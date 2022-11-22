/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** Component4069
*/

#include "Component4069.hpp"
#include "GateComponent.hpp"
#include <cstdio>
#include <iostream>

namespace nts
{
    Component4069::Component4069()
    {
        name = "4069";
        gates[1] = std::unique_ptr<IComponent>(new NOTComponent());
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(1, *gates[1], 1);
        gates[1]->setLink(2, *this, 2);
        gates[2] = std::unique_ptr<IComponent>(new NOTComponent());
        pins[3] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[4] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(3, *gates[2], 1);
        gates[2]->setLink(2, *this, 4);
        gates[3] = std::unique_ptr<IComponent>(new NOTComponent());
        pins[5] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[6] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(5, *gates[3], 1);
        gates[3]->setLink(2, *this, 6);
        gates[4] = std::unique_ptr<IComponent>(new NOTComponent());
        pins[9] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[8] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(9, *gates[4], 1);
        gates[4]->setLink(3, *this, 8);
        gates[5] = std::unique_ptr<IComponent>(new NOTComponent());
        pins[11] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[10] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(11, *gates[5], 1);
        gates[5]->setLink(3, *this, 10);
        gates[6] = std::unique_ptr<IComponent>(new NOTComponent());
        pins[13] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[12] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
        this->setLink(13, *gates[6], 1);
        gates[6]->setLink(3, *this, 12);
    }
}

