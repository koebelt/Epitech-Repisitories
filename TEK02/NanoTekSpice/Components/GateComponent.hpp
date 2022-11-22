/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** GateComponent
*/

#ifndef GATECOMPONENT_HPP_
#define GATECOMPONENT_HPP_

#include "Component.hpp"

namespace nts {
    class ANDComponent : public Component{
        public:
            ANDComponent();
            ~ANDComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
    };

    class ORComponent : public Component{
        public:
            ORComponent();
            ~ORComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
    };

    class NANDComponent : public Component{
        public:
            NANDComponent();
            ~NANDComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
    };

    class NORComponent : public Component{
        public:
            NORComponent();
            ~NORComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
    };

    class XORComponent : public Component{
        public:
            XORComponent();
            ~XORComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
    };

    class XNORComponent : public Component{
        public:
            XNORComponent();
            ~XNORComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
    };
    class NOTComponent : public Component{
        public:
            NOTComponent();
            ~NOTComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
    };
}

#endif /* !GATECOMPONENT_HPP_ */
