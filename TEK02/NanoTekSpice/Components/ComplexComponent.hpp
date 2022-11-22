/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** ComplexComponent
*/

#ifndef COMPLEXCOMPONENT_HPP_
#define COMPLEXCOMPONENT_HPP_

#include "Component.hpp"

namespace nts {
    class ComplexComponent : public Component {
        public:
            ComplexComponent() = default;
            ~ComplexComponent() = default;

        protected:
            std::map<int, std::unique_ptr<IComponent>>gates;
        private:
    };
} // namespace nts
#endif /* !COMPLEXCOMPONENT_HPP_ */
