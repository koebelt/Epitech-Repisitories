/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** MenuScene
*/

#include "MenuScene.hpp"
#include "../../IndieStudio.hpp"

namespace istudio {

    int MenuScene::renderScene(istudio::Window &win)
    {
        _background.draw(istudio::math::Vector2(0, 0), istudio::graphic::Color(255, 255, 255));
        _title.draw(istudio::math::Vector2(450, -80), istudio::graphic::Color(255, 255, 255));
        _music.setVolume(istudio::IndieStudio::musicVolume);

        if (!_music.isPlaying())
            _music.play();
        _music.update();
        if (!_isMult) {
            if (_play.update())
                istudio::IndieStudio::getScenes().load(PRE_GAME);
            if (_tuto.update())
                istudio::IndieStudio::getScenes().load(TUTO);
            if (_settings.update())
                istudio::IndieStudio::getScenes().loadAndKeepLast(SETTING);
            if (_multiplayer.update())
                _isMult = true;
        } else {
            if (_hostGame.update());
            if (_joinGame.update());
            if (_back.update())
                _isMult = false;
        }
        if (_quit.update()) return (1);
        return (0);
    }
    int MenuScene::eventScene(istudio::Window &win)
    {
        return (0);
    }

    void MenuScene::unload()
    {
        if (!_isLoaded) return;
        _play.unload();
        _settings.unload();
        _quit.unload();
        _multiplayer.unload();
        _hostGame.unload();
        _joinGame.unload();
        _background.unload();
        _back.unload();
        _title.unload();
        _music.unload();
        _tuto.unload();
        _isLoaded = false;
    }

    void MenuScene::load()
    {
        _isLoaded = true;
        _play.load("./assets/images/play_button.png", istudio::math::Vector2(800, 350), 1, 3);
        _settings.load("./assets/images/settings_button.png", istudio::math::Vector2(800, 500), 1, 3);
        _quit.load("./assets/images/quit_button.png", istudio::math::Vector2(1600, 900), 1, 3);
        _multiplayer.load("./assets/images/multiplayer_button.png", istudio::math::Vector2(800, 650), 1, 3);
        _hostGame.load("./assets/images/host_game.png", istudio::math::Vector2(800, 350), 1, 3);
        _joinGame.load("./assets/images/join_game_button.png", istudio::math::Vector2(800, 650), 1, 3);
        _back.load("./assets/images/left_arrow.png", istudio::math::Vector2(100, 900), 1, 3);
        _tuto.load("./assets/images/tutorial_button.png", istudio::math::Vector2(100, 900), 1, 3);
        _background.load("./assets/images/walltest.png");
        _title.load("./assets/images/name_logo.png");
        _music.load("./assets/audio/menu.mp3");
        _music.setVolume(istudio::IndieStudio::musicVolume);
    }
}