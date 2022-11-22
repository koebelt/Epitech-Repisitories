/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Positionable
*/

#include "Positionable.hpp"

#include <cmath>
#include "../entities/EntityLiving.hpp"
#include "../../../IndieStudio.hpp"
#include "../entities/ItemEntity.hpp"
#include "../items/PowerUp.hpp"
#include "../items/powerups/SpeedUP.hpp"

istudio::Positionable::Positionable(VectorF &position, VectorF &direction) :
    _position(position),
    _direction(direction),
    _oldPosition(Vector(-1, -1)),
    _currentDirection(Vector(-1, -1))
{
}

void istudio::Positionable::update()
{
    EntityLiving *living = dynamic_cast<EntityLiving *>(&entity->getContainer());
    if (!living || living->isDead() || _direction == VectorF(0, 0)) return;
    Matrix &matrix = IndieStudio::getMatrix();
    _localtimer.tock();
    auto duration = _localtimer.duration();

    if (_oldPosition == Vector(-1, -1))
        _oldPosition = _position.round();
    if (_currentDirection == Vector(-1, -1))
        _currentDirection = _direction.round();
    if (!(matrix.isValid(_oldPosition + _currentDirection, {WALL, BREAKABLE}) || (living->isGhostMode() && matrix.isValid(_oldPosition + _currentDirection, {WALL})))) {
        living->setMovable(true);
        _currentDirection = Vector(-1, -1);
        return;
    }
    if (_position.getX() < 0 || _position.getY() < 0) return;
    if ((duration % 2) == 0) {
        double d = 2.f * (100.f / static_cast<double>(TIME_TO_MOVE));
        _position += VectorF((_currentDirection.getX() * (d / (10.f / living->getSpeedMultiplier()))) * std::abs(_currentDirection.getX()), (_currentDirection.getY() * (d / (10.f / living->getSpeedMultiplier()))) * std::abs(_currentDirection.getY()));
    }
    auto checkX = [=]() {
        if (_currentDirection.getX() < 0)
            return (_position.getX() > (_oldPosition.getX() + _currentDirection.getX()));
        return (_position.getX() < (_oldPosition.getX() + _currentDirection.getX()));
    };
    auto checkY = [=]() {
        if (_currentDirection.getY() < 0)
            return (_position.getY() > (_oldPosition.getY() + _currentDirection.getY()));
        return (_position.getY() < (_oldPosition.getY() + _currentDirection.getY()));
    };
    if ((_position.getX() >= 0 && checkX()) || (_position.getY() >= 0 && checkY())) {
        living->setMovable(false);
        return;
    }
    _position = _position.roundn();
    _oldPosition = _position.floor();
    if (!living->hasExplored(_oldPosition)) living->addExplored(_oldPosition);
    _currentDirection = Vector(-1, -1);
    _direction = VectorF(0, 0);
    living->setMovable(true);
    EntityManager &manager = (~IndieStudio::getScenes())->getEntities();
    auto powerups = *manager.collect<ItemEntity<PowerUp>>([=](ItemEntity<PowerUp> *elem) -> bool {
        return (elem->getEntity().getPosition() == _position);
    });
    for (auto it = powerups.begin(); it != powerups.end(); it++) {
        PowerUp &powerup = dynamic_cast<PowerUp &>(~(*(*it)));
        powerup >> (*living);
        manager.erase(*it);
    }
}