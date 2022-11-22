/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Interpreter
*/

#include "Interpreter.hpp"
#include <list>

namespace zappy
{
    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class _strToWordArray method
    ** @param str (std::string): String to separate into words
    **/
    std::vector<std::string> Interpreter::_strToWordArray(std::string str)
    {
        std::string word = "";
        std::vector<std::string> vector;
        for (auto x : str) {
            if (x == ' ')
            {
                vector.push_back(word);
                word = "";
            }
            else {
                word = word + x;
            }
        }
        vector.push_back(word);
        return vector;
    }

    /**
    ** @author: Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class update method
    ** @param queue (std::queue<std::string>): Queue of commands receive by the server
    ** @param map (Map &): Map of the game
    ** @param teams (std::vector<zappy::Team> &): List of all teams
    ** @param timeUnit (int &): Frequence of the server
    ** @param iterator (std::list<zappy::Player>::iterator &): Player being watch
    **/
    void Interpreter::update(std::queue<std::string> queue, Map &map, std::vector<zappy::Team> &teams, int &timeUnit, std::list<zappy::Player>::iterator &iterator)
    {
        std::map<std::string, std::function<void (std::vector<std::string>)>> list = {
            {"bct", [&map, &teams](std::vector<std::string> cmd) {

                for (int i = 0; i < 7; ++i)
                    map(std::atoi(cmd[1].c_str()), std::atoi(cmd[2].c_str()))._fruits[i] = std::atoi(cmd[3 + i].c_str());
                }},

            {"msz", [&map, &teams](std::vector<std::string> cmd) {
                int x = std::atoi(cmd[1].c_str());
                int y = std::atoi(cmd[2].c_str());

                for (int i = 0; i < y; ++i) {
                    for (int j = 0; j < x; ++j) {
                        map(j, i) = zappy::Tile({0, 0, 0, 0, 0, 0, 0}, {});
                    }
                }
            }},
            {"tna", [&map, &teams](std::vector<std::string> cmd) {
                if (cmd[1] != "GRAPHIC")
                    teams.push_back(zappy::Team(cmd[1], zappy::graphic::Color(rand() % 255, rand() % 255, rand() % 255)));
            }},
            {"pnw", [&map, &teams](std::vector<std::string> cmd) {
                zappy::graphic::Color color;
                int i = 0;
                for (; i < teams.size(); ++i)
                    if (teams[i].getName() == cmd[6]) {
                        color = teams[i].getColor();
                        break;
                    }
                teams[i].getTrantorians().push_back(zappy::Player(std::atoi(cmd[1].c_str()), std::atoi(cmd[5].c_str()), cmd[6], std::atoi(cmd[2].c_str()), std::atoi(cmd[3].c_str()), std::atoi(cmd[4].c_str()), color));
            }},
            {"ppo", [&map, &teams](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i)
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[1].c_str())) {
                            it->_currentPos = it->_pos;
                            it->_pos = std::pair<int, int>(std::atoi(cmd[2].c_str()), std::atoi(cmd[3].c_str()));
                            if (std::atoi(cmd[4].c_str()) == zappy::north)
                                it->_orientation = zappy::south;
                            else if (std::atoi(cmd[4].c_str()) == zappy::south)
                                it->_orientation = zappy::north;
                            else
                                it->_orientation = std::atoi(cmd[4].c_str());
                            return;
                        }
                    }
            }},
            {"plv", [&map, &teams](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i)
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[1].c_str())) {
                            it->_level = std::atoi(cmd[2].c_str());
                            return;
                        }
                    }
            }},
            {"pex", [&map, &teams](std::vector<std::string> cmd) {
            }},
            {"pgt", [&map, &teams](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i)
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[1].c_str())) {
                            it->_currentAnim = 1;
                            return;
                        }
                    }
            }},
            {"pbc", [&map, &teams](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i)
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[1].c_str())) {
                            it->broadcasting = 360;
                            return;
                        }
                    }
            }},
            {"pic", [&map, &teams](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i) {
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[4].c_str())) {
                            std::list<int> ids;
                            for (int j = 4; j < cmd.size(); ++j)
                                ids.push_back(std::atoi(cmd[j].c_str()));
                            teams[i].addEvolution(std::atoi(cmd[1].c_str()), std::atoi(cmd[2].c_str()), ids);
                        }
                    }
                }
            }},
            {"pie", [&map, &teams](std::vector<std::string> cmd) {
                if (std::atoi(cmd[3].c_str()) >= 1) {
                    for (int i = 0; i < teams.size(); ++i) {
                        auto it = teams[i].getEvolutions().begin();
                        for (; it != teams[i].getEvolutions().end(); ++it) {
                            if (it->first.x == std::atoi(cmd[1].c_str()) && it->first.y == std::atoi(cmd[2].c_str())) {
                                for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                                    for (int j = 0; j < teams.size(); ++j) {
                                        for (auto it3 = teams[j].getTrantorians().begin(); it3 != teams[j].getTrantorians().end(); ++it3) {
                                            if ((*it2) == it3->_id)
                                                it3->_level++;
                                        }
                                    }
                                }
                                break;
                            }
                        }
                        teams[i].getEvolutions().remove(*it);
                    }
                } else {
                    for (int i = 0; i < teams.size(); ++i) {
                        auto it = teams[i].getEvolutions().begin();
                        for (; it != teams[i].getEvolutions().end(); ++it) {
                            if (it->first.x == std::atoi(cmd[1].c_str()) && it->first.y == std::atoi(cmd[2].c_str())) {
                                break;
                            }
                        }
                        teams[i].getEvolutions().remove(*it);
                    }

                }
            }},
            {"pfk", [&map, &teams](std::vector<std::string> cmd) {
            }},
            {"enw", [&map, &teams](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i)
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[2].c_str())) {
                            teams[i].getTrantorians().push_back(zappy::Player(999, 1, teams[i].getName(), std::atoi(cmd[3].c_str()), std::atoi(cmd[4].c_str()), zappy::north, teams[i].getColor(), std::atoi(cmd[1].c_str())));
                            return;
                        }
                    }
            }},
            {"eht", [&map, &teams, &iterator](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i)
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_eggNbr == std::atoi(cmd[1].c_str())) {
                            teams[i].getTrantorians().remove(*it);
                            iterator = teams[i].getTrantorians().begin();
                            return;
                        }
                    }
            }},
            {"pdi", [&map, &teams, &iterator](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); ++i)
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[1].c_str())) {
                            teams[i].getTrantorians().remove(*it);
                            iterator = teams[i].getTrantorians().begin();
                            return;
                        }
                    }
            }},
            {"seg", [&map, &teams](std::vector<std::string> cmd) {
            }},
            {"sgt", [&map, &teams, &timeUnit](std::vector<std::string> cmd) {
                timeUnit = std::atoi(cmd[1].c_str());
            }},
            {"sst", [&map, &teams, &timeUnit](std::vector<std::string> cmd) {
                timeUnit = std::atoi(cmd[1].c_str());
            }},
            {"pin", [&map, &teams, &timeUnit](std::vector<std::string> cmd) {
                for (int i = 0; i < teams.size(); i++) {
                    for (auto it = teams[i].getTrantorians().begin(); it != teams[i].getTrantorians().end(); ++it) {
                        if (it->_id == std::atoi(cmd[1].c_str())) {
                            it->_inventory[zappy::Fruits::FOOD] = atoi(cmd[4].c_str());
                            it->_inventory[zappy::Fruits::LINERNATE] = atoi(cmd[5].c_str());
                            it->_inventory[zappy::Fruits::DERAUMERE] = atoi(cmd[6].c_str());
                            it->_inventory[zappy::Fruits::SIBUR] = atoi(cmd[7].c_str());
                            it->_inventory[zappy::Fruits::MENDIANE] = atoi(cmd[8].c_str());
                            it->_inventory[zappy::Fruits::PHIRAS] = atoi(cmd[9].c_str());
                            it->_inventory[zappy::Fruits::THYSTAME] = atoi(cmd[10].c_str());
                            return;
                        }
                    }
                }
            }}
        };
        while (!queue.empty()) {
            std::string it = queue.front();
            std::vector<std::string> cmd = _strToWordArray(it);
            if (cmd.empty()) continue;
            if (list.find(cmd[0]) == list.end());
            else {
                list[cmd[0]](cmd);
            }
            queue.pop();
        }
    }
}
