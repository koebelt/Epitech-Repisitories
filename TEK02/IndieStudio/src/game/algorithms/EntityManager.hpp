/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntityManager
*/

#ifndef ENTITYMANAGER_HPP_
#define ENTITYMANAGER_HPP_

#include <memory>
#include <algorithm>
#include <vector>
#include <list>

#include "./IManager.hpp"
#include "../system/IEntityContainer.hpp"
#include "../system/entities/EntityLiving.hpp"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Class EntityManager ( public IManager<Entity> ): Manager for entity
**/
namespace istudio {
	class Timer;
	class Entity;
    class EntityManager : public IManager<EntityContainer>, public Collectable<EntityContainer> {
		public:
			void update() {
				refresh();
				EntityLiving *living = nullptr;
				for (auto &e : _objects) {
					if ((living = dynamic_cast<EntityLiving *>(&*e)) && living->isDead()) continue;
					(*(*e)).update();
				}
			}

			void draw() {
				EntityLiving *living = nullptr;
				for (auto &e : _objects) {
					if ((living = dynamic_cast<EntityLiving *>(&*e)) && living->isDead()) continue;
					(*(*e)).draw();
				}
			}

			EntityManager &operator<<(std::shared_ptr<EntityContainer> entity) {
				_objects.emplace_back(entity);
				return *this;
			};

			void clear() {
				_objects.erase(_objects.begin(), _objects.end());
			}

			void erase(EntityContainer *container) {
				for (auto it = _objects.begin(); it != _objects.end(); it++) {
					if (!(it->get() == container)) continue;
					it->get()->getEntity().destroy();
				}
			}
		private:
			void refresh() {
				_objects.erase(std::remove_if(std::begin(_objects), std::end(_objects), [](const std::shared_ptr<EntityContainer> &entity) {
					return (!(*(*entity)).isActive());
				}), std::end(_objects));
			}
	};
}

#endif /* !ENTITYMANAGER_HPP_ */
