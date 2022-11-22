/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** PreGameScene
*/

#include "PreGameScene.hpp"
#include "../../IndieStudio.hpp"

namespace istudio {
    int PreGameScene::renderScene(istudio::Window &win)
    {
        _background.draw(istudio::math::Vector2(0, 0), istudio::graphic::Color(255, 255, 255));
        _music.setVolume(istudio::IndieStudio::musicVolume);
        if (!_music.isPlaying())
            _music.play();
        _music.update();

        if (typeIT > 0 && _arrowLeftType.update())
            typeIT --;
        if (typeIT < 2 && _arrowRightType.update())
            typeIT++;
        istudio::graphic::Text::drawText(_font, _typeList[typeIT], 280, 100, 50, istudio::graphic::Color(255, 255, 255));
        if (typeIT != 2) {
            _skinList.draw(istudio::math::Vector2(260, 160), 0, 0, 0.5, istudio::graphic::Color(255, 255, 255, 255));
            istudio::graphic::Text::drawText(_font, "N°1", 280, 300, 50, istudio::graphic::Color(255, 255, 255));
        } if (typeIT == 0)
            _controls_player_one.draw(istudio::math::Vector2(0, 280), 0, 0.9, istudio::graphic::Color(255, 255, 255));

        if (typeIT2 > 0 && _arrowLeftType2.update())
            typeIT2 --;
        if (typeIT2 < 2 && _arrowRightType2.update())
            typeIT2++;
        istudio::graphic::Text::drawText(_font, _typeList[typeIT2], 280, 600, 50, istudio::graphic::Color(255, 255, 255));
        if (typeIT2 != 2) {
            _skinList.draw(istudio::math::Vector2(260, 660), 0, 1, 0.5, istudio::graphic::Color(255, 255, 255, 255));
            istudio::graphic::Text::drawText(_font, "N°2", 280, 800, 50, istudio::graphic::Color(255, 255, 255));
        }
        if (typeIT2 == 0)
            _controls_player_two.draw(istudio::math::Vector2(0, 780), 0, 0.9, istudio::graphic::Color(255, 255, 255));

        if (typeIT3 > 0 && _arrowLeftType3.update())
            typeIT3 --;
        if (typeIT3 < 2 && _arrowRightType3.update())
            typeIT3++;
        istudio::graphic::Text::drawText(_font, _typeList[typeIT3], 980, 100, 50, istudio::graphic::Color(255, 255, 255));
        if (typeIT3 != 2) {
            _skinList.draw(istudio::math::Vector2(960, 160), 0, 2, 0.5, istudio::graphic::Color(255, 255, 255, 255));
            istudio::graphic::Text::drawText(_font, "N°3", 980, 300, 50, istudio::graphic::Color(255, 255, 255));
        }
        if (typeIT3 == 0)
            _controls_player_three.draw(istudio::math::Vector2(700, 280), 0, 0.9, istudio::graphic::Color(255, 255, 255));

        if (typeIT4 > 0 && _arrowLeftType4.update())
            typeIT4 --;
        if (typeIT4 < 2 && _arrowRightType4.update())
            typeIT4++;
        istudio::graphic::Text::drawText(_font, _typeList[typeIT4], 980, 600, 50, istudio::graphic::Color(255, 255, 255));
        if (typeIT4 != 2) {
            _skinList.draw(istudio::math::Vector2(960, 660), 0, 3, 0.5, istudio::graphic::Color(255, 255, 255, 255));
            istudio::graphic::Text::drawText(_font, "N°4", 980, 800, 50, istudio::graphic::Color(255, 255, 255));
        }
        if (typeIT4 == 0)
            _controls_player_four.draw(istudio::math::Vector2(700, 780), 0, 0.9, istudio::graphic::Color(255, 255, 255));

        if (_back.update())
            istudio::IndieStudio::getScenes().llast();
        istudio::graphic::Text::drawText(_font, "Map Size", 1590, 200, 100, istudio::graphic::Color(255, 255, 255));
        if (size > 13 && _arrowLeftSize.update()) size--;
        if (size < 20 && _arrowRightSize.update()) size++;
        istudio::graphic::Text::drawText(_font, std::to_string(size), 1690, 450, 75, istudio::graphic::Color(255, 255, 255));
        if (_play.update())
            istudio::IndieStudio::getScenes().load(istudio::Scene::GAME);
        return (0);
    }

    void PreGameScene::unload()
    {
        if (!_isLoaded) return;
        _font.unload();
        _background.unload();
        _skinList.unload();
        _arrowLeftType.unload();
        _arrowRightType.unload();
        _arrowLeftType2.unload();
        _arrowRightType2.unload();
        _arrowLeftType3.unload();
        _arrowRightType3.unload();
        _arrowLeftType4.unload();
        _arrowRightType4.unload();
        _arrowLeftSize.unload();
        _arrowRightSize.unload();
        _back.unload();
        _play.unload();
        _controls_player_one.unload();
        _controls_player_two.unload();
        _controls_player_three.unload();
        _controls_player_four.unload();
        _music.unload();
        _isLoaded = false;
    }

    void PreGameScene::load()
    {
        _isLoaded = true;
        _font.load("./assets/miscs/game.ttf");
        _background.load("./assets/images/wallpaper.png");
        _skinList.load("./assets/images/player_select.png", 4, 1);
        _arrowLeftType.load("./assets/images/left_arrow.png", istudio::math::Vector2(200, 100), 0.5, 3);
        _arrowRightType.load("./assets/images/right_arrow.png", istudio::math::Vector2(400, 100), 0.5, 3);
        _arrowLeftType2.load("./assets/images/left_arrow.png", istudio::math::Vector2(200, 600), 0.5, 3);
        _arrowRightType2.load("./assets/images/right_arrow.png", istudio::math::Vector2(400, 600), 0.5, 3);
        _arrowLeftType3.load("./assets/images/left_arrow.png", istudio::math::Vector2(900, 100), 0.5, 3);
        _arrowRightType3.load("./assets/images/right_arrow.png", istudio::math::Vector2(1100, 100), 0.5, 3);
        _arrowLeftType4.load("./assets/images/left_arrow.png", istudio::math::Vector2(900, 600), 0.5, 3);
        _arrowRightType4.load("./assets/images/right_arrow.png", istudio::math::Vector2(1100, 600), 0.5, 3);
        _arrowLeftSize.load("./assets/images/left_arrow.png", istudio::math::Vector2(1600, 450), 0.7, 3);
        _arrowRightSize.load("./assets/images/right_arrow.png", istudio::math::Vector2(1750, 450), 0.7, 3);
        _back.load("./assets/images/left_arrow.png", istudio::math::Vector2(20, 10), 1, 3);
        _play.load("./assets/images/continue_button.png", istudio::math::Vector2(1550, 880), 1.2, 3);
        _controls_player_one.load("./assets/images/player_one.png");
        _controls_player_two.load("./assets/images/player_two.png");
        _controls_player_three.load("./assets/images/player_three.png");
        _controls_player_four.load("./assets/images/player_four.png");
        _music.load("./assets/audio/menu.mp3");
        _music.setVolume(istudio::IndieStudio::musicVolume);
    }
}