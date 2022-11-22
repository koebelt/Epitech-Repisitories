/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include "IComponent.hpp"
#include <string>
#include <memory>

namespace nts {
    class ComponentFactory {
        public:
            static std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
            class Error : public std::exception {
                public:
                    Error(char const *msg);
                    char const *what() const throw();
                private:
                    char const *_msg;
            };
        private:
    };
} // namespace nts

#endif /* !COMPONENTFACTORY_HPP_ */
