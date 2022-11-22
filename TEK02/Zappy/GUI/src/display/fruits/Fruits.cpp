/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Fruits
*/

#include "Fruits.hpp"
#include <iostream>

namespace zappy
{
    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class draw method
    ** @param fruits (std::map<int, int> fruits): List of all fruits presents
    ** @param vector (zappy::math::Vector2): Position of the fruits on the map
    ** @param model (zappy::graphic::Model &): Model of the fruits
    **/
    void Fruits::draw(std::map<int, int> fruits, zappy::math::Vector2 vector, zappy::graphic::Model &model)
    {
        zappy::graphic::Color color(255, 255, 255);
        for (int i = 0; i < fruits.size(); i++) {
            for (int cmp = 0; cmp < fruits[i]; cmp++) {
                switch(i) {
                    case FOOD: color = zappy::graphic::Color(255, 90, 90); break;
                    case LINERNATE: color = zappy::graphic::Color(200, 200, 200); break;
                    case DERAUMERE: color = zappy::graphic::Color(9, 130, 180); break;
                    case SIBUR: color = zappy::graphic::Color(200, 50, 150); break;
                    case MENDIANE: color = zappy::graphic::Color(200, 200, 20); break;
                    case PHIRAS: color = zappy::graphic::Color(255, 170, 10); break;
                    case THYSTAME: color = zappy::graphic::Color(10, 200, 150); break;
                }
                model.draw(zappy::math::Vector3(vector.x + 0.1 + 0.13 * i, cmp * 0.07 + 0.025, vector.y + 0.1), 1, color);
            }
        }
    }
}
