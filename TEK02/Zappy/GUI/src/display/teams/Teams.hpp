/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** Teams
*/

#ifndef TEAMS_HPP_
#define TEAMS_HPP_

#include "../engine/Engine.hpp"
#include <map>
#include <list>
#include "../../common/Player.hpp"
#include "../../common/Matrix.hpp"
#include <iostream>

namespace zappy {
    class Team {
        public:
            Team() = default;
            Team(std::string name, zappy::graphic::Color color);
            ~Team() = default;

            void draw(zappy::graphic::Model &modelPlayer, zappy::graphic::Model &modelEgg, zappy::graphic::AnimatedModel &walk, zappy::graphic::Model &broadcast, int mapRows, int mapCols, std::vector<zappy::Team> teams, int freq);
            void addEvolution(int posX, int posY, std::list<int> playerID);

            std::string getName() const { return _name; };
            std::list<zappy::Player> &getTrantorians() { return _trantorians; };
            zappy::graphic::Color getColor() const { return _color; };
            std::list<std::pair<zappy::math::Vector3, std::list<int>>> &getEvolutions() { return _evolutions; };

        protected:
        private:
            std::string _name = "";
            zappy::graphic::Color _color = zappy::graphic::Color(255, 255, 255);
            std::list<zappy::Player> _trantorians;
            std::list<std::pair<zappy::math::Vector3, std::list<int>>> _evolutions;
    };
}

#endif /* !TEAMS_HPP_ */
