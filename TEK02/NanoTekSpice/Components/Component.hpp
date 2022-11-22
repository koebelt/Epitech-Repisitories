/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <numeric>
#include <map>
#include <string>

#include "../IComponent.hpp"

namespace nts {
    class Component : public IComponent {
        public:
            Component() = default;
            ~Component() = default;
            void simulate(std::size_t tick) override;
            virtual nts::Tristate simulate_pin(std::size_t pin) override;
            nts::Tristate compute(std::size_t pin) override;
            void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
            void dump() const override;
            pin_t &getPin(std::size_t pin) override;
            void setState(std::size_t pin, nts::Tristate state) override;
            nts::Tristate getState(std::size_t pin) override;
            std::string getType() override;

            class Error : public std::exception {
                public:
                    Error(char const *msg);
                    char const *what() const throw();
                private:
                    char const *_msg;
            };

        protected:
            std::map<std::size_t, std::unique_ptr<pin_t>> pins;
            std::string name;
        private:
    };
} // namespace nts


#endif /* !COMPONENT_HPP_ */
