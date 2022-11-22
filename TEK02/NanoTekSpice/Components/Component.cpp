/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Component
*/

#include "Component.hpp"
#include "iostream"

namespace nts
{
    void Component::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
    {
        if (this->name == "output") {
            if (this->pins[pin]->linkedComponent != nullptr)
                throw Error("Two links one same pin, Unimplemented");
            this->pins[pin]->linkedComponent = &other;
            this->pins[pin]->pin = otherPin;
        } else {
            if (other.getPin(otherPin).linkedComponent != nullptr)
                throw Error("Two links one same pin, Unimplemented");
            other.getPin(otherPin).linkedComponent = this;
            other.getPin(otherPin).pin = pin;
        }
    }

    void Component::dump() const
    {
    }

    pin_t &Component::getPin(std::size_t pin)
    {
        if (!this->pins[pin])
            throw Error("Unknown pin, unable to get");
        return (*this->pins[pin]);
    }

    void Component::setState(std::size_t pin, nts::Tristate state)
    {
        if (!this->pins[pin])
            throw Error("Unknown pin, cannot setState.");
        this->pins[pin]->state = state;
    }

    nts::Tristate Component::getState(std::size_t pin)
    {
        if (!this->pins[pin])
            throw Error("Unknown pin, cannot getState.");
        return (this->pins[pin]->state);
    }

    std::string Component::getType()
    {
        return this->name;
    }

    void Component::simulate(std::size_t tick)
    {
        // if (!this->pins[pin])
        //     throw Error("Unknown pin, cannot simulate.");
        // return(this->pins[pin]->linkedComponent->compute(this->pins[pin]->pin));
    }

    nts::Tristate Component::simulate_pin(std::size_t pin)
    {
        if (!this->pins[pin])
            throw Error("Unknown pin, cannot simulate.");
        this->pins[pin]->state = this->pins[pin]->linkedComponent->simulate_pin(this->pins[pin]->pin);
        return (this->pins[pin]->state);
    }

    Tristate Component::compute(std::size_t pin)
    {
        if (!this->pins[pin])
            throw Error("Unknown pin, cannot compute.");
        return this->getState(pin);
    }

    Component::Error::Error(char const *msg)
    {
        this->_msg = msg;
    }

    const char *Component::Error::what() const throw() {
        return _msg;
    }
}