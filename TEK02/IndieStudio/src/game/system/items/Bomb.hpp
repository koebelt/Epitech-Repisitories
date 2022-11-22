/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Bomb
*/

#ifndef BOMB_HPP_
#define BOMB_HPP_

#include "../ECS.hpp"
#include "./Item.hpp"
#include "../entities/ItemEntity.hpp"
#include "../components/BombExplosionable.hpp"

#include <functional>

namespace istudio {
    class Bomb : public Item, public IItemWithComponent { // Abstract class
        public:
            Bomb() = delete;
            Bomb(int radius, int delay);
            ~Bomb() = default;

            Bomb(const Bomb &cpy);
            Bomb(Bomb &&ref) = delete;
            Bomb &operator=(const Bomb &cpy) = delete;

            int getRadius();
            int getDelay();
            void setRadius(int radius);
            void setUsed(bool used);
            bool isUsed();
            
            virtual void addComponentToEntity(Entity &entity) = 0;
            virtual void explode(Entity *entity) = 0;
            virtual void waiting_action(Entity *entity) = 0;
        protected:
            bool _isUsed = false;
            int _radius = 0;
            int _delay = 0; // IN Milliseconds
    };
}

#endif /* !BOMB_HPP_ */
