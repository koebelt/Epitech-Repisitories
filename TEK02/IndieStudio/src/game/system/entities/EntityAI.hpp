/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntityAI
*/

#ifndef ENTITYAI_HPP_
#define ENTITYAI_HPP_

#include "./EntityLiving.hpp"
#include "../../../engine/graphic/3d/model/animated_model/AnimatedModel.hpp"

namespace istudio {
    class EntityAI : public EntityLiving {
        public:
            EntityAI(graphic::AnimatedModel *model, graphic::Model *idle, VectorF pos, Vector size = Vector(1, 1));

            EntityAI(const EntityAI &entity) = delete;
            EntityAI(EntityAI &&ref) = delete;
            int getSymbol() { return 'A'; };
        protected:
        private:
    };
}

#endif /* !ENTITYAI_HPP_ */
