/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** PowerUp
*/

#ifndef POWERUP_HPP_
#define POWERUP_HPP_

#include "./Item.hpp"
#include "../entities/EntityLiving.hpp"

namespace istudio {

    class IPowerUp
    {
        public:
            virtual ~IPowerUp() = default;

            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Action called when powerup is collected
            ** @param entity Entity that has collect the powerup
            **/
            virtual void operator>>(EntityLiving &entity) = 0;
    };

    class PowerUp : public Item, public IItemWithComponent, public IPowerUp { // Abstract class
        public:
            PowerUp(double spawnRate);
            ~PowerUp() = default;

            double getRate() { return _spawnRate; };

            void setUsed(bool used) { _used = used; };
            bool isUsed() { return _used; };
        protected:
        private:
            bool _used;
            double _spawnRate;
    };
}

#endif /* !POWERUP_HPP_ */
