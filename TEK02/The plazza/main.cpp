/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** main
*/

#include <exception>
#include <iostream>
#include <sstream>

#include "./src/utils/Reference.hpp"
#include "./src/Reception.hpp"
#include "./src/utils/Logger.hpp"

template <typename T>
void takeArgument(char *arg, T &ref)
{
    std::stringstream stream;
    double d = std::atof(arg);

    stream.str(arg);
    stream >> ref;
    if (!stream || d != ref)
        throw std::invalid_argument("Bad Arguments must be numbers");
}

int main(int ac, char **av)
{
    plz::Reception reception;

    if (ac != 4)
        return (84);
    try {
        takeArgument<double>(av[1], plz::Reference::_mult);
        takeArgument<int>(av[2], plz::Reference::_nbCooks);
        takeArgument<int>(av[3], plz::Reference::_time);

        plz::Logger::new_log();
        reception.launch();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}