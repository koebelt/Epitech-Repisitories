/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Item
*/

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <memory>
#include "../../utils/Vector.hpp"

namespace istudio {
    class Entity;
    class Item {
        public:
            virtual ~Item() = default;

            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Action called when an item want to spawn
            ** @param position Position where item must spawn
            **/
            virtual void spawn(Vector position) = 0;
            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Return if item is currently being used or not
            **/
            virtual bool isUsed() = 0;
            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Action called when an item change state of current usage
            ** @param bool state on or off
            **/
            virtual void setUsed(bool enabled) = 0;
    };

    class IItemWithComponent {
        public:
            virtual ~IItemWithComponent() = default;

            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Action called when registering a compotent to itementity
            ** @param entity Item entity of the ItemEntity Container
            **/
            virtual void addComponentToEntity(Entity &entity) = 0;
    };
}

#endif /* !ITEM_HPP_ */
