/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** AnimatedModelComponent
*/

#include "AnimatedModelComponent.hpp"

#include "../ECS.hpp"
#include "../../../engine/graphic/3d/model/Model.hpp"
#include "../../../engine/graphic/3d/model/animated_model/AnimatedModel.hpp"

#include "../entities/EntityLiving.hpp"

istudio::AnimatedModelComponent::AnimatedModelComponent(istudio::graphic::AnimatedModel *animation, istudio::graphic::Model *idle, float scale, float scaleAnim) :
    _animation(animation),
    _idle(idle),
    _scale(scale),
    _direction(VectorF(0, 0)),
    _scaleAnim(scaleAnim)
{
}

void istudio::AnimatedModelComponent::draw()
{
    auto getDirectionAngle = [=]() -> double {
        if (_direction.getX() != 0)
            return (90.f * static_cast<double>(_direction.getX()));
        return (_direction.getY() == 1 ? 0.f : 180.f);
    };

    EntityLiving *living = nullptr;
    if ((living = dynamic_cast<EntityLiving *>(&entity->getContainer())) && !living->canMove())
        _animation->draw(istudio::math::Vector3(entity->getPosition().getX(), 0.36, entity->getPosition().getY()), istudio::math::Vector3(0.f, 1.f, 0.f), getDirectionAngle(), istudio::math::Vector3(_scaleAnim, _scaleAnim, _scaleAnim), istudio::graphic::Color(255, 255, 255));
    else
        _idle->draw(istudio::math::Vector3(entity->getPosition().getX(), 0.36, entity->getPosition().getY()), istudio::math::Vector3(0.f, 1.f, 0.f), getDirectionAngle(), istudio::math::Vector3(_scale, _scale, _scale), istudio::graphic::Color(255, 255, 255));
}

void istudio::AnimatedModelComponent::update()
{
    if (entity->getDirection() != VectorF(0, 0))
        _direction = VectorF(entity->getDirection().getX(), entity->getDirection().getY());
}
