/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ECS
*/

#include "ECS.hpp"
#include "./IEntityContainer.hpp"

istudio::Entity::Entity(EntityContainer &container) :
    _container(container),
	_position(VectorF(0, 0)),
	_direction(VectorF(0, 0))
{

};

void istudio::Entity::draw()
{
	IComponentDrawable *drawable = nullptr;

	if (!isActive()) return;
	for (auto &c : _array) {
		if (!c || !(drawable = dynamic_cast<IComponentDrawable *>(c.get()))) continue;
		drawable->draw();
	}
};

void istudio::Entity::update()
{
	for (auto &c : _array) {
		if (!isActive() || !c) continue;
		c->update();
	}
};