/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** SettingScene
*/

#include "SettingScene.hpp"
#include "../../IndieStudio.hpp"

namespace istudio {
    int SettingScene::renderScene(istudio::Window &win)
    {
        
        _background.draw(istudio::math::Vector2(0, 0), istudio::graphic::Color(255, 255, 255));
        istudio::graphic::Text::drawText(_font, "MASTER VOLUME", 800, 300, 100, istudio::graphic::Color(255, 255, 255));
        istudio::graphic::Text::drawText(_font, std::to_string((int)(0.01 + istudio::IndieStudio::masterVolume * 100)), 450, 300, 100, istudio::graphic::Color(255, 255, 255));
        istudio::graphic::Text::drawText(_font, "MUSIC VOLUME", 800, 450, 100, istudio::graphic::Color(255, 255, 255));
        istudio::graphic::Text::drawText(_font, std::to_string((int)(istudio::IndieStudio::musicVolume * 10)), 450, 450, 100, istudio::graphic::Color(255, 255, 255));
        istudio::graphic::Text::drawText(_font, "SOUND VOLUME", 800, 600, 100, istudio::graphic::Color(255, 255, 255));
        istudio::graphic::Text::drawText(_font, std::to_string((int)(istudio::IndieStudio::soundVolume * 10)), 450, 600, 100, istudio::graphic::Color(255, 255, 255));

        if (!_music.isPlaying()){
            _music.play();
        }
        _music.setVolume(istudio::IndieStudio::musicVolume);
        win.audio.setMasterVolume(istudio::IndieStudio::masterVolume);
        _music.update();
        if (_plus_master.update() && istudio::IndieStudio::masterVolume < 1.0) {
            istudio::IndieStudio::masterVolume += 0.1;
            _click.play();
        }
        if (_minus_master.update() && istudio::IndieStudio::masterVolume > 0.0) {
            istudio::IndieStudio::masterVolume -= 0.1;
            _click.play();
        }

        if (_plus_music.update() && istudio::IndieStudio::musicVolume < 10) {
            istudio::IndieStudio::musicVolume += 1;
            _click.play();
        }
        if (_minus_music.update() &&istudio::IndieStudio::musicVolume >  0) {
            istudio::IndieStudio::musicVolume -= 1;
            _click.play();
        }

        if (_plus_sound.update() && istudio::IndieStudio::soundVolume < 10) {
            istudio::IndieStudio::soundVolume += 1;
            _click.setVolume(istudio::IndieStudio::soundVolume);
            _click.play();
        }
        if (_minus_sound.update() && istudio::IndieStudio::soundVolume > 0) {
            istudio::IndieStudio::soundVolume -= 1;
            _click.setVolume(istudio::IndieStudio::soundVolume);
            _click.play();
        }

        if (_back.update())
            istudio::IndieStudio::getScenes() << istudio::IndieStudio::getScenes().getLast();
        if (_quit.update())
            return (1);
        return (0);
    }

    void SettingScene::unload()
    {
        if (!_isLoaded) return;
        _font.unload();
        _back.unload();
        _quit.unload();
        _plus_master.unload();
        _minus_master.unload();
        _plus_music.unload();
        _minus_music.unload();
        _plus_sound.unload();
        _minus_sound.unload();
        _background.unload();
        _click.unload();
        _music.unload();
        _isLoaded = false;
    }

    void SettingScene::load()
    {
        _isLoaded = true;
        _font.load("./assets/miscs/game.ttf");
        _back.load("./assets/images/left_arrow.png", istudio::math::Vector2(100, 800), 1, 3);
        _quit.load("./assets/images/quit_button.png", istudio::math::Vector2(1600, 900), 1, 3);
        _plus_master.load("./assets/images/plus.png", istudio::math::Vector2(300, 300), 1);
        _minus_master.load("./assets/images/minus.png", istudio::math::Vector2(600, 300), 1);
        _plus_music.load("./assets/images/plus.png", istudio::math::Vector2(300, 450), 1);
        _minus_music.load("./assets/images/minus.png", istudio::math::Vector2(600, 450), 1);
        _plus_sound.load("./assets/images/plus.png", istudio::math::Vector2(300, 600), 1);
        _minus_sound.load("./assets/images/minus.png", istudio::math::Vector2(600, 600), 1);
        _background.load("./assets/images/wallpaper.png");
        _click.load("./assets/audio/click.mp3");
        _click.setVolume(istudio::IndieStudio::soundVolume);
        _music.load("./assets/audio/menu.mp3");
        _music.setVolume(istudio::IndieStudio::musicVolume);
    }
}
