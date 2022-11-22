/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** Scene
*/

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <string>
#include "../managers/EntityManager.hpp"
//#include "../../tools/NCurses.hpp"
#include "../utils/Timer.hpp"
#include "../../engine/Engine.hpp"

namespace istudio {

    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class IScene: interface that each scene must be implement
    **/
    class IScene {
        public:
            virtual ~IScene() = default;

            virtual void load() = 0;
            virtual void unload() = 0;
            virtual int eventScene(istudio::Window &win) = 0;
            virtual int renderScene(istudio::Window &win) = 0;

            virtual size_t getId() = 0;
            virtual EntityManager &getEntities() = 0;
    };

    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class Scene: base class for scene
    **/
    class Scene : public IScene {
        public:
            enum {
                MENU,
                GAME,
                SETTING,
                PRE_GAME,
                TUTO
            } SCENE_ID;
            Scene() = default;
            ~Scene() = default;

            EntityManager &getEntities() { return _manager; };
        protected:
            EntityManager _manager;
            bool _isLoaded = false;
    };
}

#endif /* !SCENE_HPP_ */
