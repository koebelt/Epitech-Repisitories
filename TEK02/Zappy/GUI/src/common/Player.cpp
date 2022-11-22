/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** Player
*/

#include "Player.hpp"

namespace zappy
{
    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class draw method
    ** @param model (zappy::graphic::Model &): Model to display
    ** @param teamColor (zappy::graphic::Color): Color of the team
    **/
    void Player::draw(zappy::graphic::Model &model, zappy::graphic::Color teamColor, float height, float posX, float scale, float correctY, float correctZ)
    {
        model.draw(zappy::math::Vector3(_currentPos.first + posX, height * 0.07 - correctZ, _currentPos.second + 0.6 + correctY), zappy::math::Vector3(0, 1, 0), (_orientation + 1) * -90, zappy::math::Vector3(0.007 + _level * 0.0007 + scale, 0.007 + _level * 0.0007 + scale, 0.007 + _level * 0.0007 + scale), teamColor);
    }

    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class drawAnimation method
    ** @param model (zappy::graphic::Model &): Model to display
    ** @param teamColor (zappy::graphic::Color): Color of the team
    **/
    void Player::drawAnimation(zappy::graphic::AnimatedModel &model, zappy::graphic::Color teamColor, float height, float posX, float scale, float correctY, float correctZ)
    {
        if (model.draw(zappy::math::Vector3(_currentPos.first + posX, height * 0.07 - correctZ, _currentPos.second + 0.6 + correctY), zappy::math::Vector3(0, 1, 0), (_orientation + 1) * -90, zappy::math::Vector3(0.007 + _level * 0.0007 + scale, 0.007 + _level * 0.0007 + scale, 0.007 + _level * 0.0007 + scale), teamColor))
            _currentAnim = 0;
    }
}
