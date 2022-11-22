/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** FireResidue
*/

#include "FireResidue.hpp"
#include "../../../../IndieStudio.hpp"
#include "../PowerUp.hpp"
#include "../powerups/BombUP.hpp"
#include "../powerups/FireUP.hpp"
#include "../powerups/SpeedUP.hpp"
#include "../powerups/WallPass.hpp"
#include "../../../scenes/GameScene.hpp"
#include "../../components/ModelComponent.hpp"

istudio::FireResidue::FireResidue(EntityLiving &entliving) :
    Bomb(1, 500),
    _entliving(entliving)
{
}

istudio::FireResidue::FireResidue(const FireResidue &cpy) :
    Bomb(cpy._radius, cpy._delay),
    _entliving(cpy._entliving)
{
}

istudio::FireResidue::FireResidue(FireResidue &&ref) :
    Bomb(ref._radius, ref._delay),
    _entliving(ref._entliving)
{
}

void istudio::FireResidue::spawn(Vector pos)
{
    (~IndieStudio::getScenes())->getEntities() << std::make_shared<ItemEntity<FireResidue>>(pos, 'F', *this);
}

void istudio::FireResidue::addComponentToEntity(Entity &entity)
{
    GameScene *scene = nullptr;
    TutoScene *sceneTuto = nullptr;

    entity.registerNewComponent<BombExplosionable<FireResidue>, FireResidue&>(*this);
    if ((scene = dynamic_cast<GameScene *>(&*(~IndieStudio::getScenes()))))
        entity.registerNewComponent<ModelComponent>(scene->getExpl(),  0.02);
    else if ((sceneTuto = dynamic_cast<TutoScene *>(&*(~IndieStudio::getScenes()))))
        entity.registerNewComponent<ModelComponent>(sceneTuto->getExpl(),  0.02);
}

void istudio::FireResidue::waiting_action(Entity *entity)
{
    EntityManager &entities = (~IndieStudio::getScenes())->getEntities();
    std::list<EntityLiving *> tmp = *entities.collect<EntityLiving>([=, &entity](EntityLiving *cont) -> bool {
        return entity->getPosition().floor() == cont->getEntity().getPosition().floor();
    });

    std::for_each(tmp.begin(), tmp.end(), [](EntityLiving *&e) {
        e->setDead(true);
    });
}

void istudio::FireResidue::explode(Entity *entity)
{
    Matrix &matrix = IndieStudio::getMatrix();

    if (matrix(entity->getPosition()) != BREAKABLE) return;
    if (!_entliving.hasExplored(entity->getPosition().floor()))
        _entliving.addExplored(entity->getPosition().floor());
    matrix(entity->getPosition()) = EMPTY;
    std::vector<std::function<std::unique_ptr<PowerUp>()>> powerUpVector = {
        []() {return std::make_unique<BombUP>();},
        []() {return std::make_unique<FireUP>();},
        []() {return std::make_unique<SpeedUP>();},
        []() {return std::make_unique<WallPass>();},
    };
    if (rand() % 100 < 25) {
        auto powerUp = powerUpVector[rand() % powerUpVector.size()]();
        double spawnRate = (rand() % 100) + 1;
        if (spawnRate <= powerUp->getRate())
            powerUp->spawn(entity->getPosition().floor());
    }
}