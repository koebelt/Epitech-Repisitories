/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ClassicBomb
*/

#ifndef CLASSICBOMB_HPP_
#define CLASSICBOMB_HPP_

#include "../Bomb.hpp"
#include <list>
#include "./FireResidue.hpp"
#include "../../../../IndieStudio.hpp"
#include "../../components/ModelComponent.hpp"
#include "../../../scenes/GameScene.hpp"
#include "../../../scenes/TutoScene.hpp"

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Bomb that can spawn other bomb in their radius when exploding
    **
    **/
    template <class T, unsigned int R, unsigned int D, char S>
    class SpawnableBomb : public Bomb {
        public:
            SpawnableBomb() = delete;
            SpawnableBomb(T target, EntityLiving &entliving) :
            Bomb(R + entliving.getFireRadius(), D),
            _target(target),
            _entliving(entliving) {
                _bomb.load("./assets/audio/bomb.mp3");
                _bomb.setVolume(istudio::IndieStudio::soundVolume);
            };

            SpawnableBomb(const SpawnableBomb &cpy) = delete;
            SpawnableBomb(SpawnableBomb &&ref) :
                Bomb(R + ref._entliving.getFireRadius(), D),
                _target(ref._target),
                _entliving(ref._entliving)
            {
                _bomb.load("./assets/audio/bomb.mp3");
                _bomb.setVolume(istudio::IndieStudio::soundVolume);
            };
            ~SpawnableBomb() = default;

            void waiting_action(Entity *entity) {};
            void explode(Entity *entity) {
                EntityManager &entities = (~IndieStudio::getScenes())->getEntities();
                Matrix &matrix = IndieStudio::getMatrix();
                _bomb.setVolume(IndieStudio::soundVolume);
                _bomb.play();

                auto spawnN = [=, &matrix](Vector direction, Vector t) {
                    Vector epos = entity->getPosition().round();
                    Vector pos = (epos + direction);

                    if (!matrix.isValid(pos))
                        return (0);
                    if (!matrix.isValid(epos + t, {WALL}))
                        return (0);
                    (~IndieStudio::getScenes())->getEntities() << std::make_shared<ItemEntity<T>>(pos, 'F', std::make_shared<T>(_target));
                    return (matrix(pos) == BREAKABLE ? 0 : 1);
                };

                spawnN(Vector(0, 0), Vector(0, 0));
                for (int i = 1; i != _radius && spawnN(Vector(i, 0), Vector(1, 0)); i++);
                for (int i = 1; i != _radius && spawnN(Vector(-i, 0), Vector(-1, 0)); i++);
                for (int i = 1; i != _radius && spawnN(Vector(0, i), Vector(0, 1)); i++);
                for (int i = 1; i != _radius && spawnN(Vector(0, -i), Vector(0, -1)); i++);
                setUsed(false);
            }

            void spawn(Vector pos) {
                setUsed(true);
                (~IndieStudio::getScenes())->getEntities() << std::make_shared<ItemEntity<SpawnableBomb>>(pos, S, *this);
            }

            void addComponentToEntity(Entity &entity)
            {
                GameScene *scene = nullptr;
                TutoScene *sceneTuto = nullptr;

                entity.registerNewComponent<BombExplosionable<SpawnableBomb>, SpawnableBomb&>(*this);
                if ((scene = dynamic_cast<GameScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(scene->getBomb(),  0.2);
                else if ((sceneTuto = dynamic_cast<TutoScene *>(&*(~IndieStudio::getScenes()))))
                    entity.registerNewComponent<ModelComponent>(sceneTuto->getBomb(),  0.2);
            }
        protected:
        private:
            istudio::Audio::Sound _bomb;
            T _target;
            EntityLiving &_entliving;
    };

    using ClassicBomb = SpawnableBomb<FireResidue, 3, 2500, 'B'>;
    using SuperBomb = SpawnableBomb<ClassicBomb, 5, 6000, 'S'>;
}

#endif /* !CLASSICBOMB_HPP_ */
