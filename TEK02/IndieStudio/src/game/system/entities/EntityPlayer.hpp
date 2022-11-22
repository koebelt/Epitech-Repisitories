/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** EntityPlayer
*/

#ifndef ENTITYPLAYER_HPP_
#define ENTITYPLAYER_HPP_

#include "EntityLiving.hpp"
#include "../../../engine/graphic/3d/model/Model.hpp"
#include "../../../engine/event/keyboard/Keyboard.hpp"
#include "../../utils/Vector.hpp"

#include <algorithm>

namespace istudio {
    class EntityPlayer : public EntityLiving {
        public:
            EntityPlayer(graphic::AnimatedModel *model, graphic::Model *idle, VectorF pos = VectorF(0, 0), std::vector<int> keys = {event::LEFT_ARROW, event::UP_ARROW, event::RIGHT_ARROW, event::DOWN_ARROW, event::B}, Vector size = Vector(1, 1));
            ~EntityPlayer() = default;

            EntityPlayer(const EntityPlayer &entity) = delete;
            EntityPlayer(EntityPlayer &&ref) = delete;

            int handle(int key);
            int getSymbol() { return 'P'; };
            std::vector<int> getKeys() { return _keys; };
        protected:
        private:
            std::vector<int> _keys;
    };
}

#endif /* !ENTITYPLAYER_HPP_ */
