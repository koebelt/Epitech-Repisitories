/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** Component4011
*/

#include "Component4011.hpp"
#include "GateComponent.hpp"
#include <cstdio>

namespace nts
{
    Component4011::Component4011()
    {
        name = "4011";
        gates[1] = std::unique_ptr<IComponent>(new NANDComponent());
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[3] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(1, *gates[1], 1);
        this->setLink(2, *gates[1], 2);
        gates[1]->setLink(3, *this, 3);
        gates[2] = std::unique_ptr<IComponent>(new NANDComponent());
        pins[4] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        pins[5] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[6] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        this->setLink(5, *gates[2], 1);
        this->setLink(6, *gates[2], 2);
        gates[2]->setLink(3, *this, 4);
        gates[3] = std::unique_ptr<IComponent>(new NANDComponent());
        pins[8] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[9] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[10] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(8, *gates[3], 1);
        this->setLink(9, *gates[3], 2);
        gates[3]->setLink(3, *this, 10);
        gates[4] = std::unique_ptr<IComponent>(new NANDComponent());
        pins[11] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        pins[12] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[13] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        this->setLink(12, *gates[4], 1);
        this->setLink(13, *gates[4], 2);
        gates[4]->setLink(3, *this, 11);
    }
}

