/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** main
*/

#ifndef MAIN_HPP_
    #define MAIN_HPP_

    #include "ComponentFactory.hpp"
    #include "Components/ComplexComponent.hpp"
    #include "Components/Component.hpp"
    #include "Components/SimpleComponent.hpp"
    #include "IComponent.hpp"
    #include "iostream"
    #include "fstream"
    #include "stdio.h"
    #include "string"
    #include "vector"
    #include "regex"
    #include "algorithm"
    #include "cstdlib"

class Core {
    public:
        Core() {ticks = 0;};
        ~Core() = default;
        class Error : public std::exception {
            public:
                Error(char const *msg);
                char const *what() const throw();
            private:
                char const *_msg;
        };
        void handleInput(std::string str);
        void verif_file(char **av);
        void executeInstructions();
        void display();
        void simulate();
        std::map<std::string, std::unique_ptr<nts::IComponent>> components;
        std::map<int, std::string> file;
        std::map<int, std::map<int, std::string>> instructions;
        std::map<int, std::string> names;
        int ticks;
    private:
};

#endif /* !MAIN_HPP_ */
