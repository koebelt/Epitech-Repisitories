/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** GameScene
*/

#ifndef GAMESCENE_HPP_
#define GAMESCENE_HPP_

#include "./Scene.hpp"

#include <iostream>

namespace istudio {
    /**
    ** @author : Paul Gazeau-Rousseau
    **
    ** @brief Class Game Scene: Game menu
    **/
    class SpeedUP;
    class GameScene : public Scene {
        public:
            GameScene();

            void load();
            void unload();
            int eventScene(istudio::Window &win);
            int renderScene(istudio::Window &win);

            size_t getId() { return GAME; };

            graphic::Model *getBomb() { return &_bomb; };
            graphic::Model *getExpl() { return &_explosion; };

            // Power
            graphic::Model *getPowerBomb() { return &_powerBomb; };
            graphic::Model *getPowerFire() { return &_powerFire; };
            graphic::Model *getPowerWall() { return &_powerWall; };
            graphic::Model *getPowerSpeed() { return &_powerSpeed; };
        protected:
        private:
            float _loading;
            istudio::graphic::Texture _loadingBg;
            istudio::graphic::Camera _camera;
            istudio::graphic::Skybox _skybox;
            istudio::graphic::Model _powerBomb;
            istudio::graphic::Model _powerFire;
            istudio::graphic::Model _powerWall;
            istudio::graphic::Model _powerSpeed;
            istudio::graphic::AnimatedModel _player1;
            istudio::graphic::AnimatedModel _player2;
            istudio::graphic::AnimatedModel _player3;
            istudio::graphic::AnimatedModel _player4;
            istudio::graphic::Model _player1Idle;
            istudio::graphic::Model _player2Idle;
            istudio::graphic::Model _player3Idle;
            istudio::graphic::Model _player4Idle;
            istudio::graphic::Model _crate;
            istudio::graphic::Model _floor;
            istudio::graphic::Model _stone;
            istudio::graphic::Model _bomb;
            istudio::graphic::Model _explosion;
            istudio::graphic::Button _quit;
            istudio::Font _font;
            istudio::graphic::Button _quitPause;
            istudio::graphic::Button _pauseButton;
            istudio::graphic::Button _resumeButton;
            istudio::graphic::Button _settings;
            istudio::graphic::Texture _pauseBg;
            bool _isEnded = false;
            bool _isPaused = false;
            istudio::Audio::Music _music;
            istudio::Audio::Sound _sound;
            istudio::Matrix &_matrix;
    };
}

#endif /* !GAMESCENE_HPP_ */
