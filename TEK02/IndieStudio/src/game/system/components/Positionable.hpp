/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Positionable
*/

#ifndef POSITIONABLE_HPP_
#define POSITIONABLE_HPP_

#include "../../utils/Vector.hpp"
#include "../../utils/Timer.hpp"
#include "../IComponent.hpp"

#define TIME_TO_MOVE 200

namespace istudio {
    class Positionable : public IComponent {
        public:
            Positionable(VectorF &position, VectorF &direction);
            ~Positionable() = default;

            Positionable(const Positionable &cpy) = delete;
            Positionable(Positionable &&ref) = delete;
            VectorF &getPosition() { return _position; };
            VectorF &getDirection() { return _direction; };

            void update();
        protected:
        private:
            VectorF &_position;
            Vector _oldPosition;
            Vector _currentDirection;
            VectorF &_direction;
            Timer _localtimer;
    };
}

#endif /* !POSITIONABLE_HPP_ */
