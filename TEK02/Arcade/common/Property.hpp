/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-arcade-thomas.koebel
** File description:
** Property
*/


#ifndef PROPERTY_HPP_
#define PROPERTY_HPP_

#include <string>
#include <vector>
#include <exception>
#include <memory>
#include <any>

namespace arcade
{

    class Property
    {
    public:
        virtual ~Property() = default;
    }; // DUMMY CLASS TO ENGLOB ALL

    class PropertyBasic : public Property
    {
    public:
        PropertyBasic(const std::string &name, std::any element) : _name(name), _elem({element}){};
        PropertyBasic(const std::string &name, std::vector<std::any> element) : _name(name), _elem(element){};

        PropertyBasic &operator=(const PropertyBasic &p)
        {
            _name = p.getName();
            _elem = p.getElements();
            return (*this);
        };

        std::vector<std::any> getElements() const { return _elem; };

        std::vector<std::any> getPureElement() const { return _elem; };

        template <typename T>
        T getElement() { return (std::any_cast<T>(_elem[0])); };

        template <typename T>
        std::vector<T> getVElement()
        {
            std::vector<T> list;
            for (auto it = _elem.begin(); it != _elem.end(); it++)
                list.push_back(std::any_cast<T>(*it));
            return (list);
        };
        std::string getName() const { return _name; };

    protected:
    private:
        std::string _name;
        std::vector<std::any> _elem;
    };

    class PropertyList : public Property
    {
    public:
        PropertyList(const std::vector<PropertyBasic> properties, const char symbol = -1) : _props(properties), _symbol(symbol){};
        PropertyList(const PropertyBasic property, const char symbol = -1) : _props({property}), _symbol(symbol){};

        template <typename T>
        std::unique_ptr<T> get(const std::string &name)
        {
            for (PropertyBasic prop : _props)
                if (prop.getName() == name)
                    return (std::make_unique<T>(prop.getElement<T>()));
            return (nullptr);
        };

        template <typename T>
        T getOr(const std::string &name, T def)
        {
            std::unique_ptr<T> ptr = get<T>(name);
            if (ptr)
                return *ptr.get();
            return def;
        }

        template <typename T>
        std::vector<T> getV(const std::string &name)
        {
            for (PropertyBasic prop : _props)
                if (prop.getName() == name)
                    return (prop.getVElement<T>());
            return (std::vector<T>());
        }

        char getSymbol() const { return _symbol; }

    private:
        std::vector<PropertyBasic> _props;
        char _symbol;
    };
}
#endif /* !PROPERTY_HPP_ */