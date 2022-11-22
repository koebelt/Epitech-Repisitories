/*
** EPITECH PROJECT, 2022
** Arcade
** File description:
** IGame
*/

#ifndef IGAME_HPP_
#define IGAME_HPP_

#include <string>
#include <memory>
#include <iostream>
#include <fstream>
#include <list>
#include <vector>

#include "../common/Event.hpp"
#include "../common/Matrix.hpp"
#include "../common/Property.hpp"
#include "../common/Vector.hpp"
#include "../common/ErrorManager.hpp"

namespace arcade
{

    class IGame
    {
    public:
        enum Exit : int
        {
            WIN = 2,
            LOOSE = 1
        };

        virtual ~IGame() = default;

        virtual int listen(std::shared_ptr<arcade::Event> event) = 0;      // Handle Event main part of the game
        virtual int update(float time_elapsed, std::function<void()>) = 0; // Update the game and tell if it's finished
        virtual Matrix getMatrix() const = 0;
        virtual void reset() = 0; // When reseting the game
        virtual std::vector<std::shared_ptr<Property>> getProperties() const = 0;

    protected:
    private:
    };

};

#endif /* !IGAME_HPP_ */