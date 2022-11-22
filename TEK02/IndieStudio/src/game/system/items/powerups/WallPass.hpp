/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** WallPass
*/

#ifndef WALLPASS_HPP_
#define WALLPASS_HPP_

#include "../PowerUp.hpp"
#include "../../entities/EntityLiving.hpp"
#include "../../../../IndieStudio.hpp"
#include "../../components/ModelComponent.hpp"
#include "../../../scenes/GameScene.hpp"
#include "../../../scenes/TutoScene.hpp"

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Power Up that allow player to go through breakable wall
    **
    **/
    class WallPass : public PowerUp {
        public:
            WallPass() : PowerUp(10.f) {};
            ~WallPass() = default;

            void operator>>(EntityLiving &entity) {
                entity.setGhostMode(true);
            };
            void spawn(Vector pos) { (~IndieStudio::getScenes())->getEntities() << std::make_shared<ItemEntity<PowerUp>>(pos, 'W', std::make_shared<WallPass>()); };
            void addComponentToEntity(Entity &entity) {
                GameScene *scene = nullptr;
                TutoScene *sceneTuto = nullptr;

                if ((scene = dynamic_cast<GameScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(scene->getPowerWall(),  0.4);
                else if ((sceneTuto = dynamic_cast<TutoScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(sceneTuto->getPowerWall(),  0.4);
            };
        protected:
        private:
            double _speed;
    };
};

#endif /* !WALLPASS_HPP_ */
