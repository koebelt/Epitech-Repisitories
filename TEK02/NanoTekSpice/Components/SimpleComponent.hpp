/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** SimpleComponent
*/

#ifndef SIMPLECOMPONENT_HPP_
#define SIMPLECOMPONENT_HPP_

#include "Component.hpp"

namespace nts {

    class InputComponent : public Component {
        public:
            InputComponent();
            ~InputComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;
            void setState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getState(std::size_t pin) override;

        protected:
        private:
            Tristate saved;
    };

    class StaticStateComponent : public Component {
        public:
            StaticStateComponent(Tristate state);
            ~StaticStateComponent() = default;
            nts::Tristate simulate_pin(std::size_t pin) override;

        protected:
        private:
    };
    class OutputComponent : public Component {
        public:
            OutputComponent();
            ~OutputComponent() = default;

        protected:
        private:
    };
}

#endif /* !SIMPLECOMPONENT_HPP_ */
