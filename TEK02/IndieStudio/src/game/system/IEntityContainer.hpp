/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IEntityContainer
*/

#ifndef IENTITYCONTAINER_HPP_
#define IENTITYCONTAINER_HPP_

#include "./ECS.hpp"

// Components

#include "./components/BombExplosionable.hpp"
#include "./components/Transformable.hpp"
#include "./components/IAComponent.hpp"

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class IEntityContainer: Basic Interface for each entity container element
    **/
    class IEntityContainer {
        public:
            virtual ~IEntityContainer() = default;

            virtual Entity &operator->() = 0;
            virtual Entity &operator*() = 0;
            virtual Entity &getEntity() = 0;
            /**
             * @deprecated
             */
            virtual int getSymbol() = 0;
    };

    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class EntityContainer: Basic Base for each entity container element
    **/
    class EntityContainer : public IEntityContainer {
        public:
            EntityContainer() : _entity(Entity(*this)) {};

            Entity &operator->() { return _entity; };
            Entity &operator*() { return _entity; };
            Entity &getEntity() { return _entity; };
        protected:
            Entity _entity;
    };
}

#endif /* !IENTITYCONTAINER_HPP_ */
