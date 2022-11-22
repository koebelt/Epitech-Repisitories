/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Tile
*/

#include "Tile.hpp"


namespace zappy
{
    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class Tile constructor
    ** @param fruits (std::vector<int>): All fruits present on the tile
    ** @param players (std::list<std::shared_ptr<zappy::Player>>): All players present on the tile
    **/
    Tile::Tile(std::vector<int> fruits, std::list<std::shared_ptr<zappy::Player>> players)
    {
        int i = 0;

        _players = players;
        for (auto it = fruits.begin(); it != fruits.end(); it++, i++)
            _fruits[i] = fruits.at(i);
    }
}
