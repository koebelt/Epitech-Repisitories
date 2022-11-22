/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** SpeedUP
*/

#ifndef SPEEDUP_HPP_
#define SPEEDUP_HPP_

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
    ** @brief Power Up that increase speed of the player
    **
    **/
    class SpeedUP : public PowerUp {
        public:
            SpeedUP(double speedBoost = 1.5f) : PowerUp(30.f), _speed(speedBoost) {};
            ~SpeedUP() = default;

            void operator>>(EntityLiving &entity) {
                if (entity.getSpeedMultiplier() < 4.5)
                    entity.setSpeedMultiplier(entity.getSpeedMultiplier() + _speed);
            };
            void spawn(Vector pos) { (~IndieStudio::getScenes())->getEntities() << std::make_shared<ItemEntity<PowerUp>>(pos, 'K', std::make_shared<SpeedUP>(_speed)); };
            void addComponentToEntity(Entity &entity) {
                GameScene *scene = nullptr;
                TutoScene *sceneTuto = nullptr;

                if ((scene = dynamic_cast<GameScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(scene->getPowerSpeed(),  0.4);
                else if ((sceneTuto = dynamic_cast<TutoScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(sceneTuto->getPowerSpeed(),  0.4);
            };
        protected:
        private:
            double _speed;
    };
}

#endif /* !SPEEDUP_HPP_ */
