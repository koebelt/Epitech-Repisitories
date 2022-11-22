/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntityAI
*/

#include "EntityAI.hpp"

istudio::EntityAI::EntityAI(graphic::AnimatedModel *model, graphic::Model *idle, VectorF pos, Vector size) :
    EntityLiving(model, idle, VectorF(0.04, 0.04), pos, size)
{
    _entity.registerNewComponent<IAComponent>();
}