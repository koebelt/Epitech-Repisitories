/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Cook
*/

#include "Cook.hpp"
#include "Kitchen.hpp"
#include <chrono>
#include <thread>
#include "./utils/Reference.hpp"
#include "./process/Serialization.hpp"
#include "./utils/Logger.hpp"

plz::Cook::Cook() : _holdingPizza(nullptr), _isValid(false)
{
}

plz::Cook::~Cook()
{
    if (_isValid)
        Logger::destroy_cook();
}

plz::Cook::Cook(plz::Cook &&obj) : _holdingPizza(obj._holdingPizza), _isValid(true) {
    Logger::create_cook();
};
