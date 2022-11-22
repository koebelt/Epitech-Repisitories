/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Bomb
*/

#include "Bomb.hpp"
#include "../../../IndieStudio.hpp"

#include <memory>

istudio::Bomb::Bomb(int radius, int delay) :
    _radius(radius),
    _delay(delay),
    _isUsed(false)
{

}

istudio::Bomb::Bomb(const Bomb &cpy) :
    _radius(cpy._radius),
    _delay(cpy._delay),
    _isUsed(cpy._isUsed)
{

}

int istudio::Bomb::getRadius()
{
    return _radius;
}

int istudio::Bomb::getDelay()
{
    return _delay;
}

void istudio::Bomb::setRadius(int radius)
{
    _radius = radius;
}

void istudio::Bomb::setUsed(bool used)
{
    _isUsed = used;
}

bool istudio::Bomb::isUsed()
{
    return _isUsed;
}