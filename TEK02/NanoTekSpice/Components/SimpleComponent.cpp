/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** SimpleComponent
*/

#include "SimpleComponent.hpp"

namespace nts {
    InputComponent::InputComponent()
    {
        name = "input";
        this->saved = UNDEFINED;
        pins[1] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, UNDEFINED, -1, nullptr});
    }

    nts::Tristate InputComponent::simulate_pin(std::size_t pin)
    {
        this->pins[1]->state = this->saved;
        return (this->pins[1]->state);
    }

    void InputComponent::setState(std::size_t pin, nts::Tristate state)
    {
        if (!this->pins[pin])
            throw Error("Unknown pin, cannot setState.");
        this->saved = state;
    }

    nts::Tristate InputComponent::getState(std::size_t pin)
    {
        if (!this->pins[pin])
            throw Error("Unknown pin, cannot getState.");
        return (this->pins[pin]->state);
    }

    StaticStateComponent::StaticStateComponent(Tristate state)
    {
        name = "input";
        pins[1] = std::unique_ptr<pin_t>(new pin_t{OUTPUT, state, -1, nullptr});
    }

    nts::Tristate StaticStateComponent::simulate_pin(std::size_t pin)
    {
        return (this->pins[1]->state);
    }

    OutputComponent::OutputComponent()
    {
        name = "output";
        pins[1] = std::unique_ptr<pin_t>(new pin_t{INPUT, UNDEFINED, -1, nullptr});
    }
}