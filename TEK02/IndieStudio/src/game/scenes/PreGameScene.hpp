/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** PreGameScene
*/

#pragma once

#include "./Scene.hpp"

#include <iostream>
#include <vector>

namespace istudio {
    class PreGameScene : public Scene {
        public:
            PreGameScene() {};
            ~PreGameScene() {};

            void load();
            void unload();
            int eventScene(istudio::Window &win) { return 0; };
            int renderScene(istudio::Window &win);

            size_t getId() { return PRE_GAME; };

            inline static int typeIT = 0;
            inline static int typeIT2 = 0;
            inline static int typeIT3 = 0;
            inline static int typeIT4 = 0;
            inline static int size = 13;
        protected:
        private:
            std::vector<std::string> _typeList = {"Player", "AI", "None"};
            istudio::graphic::Texture _background;
            istudio::graphic::Sprite _skinList;
            istudio::graphic::Button _arrowLeftType;
            istudio::graphic::Button _arrowRightType;
            istudio::graphic::Button _arrowLeftType2;
            istudio::graphic::Button _arrowRightType2;
            istudio::graphic::Button _arrowLeftType3;
            istudio::graphic::Button _arrowRightType3;
            istudio::graphic::Button _arrowLeftType4;
            istudio::graphic::Button _arrowRightType4;
            istudio::graphic::Button _arrowLeftSize;
            istudio::graphic::Button _arrowRightSize;
            istudio::graphic::Button _play;
            istudio::graphic::Button _back;
            istudio::graphic::Texture _controls_player_one;
            istudio::graphic::Texture _controls_player_two;
            istudio::graphic::Texture _controls_player_three;
            istudio::graphic::Texture _controls_player_four;
            istudio::Font _font;
            istudio::Audio::Music _music;
    };
}
