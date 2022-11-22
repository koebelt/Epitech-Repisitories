/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Cook
*/

#ifndef COOK_HPP_
#define COOK_HPP_

#include "./food/Pizza.hpp"
#include "./Stock.hpp"
#include "./process/Mutex.hpp"
#include <memory>

namespace plz {
    class Kitchen;
    class Cook {
        public:
            Cook();
            ~Cook();

            Cook& operator=(const Cook&) = delete;
            Cook(const Cook& cpy) : _holdingPizza(cpy._holdingPizza) {};

            Cook(Cook &&obj);

            void cookPizza(Cook *cook);
            std::shared_ptr<Pizza> getHoldingPizza() const { return _holdingPizza; };
        protected:
        private:
            std::shared_ptr<Pizza> _holdingPizza;
            bool _isValid = false;
            friend class Kitchen;
    };
}

#endif /* !COOK_HPP_ */
