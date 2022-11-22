/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** Centipede
*/

#ifndef CENTIPEDE_HPP_
#define CENTIPEDE_HPP_

#include "../IGame.hpp"
#include <list>
#include "ncurses.h"
#include <sstream>
#include <unistd.h>

namespace arcade
{
    class Centipede : public arcade::IGame {
    public:
        Centipede();
        ~Centipede();

        class Entity {
            public:
                Entity();
                ~Entity();
                std::list<std::vector<int>> body;
                std::vector<int> head;
            protected:
            private:
        };

        int listen(std::shared_ptr<arcade::Event> event); // Handle Event main part of the game
        int update(float time_elapsed, std::function<void()>);
        std::vector<std::shared_ptr<Property>> getProperties() const;
        void reset(); // When reseting the game
        Matrix getMatrix() const;
        void createCentipede();
        bool hasCentipede();
        int moveCentipedes();
        int decideMovement(std::list<Entity>::iterator it);
        int moveCentipedesSecond(std::list<Entity>::iterator it, int currentRows, int currentCols, int add);
        void movePlayerRight();
        void movePlayerLeft();
        void movePlayerUp();
        void movePlayerDown();
        void shoot();
        bool hasShot();
        void moveShot();
        void eraseShot();
        void hitHead(int rows, int cols);
        void hitbody(int rows, int cols);
        void cleanMap();
        void addObstacles();
        void supprIterator(std::list<Entity>::iterator it);

        protected:
        private:
            Matrix _matrix;
            std::list<Entity> list;
            int centipedeMovement = 0;
            std::vector<std::shared_ptr<Property>> _props = std::vector<std::shared_ptr<Property>>{
                std::make_shared<PropertyBasic>("name", "Centipede"),
                std::make_shared<PropertyBasic>("size", Vector(33, 22)), // Map Info
                std::make_shared<PropertyBasic>("color", std::vector<int>{12, 243, 23}),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 5), PropertyBasic("C:color", 14), PropertyBasic("D:color", std::vector<int>{255, 125, 0})}, '>'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 5), PropertyBasic("C:color", 14), PropertyBasic("D:color", std::vector<int>{255, 125, 0})}, 'v'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 5), PropertyBasic("C:color", 14), PropertyBasic("D:color", std::vector<int>{255, 125, 0})}, '<'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 5), PropertyBasic("C:color", 14), PropertyBasic("D:color", std::vector<int>{255, 125, 0})}, '^'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 5), PropertyBasic("C:color", 14), PropertyBasic("D:color", std::vector<int>{255, 200, 0})}, '@'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 2), PropertyBasic("C:color", 4), PropertyBasic("D:color", std::vector<int>{255, 0, 0})}, '|'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 255, 0})}, 'O'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 200, 0})}, '0'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 170, 0})}, '8'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 150, 0})}, 'o'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 3), PropertyBasic("C:color", 2), PropertyBasic("D:color", std::vector<int>{0, 130, 0})}, 'c'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:color", 4), PropertyBasic("C:color", 1), PropertyBasic("D:color", std::vector<int>{20, 130, 200})}, 'A'),
                std::make_shared<PropertyList>(std::vector<PropertyBasic>{PropertyBasic("N:timeout", 25), PropertyBasic("C:timeout", 4000), PropertyBasic("D:timeout", 1)}, 'T'),
            };
            std::string _map =   "#################################\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#                               #\n"\
                                "#               A               #\n"\
                                "#################################\n";
    };
}

extern "C" std::shared_ptr<arcade::Centipede> allocatorGame() { return std::make_shared<arcade::Centipede>(); }

#endif /* !CENTIPEDE_HPP_ */
