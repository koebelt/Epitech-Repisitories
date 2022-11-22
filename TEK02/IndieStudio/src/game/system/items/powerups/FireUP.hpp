/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** FireUp
*/

#ifndef FIREUP_HPP_
#define FIREUP_HPP_

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
    ** @brief Power Up that increase range of the bomb
    **
    **/
    class FireUP : public PowerUp {
        public:
            FireUP(int nbPLevel = 1) : PowerUp(30.f), _nbPLevel(nbPLevel) {};
            ~FireUP() = default;

            void operator>>(EntityLiving &entity) {
                entity.setFireRadius(entity.getFireRadius() + _nbPLevel);
            };
            void spawn(Vector pos) { (~IndieStudio::getScenes())->getEntities() << std::make_shared<ItemEntity<PowerUp>>(pos, 'M', std::make_shared<FireUP>(_nbPLevel)); };
            void addComponentToEntity(Entity &entity) {
                GameScene *scene = nullptr;
                TutoScene *sceneTuto = nullptr;

                if ((scene = dynamic_cast<GameScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(scene->getPowerFire(),  0.2);
                else if ((sceneTuto = dynamic_cast<TutoScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(sceneTuto->getPowerFire(),  0.2);
            };
        protected:
        private:
            int _nbPLevel;
    };
};

#endif /* !FIREUP_HPP_ */
