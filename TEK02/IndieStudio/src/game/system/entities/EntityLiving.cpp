/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntityLiving
*/

#include "EntityLiving.hpp"
#include "../../managers/ItemManager.hpp"

#include "../items/bombs/SpawnableBomb.hpp"
#include "../items/bombs/FireResidue.hpp"
#include "../components/Positionable.hpp"
#include "../components/AnimatedModelComponent.hpp"
#include "../../../IndieStudio.hpp"

istudio::EntityLiving::EntityLiving(graphic::AnimatedModel *model, graphic::Model *idle, VectorF scale, VectorF pos, Vector size)
{
    _entity.registerNewComponent<AnimatedModelComponent>(model, idle, scale.getX(), scale.getY());
    _entity.setPosition(pos);
    _canMove = true;
    _items << std::make_shared<ClassicBomb>(FireResidue(*this), *this);
    _explored.push_back(pos.floor());

    Matrix &matrix = IndieStudio::getMatrix();
    if (matrix.isValid(pos.floor() + Vector(1, 0)))
        addExplored(pos.floor() + Vector(1, 0));
    if (matrix.isValid(pos.floor() + Vector(-1, 0)))
        addExplored(pos.floor() + Vector(-1, 0));
    if (matrix.isValid(pos.floor() + Vector(0, 1)))
        addExplored(pos.floor() + Vector(0, 1));
    if (matrix.isValid(pos.floor() + Vector(0, -1)))
        addExplored(pos.floor() + Vector(0, -1));
}

istudio::VectorF istudio::EntityLiving::getPosition()
{
    return _entity.getPosition();
}

istudio::VectorF istudio::EntityLiving::getDirection()
{
    return _entity.getDirection();
}

void istudio::EntityLiving::setDirection(VectorF direction)
{
    _entity.setDirection(direction);
}

istudio::Vector istudio::EntityLiving::getSize()
{
    return _entity.getComponent<Transformable>()->get();
}

istudio::Vector istudio::EntityLiving::getScale()
{
    return _entity.getComponent<Transformable>()->getScale();
}

void istudio::EntityLiving::setFireRadius(int radius)
{
    _fireUp = radius;
    std::list<ClassicBomb *> corrs = *_items.collect<ClassicBomb>();
    for (auto it = corrs.begin(); it != corrs.end(); it++)
        (*it)->setRadius((*it)->getRadius() + radius);
}

bool istudio::EntityLiving::hasActiveItem()
{
    auto items = (~_items);
    
    for (auto it = items.begin(); it != items.end(); it++)
        if ((*it)->isUsed()) return (true);
    return (false);
}