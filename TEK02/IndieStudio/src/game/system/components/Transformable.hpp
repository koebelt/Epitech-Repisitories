/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Transformable
*/

#ifndef TRANSFORMABLE_HPP_
#define TRANSFORMABLE_HPP_

#include "../IComponent.hpp"
#include "../../utils/Vector.hpp"

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class Transformable ( public IComponent )
    **/
    class Transformable : public IComponent {
        public:
            Transformable(Vector size, Vector scale);
            ~Transformable() = default;

            Transformable(const Transformable &cpy) = delete;
            Transformable(Transformable &&ref) = delete;

            Vector get() { return _size; };
            Vector getScale() { return _scale; };

            void draw();
            void update();
        protected:
        private:
            Vector _size;
            Vector _scale;
    };
}

#endif /* !TRANSFORMABLE_HPP_ */
