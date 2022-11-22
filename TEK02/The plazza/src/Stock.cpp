/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Stock
*/

#include "Stock.hpp"
#include "./utils/Reference.hpp"
#include "./Kitchen.hpp"

#include <thread>
#include <chrono>

plz::Stock::Stock(pid_t pid) : _pid(pid)
{
    for (int i = DOE; i <= CHIEF_LOVE; i++)
        _ingredients[i] = MAX_STOCK;
}

void plz::Stock::refill()
{
    bool refilled = false;

    for (auto it = _ingredients.begin(); it != _ingredients.end(); it++) {
        if (it->second < MAX_STOCK) {
            it->second += 1;
            refilled = true;
        }
    }
    if (refilled) Logger::stock_refilled(_pid);
}

plz::Stock::Stock(plz::Stock &&obj) : _pid(obj._pid) {
    Logger::stock_ready(_pid);
    for (int i = DOE; i <= CHIEF_LOVE; i++)
        _ingredients[i] = MAX_STOCK;
};

bool plz::Stock::contains(Ingredient &ingredient)
{
    if (ingredient < 1)
        return (false);
    return (_ingredients.find(ingredient) != _ingredients.end() && (_ingredients[ingredient] > 0));
}

bool plz::Stock::pick(Ingredient &ingredient)
{
    if (contains(ingredient)) {
        _ingredients[ingredient] -= 1;
        return (true);
    }
    return (false);
}