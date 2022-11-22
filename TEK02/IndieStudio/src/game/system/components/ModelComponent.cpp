/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ModelComponent
*/

#include "ModelComponent.hpp"

#include "../ECS.hpp"
#include "../../../engine/graphic/3d/model/Model.hpp"

istudio::ModelComponent::ModelComponent(istudio::graphic::Model *model, float scale) : _model(model), _scale(scale), _direction(VectorF(0, 0))
{
}

void istudio::ModelComponent::draw()
{
    auto getDirectionAngle = [=]() -> double {
        if (_direction.getX() != 0)
            return (90.f * static_cast<double>(_direction.getX()));
        return (_direction.getY() == 1 ? 0.f : 180.f);
    };
    _model->draw(istudio::math::Vector3(entity->getPosition().getX(), 0.36, entity->getPosition().getY()), istudio::math::Vector3(0.f, 1.f, 0.f), getDirectionAngle(), istudio::math::Vector3(_scale, _scale, _scale), istudio::graphic::Color(255, 255, 255));
}

void istudio::ModelComponent::update()
{
    if (entity->getDirection() != VectorF(0, 0))
        _direction = VectorF(entity->getDirection().getX(), entity->getDirection().getY());
}