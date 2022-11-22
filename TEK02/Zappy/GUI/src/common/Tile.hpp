/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Tile
*/

#pragma once

#include <vector>
#include <map>
#include <list>
#include "Player.hpp"
#include "../display/fruits/Fruits.hpp"


namespace zappy {
    class Tile {
        public:
            Tile() = default;
            Tile(std::vector<int> fruits, std::list<std::shared_ptr<zappy::Player>> players);
            ~Tile() = default;

            std::map<int, int> _fruits;
            std::list<std::shared_ptr<zappy::Player>> _players;
        protected:
        private:
    };
}
