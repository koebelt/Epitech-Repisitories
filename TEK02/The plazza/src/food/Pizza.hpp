/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Pizza
*/

#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#include "../Stock.hpp"
#include <vector>
#include <map>

namespace plz {

    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    class Pizza {
        public:
            Pizza() {};
            Pizza(PizzaType type, PizzaSize size): _type(type), _size(size) {};

            bool canPack(Stock &stock);
            void pack(Stock &stock);
            std::vector<Ingredient> unpack();

            Pizza(const Pizza &cpy) : _type(cpy._type), _size(cpy._size) {};
            Pizza &operator=(const Pizza &cpy) {
                _type = cpy._type;
                _size = cpy._size;
                return (*this);
            }

            int getCookTime() const;
            PizzaType getPizzaType() const { return _type; };
            PizzaSize getSize() const { return _size; };
        private:
            PizzaType _type;
            PizzaSize _size;
    };
}

#endif /* !PIZZA_HPP_ */
