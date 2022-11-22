/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <list>
#include "../IGame.hpp"
#include <sstream>

namespace arcade {
    class Nibbler : public arcade::IGame{
        public:
            Nibbler();
            ~Nibbler();

            int listen(std::shared_ptr<arcade::Event> event); // Handle Event main part of the game
            int update(float time_elapsed, std::function<void()>);
            Matrix getMatrix() const;
            std::vector<std::shared_ptr<Property>> getProperties() const;
            void reset(); // When reseting the game
            int snakeUp(int rows, int cols);
            int snakeDown(int rows, int cols);
            int snakeLeft(int rows, int cols);
            int snakeRight(int rows, int cols);
            void updateBody(int rows, int cols, int nbr);
            void changeHead(std::string str);
            void newFruit();

        protected:
        private:
            Matrix _matrix;
            std::list<std::vector<int>> list;
            std::vector<std::shared_ptr<Property>> _props = std::vector<std::shared_ptr<Property>>{
                std::make_shared<PropertyBasic>("name", "Nibbler"),
                std::make_shared<PropertyBasic>("size", Vector(22, 19)), // Map Info
                std::make_shared<PropertyBasic>("color", std::vector<int>{12, 243, 23}),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 255, 0})}, '>'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 255, 0})}, 'v'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 255, 0})}, '<'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 255, 0})}, '^'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 255, 0})}, '@'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 2), PropertyBasic("C:color", 4), PropertyBasic("D:color", std::vector<int>{255, 0, 0})}, 'o'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:timeout", 350)}, 'T'),
            };
            std::string _map =  "######################\n"\
                                "#                    #\n"\
                                "#      #      #      #\n"\
                                "#      #      #      #\n"\
                                "#      #      #      #\n"\
                                "#                    #\n"\
                                "#    ###      ###    #\n"\
                                "#    #          #    #\n"\
                                "#    #          #    #\n"\
                                "#        @@@>        #\n"\
                                "#    #          #    #\n"\
                                "#    #          #    #\n"\
                                "#    ###      ###    #\n"\
                                "#                    #\n"\
                                "#      #      #      #\n"\
                                "#      #      #      #\n"\
                                "#      #      #      #\n"\
                                "#                    #\n"\
                                "######################\n";

    };
}

extern "C" std::shared_ptr<arcade::Nibbler> allocatorGame() { return std::make_shared<arcade::Nibbler>(); }

#endif /* !NIBBLER_HPP_ */
