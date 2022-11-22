/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** SettingScene
*/

#pragma once

#include "./Scene.hpp"

#include <iostream>

/**
** @author : ethan
**
** @brief Class SettingScene: Class for the setting menu scene
**/

namespace istudio {
    class SettingScene : public Scene {
        public:
            SettingScene(){};
            ~SettingScene() {};

            void load();
            void unload();
            int eventScene(istudio::Window &win) { return 0; };
            int renderScene(istudio::Window &win);

            size_t getId() { return SETTING; };
        protected:
        private:
            istudio::graphic::Button _quit;
            istudio::graphic::Button _back;
            istudio::graphic::Button _plus_master;
            istudio::graphic::Button _minus_master;
            istudio::graphic::Texture _background;
            istudio::Audio::Music _music;
            istudio::Audio::Sound _click;
            istudio::Font _font;//("./assets/miscs/game.ttf");

            istudio::graphic::Button _plus_music;
            istudio::graphic::Button _minus_music;
            istudio::graphic::Button _plus_sound;
            istudio::graphic::Button _minus_sound;
    };
}
