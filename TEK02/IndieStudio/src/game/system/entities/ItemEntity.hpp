/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ItemEntity
*/

#ifndef ITEMENTITY_HPP_
#define ITEMENTITY_HPP_

#include "../IEntityContainer.hpp"
#include "../../utils/Vector.hpp"
#include "../../../utils/CustomError.hpp"
#include "../items/Item.hpp"

#include <memory>
#include <functional>
#include <type_traits>

namespace istudio {
    class IItemWithComponent;
    template <class T>
    class ItemEntity : public EntityContainer {
        public:
            enum Mode {
                CREATION,
                MODIFICATION
            };
            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Handle an existing item an create an entity for it
            ** @param pos Position of the item 
            ** @param symbol Symbol of the item (ncurses) @deprecated
            ** @param item Reference on the existing item
            **
            **/
            ItemEntity(Vector pos, char symbol, T &item) :
                _symbol(symbol),
                _item(std::shared_ptr<T>(&item, [](T *){}))
            {
                _entity.setPosition(VectorF(pos.getX(), pos.getY()));

                IItemWithComponent *cmp = nullptr;
                if ((cmp = dynamic_cast<IItemWithComponent *>(&item)))
                    cmp->addComponentToEntity(_entity);
            };
            /**
            ** @author : Paul Gazeau-Rousseau
            **
            ** @brief Handle an new item an create an entity for it
            ** @param pos Position of the item 
            ** @param symbol Symbol of the item (ncurses) @deprecated
            ** @param item The new item to handle
            **
            **/
            ItemEntity(Vector pos, char symbol, std::shared_ptr<T> item) :
                _symbol(symbol),
                _item(item)
            {
                _entity.setPosition(VectorF(pos.getX(), pos.getY()));

                IItemWithComponent *cmp = nullptr;
                if ((cmp = dynamic_cast<IItemWithComponent *>(_item.get())))
                    cmp->addComponentToEntity(_entity);
            };
            ItemEntity(const ItemEntity &entity) = delete;
            ItemEntity(ItemEntity &&ref) = delete;
            ItemEntity &operator=(const ItemEntity &cpy) = delete;

            ~ItemEntity() = default;
            
            int getSymbol() { return _symbol; };
            Item &operator~() { return *_item; };
        protected:
        private:
            std::shared_ptr<T> _item;
            char _symbol;
    };
}

#endif /* !ITEMENTITY_HPP_ */
