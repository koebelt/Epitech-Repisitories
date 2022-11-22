/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** EntityPlayer
*/

#include "EntityPlayer.hpp"

// Components

#include "../../IndieStudio.hpp"
#include "../components/Transformable.hpp"
#include "../../scenes/Scene.hpp"
#include "../../scenes/GameScene.hpp"
#include "../items/bombs/SpawnableBomb.hpp"

istudio::EntityPlayer::EntityPlayer(graphic::AnimatedModel *model, graphic::Model *idle, VectorF pos, std::vector<int> keys, Vector size) :
    EntityLiving(model, idle, VectorF(0.04, 0.04), pos, size),
    _keys(keys)
{
}

int istudio::EntityPlayer::EntityPlayer::handle(int idx)
{
    if (_dead) return (0);
    if (idx == 4) {
        useItem<ClassicBomb>();
        return (1);
    }
    if (!canMove()) return (0);
    switch (idx) {
        case 0:
            _entity.setDirection(VectorF(-1.f, 0));
            break;
        case 1:
            _entity.setDirection(VectorF(0, -1.f));
            break;
        case 2:
            _entity.setDirection(VectorF(1.f, 0));
            break;
        case 3:
            _entity.setDirection(VectorF(0, 1.f));
            break;
    }
    setMovable(false);
    return (1);
}