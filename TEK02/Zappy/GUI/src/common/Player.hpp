/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Player
*/

#pragma once

#include <string>
#include <utility>
#include <memory>
#include <map>
#include "../display/engine/Engine.hpp"

namespace zappy {
    enum {
        nothing,
        north,
        est,
        south,
        west,
    };
    class Player {
        public:
            Player(int id, int level, std::string team, int x, int y, int orientation, zappy::graphic::Color teamColor, int eggNbr) : _id(id), _level(level), _orientation(orientation)
            {
                _pos = std::pair<int, int>(x, y);
                _currentPos = std::pair<int, int>(x, y);
                _movement = std::pair<int, int>(0, 0);
                _isEgg = true;
                _eggNbr = eggNbr;
                _inventory[0] = 0;
                _inventory[1] = 0;
                _inventory[2] = 0;
                _inventory[3] = 0;
                _inventory[4] = 0;
                _inventory[5] = 0;
                _inventory[6] = 0;
            };
            Player(int id, int level, std::string team, int x, int y, int orientation, zappy::graphic::Color teamColor) : _id(id), _level(level), _orientation(orientation)
            {
                _pos = std::pair<int, int>(x, y);
                _currentPos = std::pair<int, int>(x, y);
                _movement = std::pair<int, int>(0, 0);
                _isEgg = false;
                _inventory[0] = 0;
                _inventory[1] = 0;
                _inventory[2] = 0;
                _inventory[3] = 0;
                _inventory[4] = 0;
                _inventory[5] = 0;
                _inventory[6] = 0;
            };

            Player(const Player &player) {
                _pos = player._pos;
                _currentPos = player._currentPos;
                _isEgg = player._isEgg;
                _eggNbr = player._eggNbr;
                _inventory[0] = 0;
                _inventory[1] = 0;
                _inventory[2] = 0;
                _inventory[3] = 0;
                _inventory[4] = 0;
                _inventory[5] = 0;
                _inventory[6] = 0;
                _id = player._id;
                _level = player._level;
                _orientation = player._orientation;
            }
            ~Player() = default;

            void draw(zappy::graphic::Model &model, zappy::graphic::Color teamColor, float height, float posX, float scale, float correctY, float correctZ);
            void drawAnimation(zappy::graphic::AnimatedModel &model, zappy::graphic::Color teamColor, float height, float posX, float scale, float correctY, float correctZ);
            bool operator==(const Player &player) const { return (player._id ==_id); };

            int _id = -1;
            int _level;
            int _orientation;
            bool _isEgg = false;
            int _eggNbr = -1;
            int _currentAnim = 0;
            int broadcasting = 0;
            std::pair<float, float> _movement;
            std::pair<float, float> _pos;
            std::pair<float, float> _currentPos;
            std::map<int, int> _inventory;
        protected:
    };
}
