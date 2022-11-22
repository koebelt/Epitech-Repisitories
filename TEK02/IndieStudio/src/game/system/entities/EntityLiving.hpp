/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** EntityLiving
*/

#ifndef ENTITYLIVING_HPP_
#define ENTITYLIVING_HPP_

#include "../IEntityContainer.hpp"
#include "../../managers/ItemManager.hpp"
#include "../../utils/Vector.hpp"
#include "../../../engine/graphic/3d/model/animated_model/AnimatedModel.hpp"
#include "../../../engine/graphic/3d/model/Model.hpp"

#include <algorithm>

namespace istudio {
    class EntityLiving : public EntityContainer {
        public:
            EntityLiving(graphic::AnimatedModel *model, graphic::Model *idle, VectorF scale, VectorF pos, Vector size = Vector(1, 1));
            EntityLiving(EntityLiving &&ref) = delete;

            ItemManager &operator~() { return _items; };
            VectorF getPosition();
            VectorF getDirection();
            void setDirection(VectorF vector);

            /**
             ** @author : Paul Gazeau-Rousseau
             ** @template T The class of item to use
             **
             ** @brief Function that use an item in the player inventory
             **
             **/
            template <typename T>
            void useItem() {
                std::list<T *> corrs = *_items.collect<T>();
                if (corrs.size() <= 0) return;
                for (auto it = corrs.begin(); it != corrs.end(); it++) {
                    if (!(*it)->isUsed()) {
                        (*it)->spawn(_entity.getPosition().round());
                        break;
                    }
                }
            };

            /**
             ** @author : Paul Gazeau-Rousseau
             **
             ** @brief Function that tell if player has at least on active item
             **
             **/
            bool hasActiveItem();
            Vector getSize();
            Vector getScale();

            double getSpeedMultiplier() { return _speedMult; };
            bool isGhostMode() { return _canWallPass; };
            int getFireRadius() { return _fireUp; };

            void setSpeedMultiplier(double speedMult) { _speedMult = speedMult; };
            void setGhostMode(bool enabled) { _canWallPass = enabled; };
            void setFireRadius(int radius);

            void setMovable(bool enabled) { _canMove = enabled; };
            bool canMove() { return _canMove; };
            bool isDead() { return _dead; };
            void setDead(bool dead) { _dead = dead; };

            bool hasExplored(Vector position) { return std::find_if(_explored.begin(), _explored.end(), [&position](auto &e) -> bool {
                return e == position;
            }) != _explored.end(); };
            void addExplored(Vector position) { _explored.push_back(position); };
            std::vector<Vector> &getExplored() { return _explored; };
            std::vector<Vector> &copyExplored(std::vector<Vector> &explored) {
                _explored.insert(_explored.end(), explored.begin(), explored.end());
                return _explored;
            };
        protected:
            bool _dead = false;
        private:
            ItemManager _items{};
            double _speedMult = 1.f;
            bool _canWallPass = false;
            int _fireUp = 0;
            bool _canMove = false;
            std::vector<Vector> _explored{};
    };
}

#endif /* !ENTITYLIVING_HPP_ */
