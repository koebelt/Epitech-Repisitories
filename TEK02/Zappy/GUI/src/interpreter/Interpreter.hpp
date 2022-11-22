/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Interpreter
*/

#pragma once
    #include "../common/Map.hpp"
    #include "../display/teams/Teams.hpp"
    #include "../common/ErrorManager.hpp"
    #include "../listener/Listener.hpp"
    #include <string>
    #include <list>
    #include <map>
    #include <functional>

namespace zappy {

    class Interpreter {
        public:
            static void update(std::queue<std::string> queue, Map &map, std::vector<zappy::Team> &Teams, int &timeUnit, std::list<zappy::Player>::iterator &iterator);

        protected:
        private:
            static std::vector<std::string> _strToWordArray(std::string str);
    };
}
