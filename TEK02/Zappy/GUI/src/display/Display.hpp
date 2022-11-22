/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Display
*/

#pragma once

#include "engine/Engine.hpp"
#include "../common/Map.hpp"
#include <memory>
#include "teams/Teams.hpp"
#include <chrono>
#include "../listener/Listener.hpp"
#include "../interpreter/Interpreter.hpp"
#include <queue>

namespace zappy {
    class Display {
        public:
            Display();
            ~Display() = default;

            void loop(zappy::Listener &listener);

        protected:
        private:
            zappy::Window _window;
            std::list<std::shared_ptr<zappy::Player>> _players;
            int _timeUnit = -1;
            bool _isInventory = false;
            std::list<zappy::Player>::iterator playerIt;
            std::vector<zappy::Team>::iterator teamIt;

    };

}
