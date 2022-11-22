/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** main
*/

#include "./IndieStudio.hpp"
#include "./engine/Engine.hpp"

#include <iostream>
#include <exception>

int main(void) // TODO: Voir plus tard pour des possibles arguments ?
{
    try {
        srand(time(NULL));
        istudio::IndieStudio::init();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (84);
    }
}