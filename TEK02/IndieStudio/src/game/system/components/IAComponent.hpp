/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IAComponent
*/

#ifndef IACOMPONENT_HPP_
#define IACOMPONENT_HPP_

#include "../IComponent.hpp"
#include <vector>
#include <deque>
#include <memory>
#include <iostream>
#include <list>
#include <algorithm>
#include <deque>
#include <map>
#include <climits>
#include "../IEntityContainer.hpp"
#include "../../utils/Matrix.hpp"
#include "../../utils/Timer.hpp"

namespace istudio {
    class EntityManager;
    class EntityLiving;

    class IAComponent : public IComponent {
        public:
            enum DIRECTION : int {
                LEFT,
                TOP,
                RIGHT,
                BOTTOM
            };

            typedef struct {
                double Gcost;
                double Hcost;
                double Fcost;
                Vector position;
                Vector direction;
            } Slot;

            IAComponent() = default;
            ~IAComponent() = default;

            IAComponent(const IAComponent &cpy) = delete;
            IAComponent(IAComponent &&ref) = delete;

            void update();

        protected:
        private:
            bool isOnSafePlace(Vector pos, EntityManager &manager);
            bool isSecure(Vector pos, EntityManager &manager, std::vector<int> banned = {WALL});
            std::unique_ptr<Vector> findTarget(EntityManager &matches);
            std::unique_ptr<Vector> findNearestSafePlace(Vector pos, EntityManager &manager, int last_path = -1);
            int AAlgorithm(Vector pos, Vector &choosen, bool safePlace);
            int EscapeAlgorithm(Vector iaPos, std::list<Vector> &list, istudio::EntityManager &manager);
            std::unique_ptr<Vector> _target = nullptr;
            Timer _localtimer;
    };
}

#endif /* !IACOMPONENT_HPP_ */
