/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** MenuScene
*/

#ifndef MENUSCENE_HPP_
#define MENUSCENE_HPP_

#include "./Scene.hpp"

#include <iostream>

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class Menu Scene: Main menu scene
    **/
    class MenuScene : public Scene {
        public:
            MenuScene(){};
            ~MenuScene() {};

            void load();
            void unload();
            int eventScene(istudio::Window &win);
            int renderScene(istudio::Window &win);

            size_t getId() { return MENU; };
        protected:
        private:
            istudio::graphic::Texture _title;
            istudio::graphic::Texture _background;
            istudio::graphic::Button _play;
            istudio::graphic::Button _settings;
            istudio::graphic::Button _quit;
            istudio::graphic::Button _multiplayer;
            istudio::graphic::Button _joinGame;
            istudio::graphic::Button _hostGame;
            istudio::graphic::Button _back;
            istudio::graphic::Button _tuto;
            istudio::Audio::Music _music;
            bool _isMult = false;
    };
}

#endif /* !MENUSCENE_HPP_ */
