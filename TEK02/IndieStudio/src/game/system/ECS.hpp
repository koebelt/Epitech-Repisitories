/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntityManager
*/

#ifndef ECS_HPP_
#define ECS_HPP_

#include <bitset>
#include <array>
#include <memory>
#include <iostream>
#include <vector>

#include "../../utils/CustomError.hpp"
#include "./IComponent.hpp"
#include "./components/Positionable.hpp"
#include "../utils/Vector.hpp"

/**
** @author Paul Gazeau-Rousseau
**
** @brief Useful Tools for ECS
**/
namespace istudio {

    class Entity;
	using ComponentID = std::size_t;

	constexpr std::size_t MAX_COMPONENTS = 32;

	using ComponentBitSet = std::bitset<MAX_COMPONENTS>;
	using ComponentArray = std::array<std::unique_ptr<IComponent>, MAX_COMPONENTS>;

	/**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class Entity: Entity ECS implementation class
    **/
    class Timer;
	class EntityContainer;
	class Entity {
		public:
			Entity() = delete;
			Entity(EntityContainer &container);

			Entity(const Entity &cpy) = delete;
			Entity(Entity &&entity) = delete;

			void draw();
			void update();

			void destroy() { _active = false; };
			bool isActive() { return _active; };
			void setActive(bool enabled) { _active = enabled; };
			void setPosition(VectorF position) {
				_position = position;
    			registerNewComponent<Positionable, VectorF&, VectorF&>(_position, _direction);
			};
			VectorF &getPosition() { return _position; };
			void setDirection(VectorF direction) { _direction = direction; };
			VectorF &getDirection() { return _direction; };
			EntityContainer &getContainer() { return _container; };

			/**
			** @author : Paul Gazeau-Rousseau
			**
			** @brief Function hasComponent: Check if a entity has a component
			**
			** @return 			true or false
			**/
			template <typename T>
			bool hasComponent() {
				ComponentID id = getComponentID<T>(_array);
				if (dynamic_cast<T *>(_array[id].get()))
					return (true);
				return (false);
			}

			/**
			** @author : Paul Gazeau-Rousseau
			**
			** @brief Function &registerNewComponent: Registering a new component for entity
			** @param component (Reference on a component): New component to register
			**
			** @return 			Component &
			**/
			template <typename T, typename... Args>
			T &registerNewComponent(Args... args) {
				if (hasComponent<T>())
					throw CustomError("ECS", "Already has component of this type");
				int pos = getComponentID<T>(_array);
				_array[pos] = std::make_unique<T>(args...);
				_array[pos]->entity = this;
				_bitSet[pos] = true;
				return (dynamic_cast<T &>(*_array[pos]));
			}

			/**
			** @author : Paul Gazeau-Rousseau
			**
			** @brief Function getComponent: Return component in array that contains T
			**
			** @return pointer on T
			**/
			template <typename T>
			T *getComponent() {
				ComponentID id = getComponentID<T>(_array);
				return dynamic_cast<T *>(_array[id].get());
			};
		private:
			bool _active = true;
			ComponentID lastID = 0;
			VectorF _position;
			VectorF _direction;
			EntityContainer &_container;

			/**
			* @brief Get the Component ID of an object
			*
			* @return id
			*/
			inline ComponentID getComponentID() {
				return lastID++;
			}

			/**
			** @author : Paul Gazeau-Rousseau
			**
			** @brief Function getComponentID: Return index of element in array
			** @param array: Array to check into
			**
			** @return 			id
			**/
			template <typename T>
			ComponentID getComponentID(ComponentArray &array) noexcept {
				for (int i = 0; i < array.size(); i++) {
					if (array[i] && dynamic_cast<T *>(array[i].get())) {
						return i;
					}
				}
				return getComponentID();
			}
			ComponentArray _array;
			ComponentBitSet _bitSet;
	};
}

#endif /* !ECS_HPP_ */
