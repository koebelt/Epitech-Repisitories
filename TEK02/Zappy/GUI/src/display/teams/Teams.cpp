/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** Teams
*/

#include "Teams.hpp"

namespace zappy
{
    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class Team constructor
    ** @param name (std::string): Name of the team
    ** @param color (zappy::graphic::Color): Color of the team
    **/
    Team::Team(std::string name, zappy::graphic::Color color)
    {
        _name = name;
        _color = color;
    }

    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class draw method
    ** @param modelPlayer (zappy::graphic::Model &): Model of the players
    ** @param modelEgg (zappy::graphic::Model &): Model of the Eggs
    ** @param walk (zappy::graphic::AnimatedModel &): Walk animation
    ** @param broadcast (zappy::graphic::Model &): Model of the broadcast
    ** @param mapRows (int): Number of map rows
    ** @param mapCols (int): Number of map cols
    ** @param teams (std::vector<zappy::Team>): List of all team present
    ** @param freq (int): freq of the server
    **/
    void Team::draw(zappy::graphic::Model &modelPlayer, zappy::graphic::Model &modelEgg, zappy::graphic::AnimatedModel &walk, zappy::graphic::Model &broadcast, int mapRows, int mapCols, std::vector<zappy::Team> teams, int freq)
    {
        int myTeam = 0;
        zappy::Matrix matrix(mapRows, mapCols);

        for (; teams.size() > myTeam && (_name != teams[myTeam].getName()); myTeam++);

        for (auto it = _trantorians.begin(); it != _trantorians.end(); it++) {
            bool isWalking = true;
            if (std::abs(it->_pos.first - it->_currentPos.first) < 0.05 && std::abs(it->_pos.second - it->_currentPos.second) < 0.05) {
                it->_currentPos = it->_pos;
                it->_movement.first = 0;
                it->_movement.second = 0;
                isWalking = false;
            } else if ((it->_pos.first != it->_currentPos.first || it->_pos.second != it->_currentPos.second) && it->_movement == std::pair<float, float>(0, 0)) {
                if ((it->_currentPos.first == mapCols - 1 && it->_pos.first == 0))
                    it->_pos.first = mapCols;
                else if ((it->_currentPos.first == 0 && it->_pos.first == mapCols - 1))
                    it->_pos.first = -1;
                else if ((it->_currentPos.second == mapRows - 1 && it->_pos.second == 0))
                    it->_pos.second = mapRows;
                else if ((it->_currentPos.second == 0 && it->_pos.second == mapRows - 1))
                    it->_pos.second = -1;
                it->_movement.first = float(float(it->_pos.first - it->_currentPos.first) /  ((35 * 12 / freq) < 1 ? 1 : (35 * 12 / freq)));
                it->_movement.second = float(float(it->_pos.second - it->_currentPos.second) /  ((35 * 12 / freq) < 1 ? 1 : (35 * 12 / freq)));
            } else {
                if (it->_currentPos.first >= mapCols - 0.5) {
                    it->_pos.first = 0;
                    it->_currentPos.first = -0.5;
                    it->_movement.first = float(float(it->_pos.first - it->_currentPos.first) /  ((35 * 12 / freq) < 1 ? 1 : (35 * 12 / freq)));
                } else if (it->_currentPos.first <= -0.5) {
                    it->_pos.first = mapCols - 1;
                    it->_currentPos.first = mapCols - 0.5;
                    it->_movement.first = float(float(it->_pos.first - it->_currentPos.first) /  ((35 * 12 / freq) < 1 ? 1 : (35 * 12 / freq)));
                } else if (it->_currentPos.second >= mapRows - 0.5)
                {
                    it->_pos.second = 0;
                    it->_currentPos.second = -0.5;
                    it->_movement.second = float(float(it->_pos.second - it->_currentPos.second) /  ((35 * 12 / freq) < 1 ? 1 : (35 * 12 / freq)));
                } else if (it->_currentPos.second <= -0.5)
                {
                    it->_pos.second = mapRows - 1;
                    it->_currentPos.second = mapRows - 0.5;
                    it->_movement.second = float(float(it->_pos.second - it->_currentPos.second) /  ((35 * 12 / freq) < 1 ? 1 : (35 * 12 / freq)));
                }
                it->_currentPos.first += it->_movement.first;
                it->_currentPos.second += it->_movement.second;
            }

            float value = 0;
            if (it->_pos.first < 0)
                it->_pos.first = 0;
            if (it->_pos.second < 0)
                it->_pos.second = 0;
            if (it->_pos.first > mapCols)
                it->_pos.first = mapCols;
            if (it->_pos.second > mapRows)
                it->_pos.second = mapRows;
            if (!isWalking) value = matrix(it->_pos.second, it->_pos.first);
            float res = 1.00 / float(teams.size() + 1.00) * float(myTeam + 1.00);

            if (it->_isEgg == false) {
                if (!isWalking) {
                    if (it->_currentAnim == 1) {
                        it->drawAnimation(walk, _color, 1.3, 1.00 / float(teams.size() + 1) * float((myTeam + 1)), 0, 0, 0);
                        it->broadcasting = 0;
                     } else {
                        it->draw(modelPlayer, _color, value + 1.3, 1.00 / float(teams.size() + 1) * float((myTeam + 1)), 0, 0, 0);
                        if (it->broadcasting > 0) {
                            broadcast.draw(zappy::math::Vector3(it->_currentPos.first + 1.00 / float(teams.size() + 1) * float((myTeam + 1)), (value + 1.3) * 0.07, it->_currentPos.second + 0.6), zappy::math::Vector3(0, 1, 0), 3 * it->broadcasting, zappy::math::Vector3(1, 1, 0.84), getColor());
                            it->broadcasting--;
                        }
                    }
                } else {
                    it->drawAnimation(walk, _color, 1.3, 1.00 / float(teams.size() + 1) * float((myTeam + 1)), 0, 0, 0);
                    it->broadcasting = 0;
                }
            } else
                it->draw(modelEgg, _color, value + 1.3, 1.00 / float(teams.size() + 1) * float((myTeam + 1)), 0.3, 0.21, 0.03);
            if (!isWalking) matrix(it->_pos.second, it->_pos.first) = value + 5 + 0.5 * (it->_level - 1);
        }
    }

    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class draw method
    ** @param posX (int): Position X on the map
    ** @param posY (int): Position Y on the map
    ** @param playerID (std::list<int>): List of all player ID
    **/
    void Team::addEvolution(int posX, int posY, std::list<int> playerID)
    {
        _evolutions.push_back(std::pair<zappy::math::Vector3, std::list<int>>(zappy::math::Vector3(posX, posY, 90), playerID));
    }
}