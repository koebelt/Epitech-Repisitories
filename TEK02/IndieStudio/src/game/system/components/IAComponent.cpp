/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IAComponent
*/

#include "IAComponent.hpp"
#include "../IEntityContainer.hpp"
#include "../../managers/EntityManager.hpp"
#include "../entities/EntityLiving.hpp"
#include "../../../IndieStudio.hpp"
#include "../../utils/Timer.hpp"

#include "../items/bombs/SpawnableBomb.hpp"
#include "../items/bombs/FireResidue.hpp"
#include "../items/PowerUp.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <ranges>

/**
 * * @author Thibaut Ruscher & Tristan Courty
 *
 * @brief Function that find the nearest entity
 * @param Matrix matrix - Reference on the map
 * @param EntityManager manager - List of all entities in current scene
 *
 * @return pointer of the entity that have been found
*/
std::unique_ptr<istudio::Vector> istudio::IAComponent::findTarget(EntityManager &manager)
{
    std::vector<int> distRes{};
    auto matches = manager.collect<EntityLiving>([=](EntityLiving *living) {
        return !living->isDead() && (&living->getEntity() != entity);
    }).hasVector();

    for (auto it = matches.begin(); it != matches.end(); it++)
        distRes.push_back((*it)->getPosition().diff(entity->getPosition()));
    if (distRes.size() == 0)
        return (nullptr);
    int idx = std::distance(std::begin(distRes), std::min_element(std::begin(distRes), std::end(distRes)));
    return (std::make_unique<Vector>(matches[idx]->getPosition().floor()));
}

/**
 * * @author Thibaut Ruscher & Paul Gazeau-Rousseau
 *
 * @brief check if a place is a safe place (not targeted by a bomb)
 * @param pos pos - pos to check
 * @param manager manager - entityManager
 *
*/
bool istudio::IAComponent::isOnSafePlace(Vector pos, EntityManager &manager)
{

    if (!IndieStudio::getMatrix().isValid(pos, {WALL, BREAKABLE}))
        return (false);
    return ((*manager.collect<ItemEntity<ClassicBomb>>([=, &pos](ItemEntity<ClassicBomb> *entity) {
        ClassicBomb &bomb = dynamic_cast<ClassicBomb &>(~*entity);
        if (entity->getEntity().getPosition().floor() == pos) return (true);
        for (int i = -bomb.getRadius(); i <= bomb.getRadius(); i++)
            if ((entity->getEntity().getPosition().floor() + Vector(i, 0)) == pos)
                return (true);
        for (int i = -bomb.getRadius(); i <= bomb.getRadius(); i++)
            if ((entity->getEntity().getPosition().floor() + Vector(0, i)) == pos)
                return (true);
        return (false);
    })).size() == 0);
}

/**
 * * @author Paul Gazeau-Rousseau
 *
 * @brief Function that check ia to not go into fire residue and into banned fixed element
 * @param Vector pos - Position to check into
 * @param EntityManager manager - List of entities to check into
 * @param std::vector<int> banned - List of Banned fixed element
 *
 * @return if the case is secure or not
*/
bool istudio::IAComponent::isSecure(Vector pos, EntityManager &manager, std::vector<int> banned)
{
    if (!IndieStudio::getMatrix().isValid(pos, banned))
        return (false);
    return ((*manager.collect<ItemEntity<FireResidue>>([=, &pos](ItemEntity<FireResidue> *entity) {
        if (entity->getEntity().getPosition().floor() == pos) return (true);
        return (false);
    })).size() == 0);
}
/**
 * * @author Paul Gazeau-Rousseau
 *
 * @brief Function that integrate pathfinding for ia
 * @param Vector pos - Position to check into
 * @param std::list<Vector> list - List that will be used and that stocjk the path
 *
 * @return if the AAlgorithm find a path
*/
int istudio::IAComponent::AAlgorithm(Vector pos, Vector &choosen, bool safePlace)
{
    std::deque<Slot> slots{};
    EntityLiving *me = dynamic_cast<EntityLiving *>(&entity->getContainer());
    EntityManager &manager = (~IndieStudio::getScenes())->getEntities();
    Vector entityPos = entity->getPosition().floor();

    auto compare = [](Slot &a, Slot &b) -> bool {
        return (a.Fcost < b.Fcost);
    };

    if (pos.diff(entity->getPosition().floor()) < 1)
        return (safePlace);
    for (int row = -1; row <= 1; row++) {
        for (int col = -1; col <= 1; col++) {
            if ((row != 0 && col != 0) || (row == 0 && col == 0)) // Skip diagonale and middle
                continue;
            Vector newPosition = (entityPos + Vector(col, row));
            if (!isSecure(newPosition, manager, ((safePlace || me->isGhostMode()) ? std::vector<int>{WALL} : std::vector<int>{WALL, BREAKABLE})))
                continue; // Si c'est une position pas safe
            double startDiff = (IndieStudio::getMatrix()(newPosition) == BREAKABLE ? 5.f : 0.f);
            if ((*manager.collect<ItemEntity<PowerUp>>([&newPosition](ItemEntity<PowerUp> *power) {
                return power->getEntity().getPosition().floor() == newPosition;
            })).size() > 0)
                startDiff = 0;
            double endDiff = (pos.diff(newPosition) * 10);
            slots.push_back({
                .Gcost = startDiff,
                .Hcost = endDiff,
                .Fcost = (startDiff + endDiff),
                .position = newPosition,
                .direction = Vector(col, row)
            });
        }
    }
    if (slots.size() == 0)
        return (0);
    auto it = std::min_element(slots.begin(), slots.end(), compare);
    if (it == slots.end())
        return (0);
    slots.erase(std::remove_if(slots.begin(), slots.end(), [&it](const Slot& slot) {
        return it->Hcost != slot.Hcost;
    }), slots.end());
    choosen = slots[rand() % slots.size()].direction;
    return (0);
}

/**
 * * @author Thibaut Ruscher & Paul Gazeau-Rousseau
 *
 * @brief find the nearest place who is a safe place (not threatened by a bomb)
 * @param pos pos - pos to check
 * @param manager manager - entityManager
 * @param last_path last_path - last path that we checked
 *
*/
std::unique_ptr<istudio::Vector> istudio::IAComponent::findNearestSafePlace(Vector pos, EntityManager &manager, int last_path)
{
    std::vector<int> distRes{};
    std::vector<Vector> safePlaces{};
    EntityLiving *me = dynamic_cast<EntityLiving *>(&entity->getContainer());

    for (auto it = me->getExplored().begin(); it != me->getExplored().end(); it++) 
        if (isOnSafePlace(*it, manager)) {
            distRes.push_back((*it).diff(pos));
            safePlaces.push_back(*it);
        }
    if (safePlaces.size() == 0) return (nullptr);
    int idx = std::distance(std::begin(distRes), std::min_element(std::begin(distRes), std::end(distRes)));
    return (std::make_unique<Vector>(safePlaces[idx]));
}

/**
 * * @author Thibaut Ruscher & Tristan Courty & Mathieu Suk & Paul Gazeau-Rousseau
 *
 * @brief update function of the IAComponent
 * @param Timer timer - The timer of current scene
 *
*/
void istudio::IAComponent::update()
{
    _localtimer.tock();
    auto duration = _localtimer.duration();
    if (duration < 330 || !entity->isActive())
        return;
    EntityLiving *me = dynamic_cast<EntityLiving *>(&entity->getContainer());
    if (!me->canMove() || me->isDead()) return;
    EntityManager &manager = (~IndieStudio::getScenes())->getEntities();
    Matrix &matrix = IndieStudio::getMatrix();
    bool safePlace = isOnSafePlace(entity->getPosition().floor(), manager);

    _target = !safePlace ? findNearestSafePlace(entity->getPosition().floor(), manager) : findTarget(manager);
    if (!_target) return;
    Vector choosen{0, 0};
    if (AAlgorithm(*_target, choosen, safePlace))
        me->useItem<ClassicBomb>();
    else if (matrix(entity->getPosition().floor() + choosen) == BREAKABLE) {
        me->useItem<ClassicBomb>();
    } else if (!isOnSafePlace(entity->getPosition().floor(), manager) || (isOnSafePlace(entity->getPosition().floor(), manager) && isOnSafePlace(entity->getPosition().floor() + choosen, manager)))
        entity->setDirection(VectorF(choosen.getX(), choosen.getY()));
    _localtimer.tick();
}