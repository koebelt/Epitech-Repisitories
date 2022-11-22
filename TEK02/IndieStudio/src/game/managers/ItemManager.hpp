/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ItemManager
*/

#ifndef ITEMMANAGER_HPP_
#define ITEMMANAGER_HPP_

#include "./IManager.hpp"
#include <algorithm>
#include <list>
#include "../system/items/Item.hpp"

namespace istudio {
    class ItemManager : public IManager<Item>, public Collectable<Item> {
        public:
            ItemManager() = default;
            ~ItemManager() = default;

            ItemManager &operator<<(std::shared_ptr<Item> elem) {
                _objects.emplace_back(elem);
                return (*this);
            };

            std::list<std::shared_ptr<Item>> &operator~() { return _objects; };
        protected:
        private:
    };
}

#endif /* !ITEMMANAGER_HPP_ */
