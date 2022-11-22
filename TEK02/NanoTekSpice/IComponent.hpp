/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <numeric>
#include <memory>

namespace nts {
    typedef struct pin pin_t;
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };
    enum pinType {
        INPUT,
        OUTPUT
    };
    class IComponent {
        public:
            IComponent() = default;
            ~IComponent() = default;
            virtual void simulate(std::size_t tick) = 0;
            virtual nts::Tristate simulate_pin(std::size_t pin) = 0;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other,
                std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual pin_t &getPin(std::size_t pin) = 0;
            virtual void setState(std::size_t pin, nts::Tristate state) = 0;
            virtual nts::Tristate getState(std::size_t pin) = 0;
            virtual std::string getType() = 0;
    };

    struct pin {
        pinType type;
        Tristate state;
        int pin;
        nts::IComponent *linkedComponent;
    };
} // namespace nts

#endif /* !ICOMPONENT_HPP_ */
