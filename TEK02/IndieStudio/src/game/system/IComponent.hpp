/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <iostream>

namespace istudio {
    class Entity;
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class IComponent: Basic interface for each component to implement
    **/
    class Timer;
    class IComponent {
	    public:
		    virtual ~IComponent() = default;

		    virtual void update() = 0;

			Entity *entity = nullptr;
	    protected:
    };

    class IComponentDrawable : public IComponent {
        public:
		    virtual void draw() = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
