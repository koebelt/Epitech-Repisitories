/*
** EPITECH PROJECT, 2022
** Plazza
** File description:
** Stock
*/

#ifndef STOCK_HPP_
#define STOCK_HPP_

#include <map>

extern "C" {
    #include <stdio.h>
    #include <sys/types.h>
    #include <unistd.h>
}
#define MAX_STOCK 5

namespace plz {

    enum Ingredient : int {
        DOE = 1,
        TOMATO = 2,
        GRUYERE = 3,
        HAM = 4,
        MUSHROOMS = 5,
        STEAK = 6,
        EGGPLANT = 7,
        GOAT_CHEESE = 8,
        CHIEF_LOVE = 9
    };

    class Kitchen;
    class Stock  {
        public:
            Stock(pid_t pid);

            Stock(const Stock& cpy) = delete;
            Stock& operator=(const Stock&) = delete;

            Stock(Stock &&stock);
            void refill();
            bool contains(Ingredient &ingredient);
            bool pick(Ingredient &ingredient);
        protected:
        private:
            std::map<int, int> _ingredients;
            pid_t _pid;
    };
}

#endif /* !STOCK_HPP_ */
