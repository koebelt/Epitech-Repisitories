/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Map
*/

#pragma once

#include "Tile.hpp"
#include <map>

namespace zappy {
    class Map {
        public:
            Map() = default;
            ~Map() = default;

            Tile &operator()(int x, int y) { return _map[y][x]; };
            std::map<int, Tile> &operator()(int y) { return _map[y]; };
            std::map<int, std::map<int, Tile>> &get() { return _map; };
            int getWidth() { return _map[0].size(); };
            int getHeight() { return _map.size(); };

        protected:
        private:
            std::map<int, std::map<int, Tile>> _map;
    };
}
