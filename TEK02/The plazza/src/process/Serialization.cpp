/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-theplazza-paul.gazeau-rousseau
** File description:
** Serialization
*/

#include "Serialization.hpp"

namespace plz {

    uint8_t Serialization::pack(Pizza pizza)
    {
        return ((((uint8_t)(pizza.getPizzaType() & 0xff)) << 4) | (0x00ff & ((uint8_t)((pizza.getSize() - 1) & 0xff))));
    }

    Pizza Serialization::unpack(uint8_t n)
    {
        return (Pizza((PizzaType)(n >> 4), (PizzaSize)((n & 0x0f) + 1)));
    }

}
