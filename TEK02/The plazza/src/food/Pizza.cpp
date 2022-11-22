/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Pizza
*/

#include "Pizza.hpp"
#include "../utils/PlazzaError.hpp"

void plz::Pizza::pack(Stock &stock)
{
    std::vector<plz::Ingredient> igs = unpack();

    for (auto it = igs.begin(); it != igs.end(); it++)
        stock.pick(*it);
}

bool plz::Pizza::canPack(Stock &stock)
{
    std::vector<plz::Ingredient> igs = unpack();

    for (auto it = igs.begin(); it != igs.end(); it++)
        if (!stock.contains(*it))
            return (false);
    return (true);
}

int plz::Pizza::getCookTime() const
{
    switch (_type) {
        case Margarita:
            return 1;
        case Fantasia:
            return 4;
        case Americana:
            return 2;
        case Regina:
            return 2;
    }
    return 0;
}

std::vector<plz::Ingredient> plz::Pizza::unpack()
{
    switch (_type) {
        case Margarita:
            return { DOE, TOMATO, GRUYERE };
        case Fantasia:
            return { DOE, TOMATO, EGGPLANT, GOAT_CHEESE, CHIEF_LOVE };
        case Americana:
            return { DOE, TOMATO, GRUYERE, STEAK };
        case Regina:
            return { DOE, TOMATO, GRUYERE, HAM, MUSHROOMS };
    }
    return {};
}