/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** GateComponent
*/

#include "GateComponent.hpp"
#include <memory>
#include <iostream>

namespace nts
{
    ANDComponent::ANDComponent()
    {
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[3] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    Tristate ANDComponent::simulate_pin(std::size_t pin)
    {
        Tristate input1 = pins[1]->linkedComponent->simulate_pin(pins[1]->pin);
        Tristate input2 = pins[2]->linkedComponent->simulate_pin(pins[2]->pin);

        if ((input1 == UNDEFINED && input2 == TRUE) || (input2 == UNDEFINED && input1 == TRUE))
            return UNDEFINED;
        return ((Tristate)(input1 == TRUE && input2 == TRUE));
    }

    ORComponent::ORComponent() {
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[3] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    Tristate ORComponent::simulate_pin(std::size_t pin)
    {
        Tristate input1 = pins[1]->linkedComponent->simulate_pin(pins[1]->pin);
        Tristate input2 = pins[2]->linkedComponent->simulate_pin(pins[2]->pin);

        if ((input1 == UNDEFINED && input2 != TRUE) || (input2 == UNDEFINED && input1 != TRUE))
            return UNDEFINED;
        return ((Tristate)(input1 == TRUE || input2 == TRUE));
    }

    NANDComponent::NANDComponent() {
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[3] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    Tristate NANDComponent::simulate_pin(std::size_t pin)
    {
        Tristate input1 = pins[1]->linkedComponent->simulate_pin(pins[1]->pin);
        Tristate input2 = pins[2]->linkedComponent->simulate_pin(pins[2]->pin);

        if ((input1 == UNDEFINED && input2 == TRUE) || (input2 == UNDEFINED && input1 == TRUE))
            return UNDEFINED;
        return ((Tristate)(!(input1 == TRUE && input2 == TRUE)));
    }

    NORComponent::NORComponent() {
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[3] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    Tristate NORComponent::simulate_pin(std::size_t pin)
    {
        Tristate input1 = pins[1]->linkedComponent->simulate_pin(pins[1]->pin);
        Tristate input2 = pins[2]->linkedComponent->simulate_pin(pins[2]->pin);

        if ((input1 == UNDEFINED && input2 != TRUE) || (input2 == UNDEFINED && input1 != TRUE))
            return UNDEFINED;
        return ((Tristate)(!(input1 == TRUE || input2 == TRUE)));
    }

    XORComponent::XORComponent() {
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[3] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    Tristate XORComponent::simulate_pin(std::size_t pin)
    {
        Tristate input1 = pins[1]->linkedComponent->simulate_pin(pins[1]->pin);
        Tristate input2 = pins[2]->linkedComponent->simulate_pin(pins[2]->pin);

        if ((input1 == UNDEFINED) || (input2 == UNDEFINED))
            return UNDEFINED;
        return ((Tristate)((input1 == TRUE ^ input2 == TRUE)));
    }

    XNORComponent::XNORComponent() {
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[3] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    Tristate XNORComponent::simulate_pin(std::size_t pin)
    {
        Tristate input1 = pins[1]->linkedComponent->simulate_pin(pins[1]->pin);
        Tristate input2 = pins[2]->linkedComponent->simulate_pin(pins[2]->pin);

        if ((input1 == UNDEFINED) || (input2 == UNDEFINED))
            return UNDEFINED;
        return ((Tristate)(!(input1 == TRUE ^ input2 == TRUE)));
    }

    NOTComponent::NOTComponent() {
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
        pins[2] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    Tristate NOTComponent::simulate_pin(std::size_t pin)
    {
        Tristate input = pins[1]->linkedComponent->simulate_pin(pins[1]->pin);

        if (input == UNDEFINED)
            return UNDEFINED;
        return ((Tristate)(!(input)));
    }
}