/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Fruits
*/

#pragma once

#include "../engine/Engine.hpp"
#include <map>

namespace zappy {
    class Fruits {
        public:
            ~Fruits() = default;

            enum fruitType : int {
                FOOD = 0,
                LINERNATE,
                DERAUMERE,
                SIBUR,
                MENDIANE,
                PHIRAS,
                THYSTAME
            };

            static void draw(std::map<int, int> fruits, zappy::math::Vector2 vector, zappy::graphic::Model &model);

        protected:
        private:
    };
}
