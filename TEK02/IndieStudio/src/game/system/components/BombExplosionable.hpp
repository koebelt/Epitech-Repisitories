/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser [WSL : Ubuntu]
** File description:
** BombExplosionable
*/

#ifndef BOMBEXPLOSIONABLE_HPP_
#define BOMBEXPLOSIONABLE_HPP_

#include "../IComponent.hpp"
#include "../../utils/Timer.hpp"
#include "../../utils/Vector.hpp"

#include <functional>

namespace istudio {
    class Entity;
    class EntityLiving;
    class Bomb;
    template <typename T>
    class BombExplosionable : public IComponent {
        public:
            BombExplosionable() = delete;
            BombExplosionable(T &bomb) : _container(bomb), _localtimer(Timer(true)) {};
            ~BombExplosionable() = default;

            BombExplosionable(const BombExplosionable &cpy) = delete;
            BombExplosionable &operator=(const BombExplosionable &cpy) = delete;
            BombExplosionable(BombExplosionable &&ref) = delete;

            void update() {
                _localtimer.tock();
                auto duration = _localtimer.duration();
                if (!entity->isActive()) return;
                if (duration < _container.getDelay()) {
                    _container.waiting_action(entity);
                    return;
                }
                _container.explode(entity);
                entity->destroy();
                _localtimer.tick();
            }
        protected:
        private:
            Timer _localtimer;
            T &_container;
    };
}

#endif /* !BOMBEXPLOSIONABLE_HPP_ */
