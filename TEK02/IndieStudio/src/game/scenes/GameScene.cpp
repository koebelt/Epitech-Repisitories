/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** GameScene
*/

#include "GameScene.hpp"

#include "../system/entities/EntityPlayer.hpp"
#include "../system/entities/EntityAI.hpp"
#include "../IndieStudio.hpp"
#include "../utils/References.hpp"
#include "../system/items/bombs/SpawnableBomb.hpp"
#include "../algorithms/patterns/Pattern.hpp"
#include "./PreGameScene.hpp"
#include <iostream>

istudio::GameScene::GameScene() :
    _matrix(IndieStudio::getMatrix())
{
};

//Models

void istudio::GameScene::unload()
{
    _skybox.unload();
    _floor.unload();
    _player1.unload();
    _player2.unload();
    _player3.unload();
    _player4.unload();
    _player1Idle.unload();
    _player2Idle.unload();
    _player3Idle.unload();
    _player4Idle.unload();
    _crate.unload();
    _stone.unload();
    _bomb.unload();
    _explosion.unload();
    _powerBomb.unload();
    _powerFire.unload();
    _sound.unload();
    _powerWall.unload();
    _powerSpeed.unload();
    _quit.unload();
    _font.unload();
    _music.unload();
    _pauseBg.unload();
    _pauseButton.unload();
    _resumeButton.unload();
    _settings.unload();
    _quitPause.unload();
    _loadingBg.unload();
    _manager.clear();
}

void istudio::GameScene::load()
{
    _loading = 0.0;
    _isEnded = false;

    _loadingBg.load("./assets/images/loading_screen.png");
    _matrix = Matrix(PreGameScene::size, PreGameScene::size);

    Pattern::fillMapWithPatterns(_matrix);
    Pattern::fillBreakableWall(_matrix);

    _camera = istudio::graphic::Camera(istudio::math::Vector3(_matrix.getCols() / 2, (_matrix.getRows() + _matrix.getCols()) / 1.3, _matrix.getRows() / 2 + 10), istudio::math::Vector3(_matrix.getCols() / 2, 0.0f, _matrix.getRows() / 2), istudio::math::Vector3(0.0f, 1.0f, 0.0f), 45.0f, CAMERA_PERSPECTIVE);
    int nbPlayers = References::nbPlayers;

    auto addIA = [=](graphic::AnimatedModel *model, graphic::Model *idle, VectorF pos) { _manager << std::make_shared<EntityAI>(model, idle, pos); };
    auto addPlayer = [=](graphic::AnimatedModel *model, graphic::Model *idle, VectorF pos, std::vector<int> key) { _manager << std::make_shared<EntityPlayer>(model, idle, pos, key); };

    if (PreGameScene::typeIT != 2)
        (PreGameScene::typeIT ? addIA(&_player1, &_player1Idle, VectorF(0, 0)) : addPlayer(&_player1, &_player1Idle, VectorF(0, 0), {event::Q, event::Z, event::D, event::S, event::E}));
    if (PreGameScene::typeIT2 != 2)
        (PreGameScene::typeIT2 ? addIA(&_player2, &_player2Idle, VectorF(0, _matrix.getRows() - 1)) : addPlayer(&_player2, &_player2Idle, VectorF(0, _matrix.getRows() - 1), {event::F, event::T, event::H, event::G, event::Y}));
    if (PreGameScene::typeIT3 != 2)
        (PreGameScene::typeIT3 ? addIA(&_player3, &_player3Idle, VectorF(_matrix.getCols() - 1, 0)) : addPlayer(&_player3, &_player3Idle, VectorF(_matrix.getCols() - 1, 0), {event::J, event::I, event::L, event::K, event::O}));
    if (PreGameScene::typeIT4 != 2)
        (PreGameScene::typeIT4 ? addIA(&_player4, &_player4Idle, VectorF(_matrix.getCols() - 1, _matrix.getRows() - 1)) : addPlayer(&_player4, &_player4Idle, VectorF(_matrix.getCols() - 1, _matrix.getRows() - 1), {event::LEFT_ARROW, event::UP_ARROW, event::RIGHT_ARROW, event::DOWN_ARROW, event::B}));
}

int istudio::GameScene::eventScene(istudio::Window &win)
{
    if (static_cast<int>(_loading) < 100) return (0);
    auto entities = *_manager.collect<EntityLiving>([](EntityLiving *e) {
        return !e->isDead();
    });
    if (entities.size() <= 1 && !_isEnded) {
        _isEnded = true;
        if (entities.size() > 0) {
            istudio::VectorF pos = entities.front()->getPosition();
            _camera = istudio::graphic::Camera(istudio::math::Vector3(pos.getX() + 3, 5, pos.getY() + 3), istudio::math::Vector3(pos.getX(), 0, pos.getY()));
        } else {
            _camera = istudio::graphic::Camera(istudio::math::Vector3(istudio::IndieStudio::getMatrix().getCols() / 2 + 4, 5, istudio::IndieStudio::getMatrix().getRows() / 2 + 4), istudio::math::Vector3(istudio::IndieStudio::getMatrix().getCols() / 2, 0, istudio::IndieStudio::getMatrix().getRows() / 2));
        }
        _camera.setMode(CAMERA_ORBITAL);
        return (0);
    }
    auto players = *_manager.collect<EntityPlayer>();
    if (players.size() == 0) return (0);
    if (!_isEnded && !_isPaused)
        for (auto it = players.begin(); it != players.end(); it++) {
            auto vec = (*it)->getKeys(); int i = 0;
            for (auto it2 = vec.begin(); it2 != vec.end(); it2++, i++) {
                if (win.keyboard.isKeyPressed(*it2)) {
                    (*it)->handle(i);
                    break;
                }
            }
        }
    return (0);
}

int istudio::GameScene::renderScene(istudio::Window &win)
{
    if (static_cast<int>(_loading) < 100) {
        if (_loading == 0)
            _skybox.load("./assets/images/skybox_space.png");
        else if (static_cast<int>(_loading) == 3)
            _floor.load(istudio::graphic::Mesh::genPlane(1, 1, 1, 1), "./assets/images/metal_texture.png");
        else if (static_cast<int>(_loading) == 7)
            _player1.load("./assets/models/amongus.iqm", "./assets/images/red_amogus.png", "./assets/models/amongus.iqm", 1);
        else if (static_cast<int>(_loading) == 11)
            _player2.load("./assets/models/amongus.iqm", "./assets/images/green_amogus.png", "./assets/models/amongus.iqm", 1);
        else if (static_cast<int>(_loading) == 14)
            _player3.load("./assets/models/amongus.iqm", "./assets/images/yellow_amogus.png", "./assets/models/amongus.iqm", 1);
        else if (static_cast<int>(_loading) == 18)
            _player4.load("./assets/models/amongus.iqm", "./assets/images/cyan_amogus.png", "./assets/models/amongus.iqm", 1);
        else if (static_cast<int>(_loading) == 22)
            _player1Idle.load("./assets/models/amogus.obj", "./assets/images/red_amogus.png");
        else if (static_cast<int>(_loading) == 25)
            _player2Idle.load("./assets/models/amogus.obj", "./assets/images/green_amogus.png");
        else if (static_cast<int>(_loading) == 29)
            _player3Idle.load("./assets/models/amogus.obj", "./assets/images/yellow_amogus.png");
        else if (static_cast<int>(_loading) == 33)
            _player4Idle.load("./assets/models/amogus.obj", "./assets/images/cyan_amogus.png");
        else if (static_cast<int>(_loading) == 37)
            _crate.load(istudio::graphic::Mesh::genCube(1, 1, 1), "./assets/images/crate.png");
        else if (static_cast<int>(_loading) == 40)
            _stone.load("./assets/models/stone.gltf", "./assets/images/stone.png");
        else if (static_cast<int>(_loading) == 44)
            _bomb.load("./assets/models/bomb.glb", "./assets/images/bombe.png");
        else if (static_cast<int>(_loading) == 48)
            _explosion.load("./assets/models/explosion.gltf", "./assets/images/flame.png");
        else if (static_cast<int>(_loading) == 51)
            _powerBomb.load("./assets/models/bomb.glb", "./assets/images/bomb_up.png");
        else if (static_cast<int>(_loading) == 55)
            _powerFire.load("./assets/models/bomb.glb", "./assets/images/fire_up.png");
        else if (static_cast<int>(_loading) == 59)
            _sound.load("./assets/audio/bomb.mp3");
        else if (static_cast<int>(_loading) == 62)
            _powerWall.load(istudio::graphic::Mesh::genCube(1, 1, 1), "./assets/images/wall_pass.png");
        else if (static_cast<int>(_loading) == 66)
            _powerSpeed.load(istudio::graphic::Mesh::genCube(1, 1, 1), "./assets/images/speed_up.png");
        else if (static_cast<int>(_loading) == 70)
            _quit.load("./assets/images/quit_button.png", istudio::math::Vector2(850, 800), 1, 3);
        else if (static_cast<int>(_loading) == 74)
            _font.load("./assets/miscs/game.ttf");
        else if (static_cast<int>(_loading) == 77) {
            _music.load("./assets/audio/game.mp3");
            _music.setVolume(istudio::IndieStudio::musicVolume);
        } else if (static_cast<int>(_loading) == 81)
            _pauseBg.load("./assets/images/pause_menu.png");
        else if (static_cast<int>(_loading) == 85)
            _pauseButton.load("./assets/images/pause_button.png", istudio::math::Vector2(1850, 10), 0.4, 3);
        else if (static_cast<int>(_loading) == 88)
            _resumeButton.load("./assets/images/resume_button.png", istudio::math::Vector2(810, 330), 1, 3);
        else if (static_cast<int>(_loading) == 92)
            _settings.load("./assets/images/settings_button.png", istudio::math::Vector2(810, 540), 1, 3);
        else if (static_cast<int>(_loading) == 96)
            _quitPause.load("./assets/images/quit_button.png", istudio::math::Vector2(860, 750), 1, 3);
        _loading = (static_cast<int>(_loading) == 96) ? 100 : _loading + 3.7;
        _loadingBg.draw(math::Vector2(0, 0), istudio::graphic::Color(255, 255, 255));
        graphic::Text::drawText(std::to_string(_loading).substr(0, 4) + "%", 900, 800, 32, istudio::graphic::Color(255, 255, 255));
        return (0);
    }
    if (!_isEnded && !_isPaused) {
        _camera.setMode(CAMERA_FREE);
        _manager.update();
    }
    _music.setVolume(istudio::IndieStudio::musicVolume);
    if (!_music.isPlaying())
        _music.play();
    _music.update();
    _camera.update();
    win.clearBackground(istudio::graphic::Color(255, 255, 255));
    win.drawCamera(_camera);
    _skybox.draw();
    for (int i = 0; i < _matrix.getRows(); i++) {
        for (int j = 0; j < _matrix.getCols(); j++) {
            _floor.draw(istudio::math::Vector3(j, 0, i), 1, istudio::graphic::Color(255, 255, 255));
            auto FireOnPos = *_manager.collect<ItemEntity<FireResidue>>([&i, &j](ItemEntity<FireResidue> *e) -> bool { return (e->getEntity().getPosition() == VectorF(j, i)); });
            switch(_matrix(i, j)) {
                case('#'):
                    _crate.draw(istudio::math::Vector3(j, 0.36, i), 0.7, FireOnPos.size() > 0 ? istudio::graphic::Color(255, 0, 0) : istudio::graphic::Color(255, 255, 255));
                    break;
                case('1'): _stone.draw(istudio::math::Vector3(j, 0.36, i), 0.7, istudio::graphic::Color(255, 255, 255));
                    break;
            }
        }
    }
    _manager.draw();

    win.endDrawCamera();

    if (_isPaused) {
        _pauseBg.draw(istudio::math::Vector2(650, 150), 0, 0.8, istudio::graphic::Color(255, 255, 255));
        if (_resumeButton.update())
            _isPaused = false;
        if (_settings.update())
            istudio::IndieStudio::getScenes().loadAndKeepLast(SETTING);
        if (_quitPause.update()) {
            _isPaused = false;
            istudio::IndieStudio::getScenes().load(MENU);
            return 0;
        }
    } else
        if (!_isEnded && _pauseButton.update())
            _isPaused = true;
    if (_isEnded) {
        auto entities = *_manager.collect<EntityLiving>([](EntityLiving *e) {
            return !e->isDead();
        });
        if (entities.size() > 0)
            istudio::graphic::Text::drawText(_font, "Congratulation, You win!", 630, 200, 100,istudio::graphic::Color(255, 255, 255));
        else
            istudio::graphic::Text::drawText(_font, "Equality, no one wins!", 630, 200, 100, istudio::graphic::Color(255, 255, 255));
        if (_quit.update())
            istudio::IndieStudio::getScenes().load(MENU);
    }
    istudio::graphic::Text::drawFPS(0, 0);
    return (0);
}