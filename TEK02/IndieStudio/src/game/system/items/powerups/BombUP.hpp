/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** BombUP
*/

#ifndef BOMBUP_HPP_
#define BOMBUP_HPP_

#include "../PowerUp.hpp"
#include "../Bomb.hpp"
#include "../bombs/SpawnableBomb.hpp"
#include "../../entities/EntityLiving.hpp"
#include "../../../../IndieStudio.hpp"
#include "../../components/ModelComponent.hpp"
#include "../../../scenes/GameScene.hpp"
#include "../../../scenes/TutoScene.hpp"

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Power Up that increase number of bomb that the entity has
    **
    **/
    class BombUP : public PowerUp {
        public:
            BombUP() : PowerUp(30.f) {};
            ~BombUP() = default;

            void operator>>(EntityLiving &entity) {
                //TODO: Voir si on peux l'associer avec d'autre bombes
                (~entity) << std::make_shared<ClassicBomb>(FireResidue(entity), entity);
            };
            void spawn(Vector pos) { (~IndieStudio::getScenes())->getEntities() << std::make_shared<ItemEntity<PowerUp>>(pos, 'L', std::make_shared<BombUP>()); };
            void addComponentToEntity(Entity &entity) {
                GameScene *scene = nullptr;
                TutoScene *sceneTuto = nullptr;

                if ((scene = dynamic_cast<GameScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(scene->getPowerBomb(),  0.2);
                else if ((sceneTuto = dynamic_cast<TutoScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(sceneTuto->getPowerBomb(),  0.2);
            };
        protected:
        private:
    };
};

#endif /* !BOMBUP_HPP_ */
