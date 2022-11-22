/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** TutoScene
*/

#pragma once

#include "./Scene.hpp"
#include <list>

namespace istudio {

    class TutoScene : public Scene {
        public:
            TutoScene();

            void load();
            void unload();
            int eventScene(istudio::Window &win);
            int renderScene(istudio::Window &win);

            size_t getId() { return TUTO; };

            graphic::Model *getBomb() { return &_bomb; };
            graphic::Model *getExpl() { return &_explosion; };

            // Power
            graphic::Model *getPowerBomb() { return &_powerBomb; };
            graphic::Model *getPowerFire() { return &_powerFire; };
            graphic::Model *getPowerWall() { return &_powerWall; };
            graphic::Model *getPowerSpeed() { return &_powerSpeed; };

        protected:
        private:
            istudio::graphic::Camera _camera;
            istudio::graphic::Skybox _skybox;
            istudio::graphic::Model _powerBomb;
            istudio::graphic::Model _powerFire;
            istudio::graphic::Model _powerWall;
            istudio::graphic::Model _powerSpeed;
            istudio::graphic::AnimatedModel _player1;
            istudio::graphic::AnimatedModel _player2;
            istudio::graphic::Model _player1Idle;
            istudio::graphic::Model _player2Idle;
            istudio::graphic::Model _ia;
            istudio::graphic::Model _crate;
            istudio::graphic::Model _floor;
            istudio::graphic::Model _stone;
            istudio::graphic::Model _bomb;
            istudio::graphic::Model _explosion;
            istudio::graphic::TextBox _textBox;
            istudio::graphic::Sprite _stickBase;
            istudio::graphic::Sprite _stickPoint;
            istudio::graphic::Sprite _stickBomb;
            istudio::Matrix &_matrix;
            std::list<std::string> _dialog;
            istudio::graphic::Button _quitPause;
            istudio::graphic::Button _pauseButton;
            istudio::graphic::Button _resumeButton;
            istudio::graphic::Button _settings;
            istudio::graphic::Texture _pauseBg;
            bool _isPaused = false;
            int _isTalking = 1;
            int _isCrateDestroyed = 0;
    };

}