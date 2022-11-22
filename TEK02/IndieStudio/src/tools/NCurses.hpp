/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** NCurses
*/

#pragma once

extern "C" {
    #include <ncurses.h>
}

#include <iostream>
#include <thread>
#include <exception>
#include <functional>
#include <fstream>
#include "../game/utils/Matrix.hpp"

namespace istudio {
    class NCurses {
        public:
            NCurses();
            ~NCurses();

            /**
            ** @author : Mathieu Suk and Tristan Courty
            **
            ** @brief Function isOpen: return a boolean value to know if the library is used or not
            **
            ** @return bool
            **/
            bool isOpen() const {
                std::this_thread::sleep_for(std::chrono::milliseconds(50));
                return _isOpen;
            };
            /**
            ** @author : Mathieu Suk and Tristan Courty
            **
            ** @brief Function pollKey: return the keycode corresponding to the key pressed
            **
            ** @return int
            **/
            int pollKey() { return getch(); };
            void render(Matrix matrix);

        protected:
        private:
            bool _isOpen = true;
            WINDOW *_win;
    };
}
