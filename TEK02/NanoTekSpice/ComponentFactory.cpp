/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-matheo.vitali
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
#include "Components/Component4001.hpp"
#include "Components/Component4011.hpp"
#include "Components/Component4030.hpp"
#include "Components/Component4069.hpp"
#include "Components/Component4071.hpp"
#include "Components/Component4081.hpp"
#include "Components/SimpleComponent.hpp"

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(const std::string &type)
{
    if (type == "input")
        return std::unique_ptr<nts::IComponent>(new nts::InputComponent());
    else if (type == "output")
        return std::unique_ptr<nts::IComponent>(new nts::OutputComponent());
    else if (type == "true")
        return std::unique_ptr<nts::IComponent>(new nts::StaticStateComponent(TRUE));
    else if (type == "false")
        return std::unique_ptr<nts::IComponent>(new nts::StaticStateComponent(FALSE));
    else if (type == "4001")
        return std::unique_ptr<nts::IComponent>(new nts::Component4001());
    else if (type == "4011")
        return std::unique_ptr<nts::IComponent>(new nts::Component4011());
    else if (type == "4030")
        return std::unique_ptr<nts::IComponent>(new nts::Component4030());
    else if (type == "4069")
        return std::unique_ptr<nts::IComponent>(new nts::Component4069());
    else if (type == "4071")
        return std::unique_ptr<nts::IComponent>(new nts::Component4071());
    else if (type == "4081")
        return std::unique_ptr<nts::IComponent>(new nts::Component4081());
    else
        throw Error("Invalid component type, cannot create");
}

nts::ComponentFactory::Error::Error(char const *msg)
{
    this->_msg = msg;
}

const char *nts::ComponentFactory::Error::what() const throw() {
    return _msg;
}

