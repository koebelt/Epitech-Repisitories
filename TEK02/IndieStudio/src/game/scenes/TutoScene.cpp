/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** TutoScene
*/

#include "TutoScene.hpp"

#include "../system/entities/EntityPlayer.hpp"
#include "../system/entities/EntityAI.hpp"
#include "../IndieStudio.hpp"
#include "../utils/References.hpp"
#include "../system/items/bombs/SpawnableBomb.hpp"
#include "../algorithms/patterns/Pattern.hpp"
#include "./PreGameScene.hpp"
#include <iostream>

namespace istudio {

    istudio::TutoScene::TutoScene() :
    _matrix(IndieStudio::getMatrix())
{
};

    void TutoScene::load()
    {
        _skybox.load("./assets/images/skybox_space.png");
        _floor.load(istudio::graphic::Mesh::genPlane(1, 1, 1, 1), "./assets/images/metal_texture.png");
        _player1.load("./assets/models/amongus.iqm", "./assets/images/red_amogus.png", "./assets/models/amongus.iqm", 1);
        _player2.load("./assets/models/amongus.iqm", "./assets/images/green_amogus.png", "./assets/models/amongus.iqm", 1);
        _player1Idle.load("./assets/models/amogus.obj", "./assets/images/red_amogus.png");
        _player2Idle.load("./assets/models/amogus.obj", "./assets/images/green_amogus.png");
        _crate.load(istudio::graphic::Mesh::genCube(1, 1, 1), "./assets/images/crate.png");
        _stone.load("./assets/models/stone.gltf", "./assets/images/stone.png");
        _ia.load("./assets/models/amogus.obj", "./assets/images/red_amogus.png");
        _bomb.load("./assets/models/bomb.glb", "./assets/images/bombe.png");
        _explosion.load("./assets/models/explosion.gltf", "./assets/images/flame.png");
        _powerBomb.load("./assets/models/bomb.glb", "./assets/images/bomb_up.png");
        _powerFire.load("./assets/models/bomb.glb", "./assets/images/fire_up.png");
        _powerWall.load(istudio::graphic::Mesh::genCube(1, 1, 1), "./assets/images/wall_pass.png");
        _powerSpeed.load(istudio::graphic::Mesh::genCube(1, 1, 1), "./assets/images/speed_up.png");
        _stickBase.load("./assets/images/tuto_player.png", 1, 1);
        _stickPoint.load("./assets/images/tuto_player_pointing.png", 1, 1);
        _stickBomb.load("./assets/images/tuto_player_bomb.png", 1, 1);
        _pauseBg.load("./assets/images/pause_menu.png");
        _pauseButton.load("./assets/images/pause_button.png", istudio::math::Vector2(1850, 10), 0.4, 3);
        _resumeButton.load("./assets/images/resume_button.png", istudio::math::Vector2(810, 330), 1, 3);
        _settings.load("./assets/images/settings_button.png", istudio::math::Vector2(810, 540), 1, 3);
        _quitPause.load("./assets/images/quit_button.png", istudio::math::Vector2(860, 750), 1, 3);

        _dialog.push_back("Hi ! I'm bob and welcome to our game : Let's Bomb Us!");
        _dialog.push_back("Let's start with an explanation of what you'll find in our game.");
        _dialog.push_back("You see this little red thing ? It's you.");
        _dialog.push_back("And this green guy here is the bad guy.");
        _dialog.push_back("You have one mission, destroy him !");
        _dialog.push_back("To do this, you are equipped with an amazing weapon...");
        _dialog.push_back("A bomb !");
        _dialog.push_back("Press E to drop one.");
        _dialog.push_back("You have an infinite number of bombs but you can only place one at a time.");
        _dialog.push_back("But those bombs aren't only for destroying bad guys !");
        _dialog.push_back("You can also use them to explode crates.");
        _dialog.push_back("See this one ? You can place a bomb next to it and it will break !");
        _dialog.push_back("But watch out ! You cannot destroy those rocks !");
        _dialog.push_back("The map is divided into squares, you can move around by using Z Q S D.");
        _dialog.push_back("Go on ! Move to that crate and make it explode !");
        _dialog.push_back("But proceed with caution, our bombs have an explosion radius of the squares in all directions !");
        _dialog.push_back("Try not to kill yourself...");
        _dialog.push_back("");
        _dialog.push_back("Great job ! If you're lucky you may have droped a bonus.");
        _dialog.push_back("If not, here are all of the available bonuses in the game.");
        _dialog.push_back("In order from left to right and top to bottom.");
        _dialog.push_back("The first is bombUp, it allow you to place one more bomb at the same time.");
        _dialog.push_back("The second is fireUp, it increases the power of your bombs by one.");
        _dialog.push_back("The third is speedUp, it increases your speed.");
        _dialog.push_back("The last is wallPass. When you pick it up you can go through walls !");
        _dialog.push_back("Now that you know more about the game, let's continue !");
        _dialog.push_back("The next step of this tutorial is to kill the ennemy.");
        _dialog.push_back("Go on ! And remember, don't kill yourself ");
        _dialog.push_back("");
        _dialog.push_back("Well you'vd done it ! I think you are ready to enjoy our game !");
        _dialog.push_back("Hope you like it !");

        _textBox.load("./assets/images/text_card.png", 1, 1, 20, istudio::graphic::Color(255, 255, 255), _dialog.front());

        _matrix = Matrix(10, 5);
        _matrix(0, 0) = '#';
        _matrix(0, 1) = '#';
        _matrix(0, 2) = '#';
        _matrix(0, 3) = '#';
        _matrix(0, 4) = '#';
        _matrix(1, 0) = '#';
        _matrix(1, 4) = '#';
        _matrix(2, 0) = '#';
        _matrix(2, 4) = '#';
        _matrix(3, 0) = '#';
        _matrix(3, 4) = '#';
        _matrix(6, 0) = '1';
        _matrix(6, 1) = '1';
        _matrix(6, 2) = '#';
        _matrix(6, 3) = '1';
        _matrix(6, 4) = '1';
        _matrix(7, 0) = '1';
        _matrix(7, 1) = '1';
        _matrix(7, 3) = '1';
        _matrix(7, 4) = '1';

        _camera = istudio::graphic::Camera(istudio::math::Vector3(_matrix.getCols() / 2, (_matrix.getRows() + _matrix.getCols()) / 1.3, _matrix.getRows() / 2 + 10), istudio::math::Vector3(_matrix.getCols() / 2, 0.0f, _matrix.getRows() / 2), istudio::math::Vector3(0.0f, 1.0f, 0.0f), 45.0f, CAMERA_PERSPECTIVE);

        auto addPlayer = [=](graphic::AnimatedModel *model, graphic::Model *idle, VectorF pos, std::vector<int> key) { _manager << std::make_shared<EntityPlayer>(model, idle, pos, key); };

        addPlayer(&_player1, &_player1Idle, VectorF(2, 9), {event::Q, event::Z, event::D, event::S, event::E});
        addPlayer(&_player2, &_player2Idle, VectorF(2, 2), {337, 377, 377, 377, 337});

        _isTalking = 1;
        _isCrateDestroyed = 0;
    }

    void TutoScene::unload()
    {
        _skybox.unload();
        _floor.unload();
        _player1.unload();
        _player1Idle.unload();
        _player2.unload();
        _player2Idle.unload();
        _powerBomb.unload();
        _powerFire.unload();
        _powerWall.unload();
        _powerSpeed.unload();
        _crate.unload();
        _stone.unload();
        _ia.unload();
        _manager.clear();
        _bomb.unload();
        _explosion.unload();
        _stickBase.unload();
        _stickBomb.unload();
        _stickPoint.unload();
        _textBox.unload();
        _pauseBg.unload();
        _pauseButton.unload();
        _resumeButton.unload();
        _settings.unload();
        _quitPause.unload();
        _dialog.clear();
    }

    int TutoScene::eventScene(istudio::Window &win)
    {
        if (_isPaused)
            return (0);
        _textBox.update();
        auto entities = _manager.collect<EntityLiving>().hasVector();
        if (_dialog.front() == "Hope you like it !" && win.keyboard.isKeyPressed(event::SPACE)) {
            istudio::IndieStudio::getScenes().load(MENU);
            return (0);
        }
        if (_matrix(6, 2) == '0' && _isCrateDestroyed == 0) {
            _isCrateDestroyed = 1;
            _isTalking = 3;
        }
        if (_isTalking == 2) {
            if (win.keyboard.isKeyPressed(event::SPACE)) {
                _isTalking = 0;
                entities[0]->setDead(false);
                entities[1]->setDead(false);
            }
        } else {
            if (win.keyboard.isKeyPressed(event::SPACE) && _dialog.front() != "") {
                _dialog.pop_front();
                _textBox.setText(_dialog.front());
            } else if (_dialog.front() == "" && _isTalking == 3) {
                _dialog.pop_front();
                _textBox.setText(_dialog.front());
                _isTalking = 1;
            }
            if (_dialog.front() == "")
                _isTalking = 0;
            if (_isTalking == 0) {
                if (entities[0]->isDead()) {
                    _isTalking = 2;
                    _textBox.setText(std::string("Okay that was unexpected. Seems like you need to practice a little more."));
                } else if (entities[1]->isDead()) {
                    _dialog.pop_front();
                    _textBox.setText(_dialog.front());
                    _isTalking = 1;
                }
                auto players = *_manager.collect<EntityPlayer>();
                if (players.size() == 0) return (0);
                for (auto it = players.begin(); it != players.end(); it++) {
                    auto vec = (*it)->getKeys(); int i = 0;
                    for (auto it2 = vec.begin(); it2 != vec.end(); it2++, i++) {
                        if (win.keyboard.isKeyPressed(*it2)) {
                            (*it)->handle(i);
                            break;
                        }
                    }
                }
            }
        }
        return (0);
    }

    int TutoScene::renderScene(istudio::Window &win)
    {
        if (!_isPaused) {
            _camera.setMode(CAMERA_FREE);
            _camera.update();
            _manager.update();
        }
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
        if ((_isTalking &&_dialog.front() == "If not, here are all of the available bonuses in the game.") || (_isTalking && _dialog.front() == "In order from left to right and top to bottom.")) {
            _floor.draw(istudio::math::Vector3(7, 0, 6), 1, istudio::graphic::Color(255, 255, 255));
            _floor.draw(istudio::math::Vector3(8, 0, 6), 1, istudio::graphic::Color(255, 255, 255));
            _floor.draw(istudio::math::Vector3(7, 0, 5), 1, istudio::graphic::Color(255, 255, 255));
            _floor.draw(istudio::math::Vector3(8, 0, 5), 1, istudio::graphic::Color(255, 255, 255));
            _powerBomb.draw(istudio::math::Vector3(7, 0.2, 5), 0.2, istudio::graphic::Color(255, 255, 255));
            _powerFire.draw(istudio::math::Vector3(8, 0.2, 5), 0.2, istudio::graphic::Color(255, 255, 255));
            _powerSpeed.draw(istudio::math::Vector3(7, 0.2, 6), istudio::math::Vector3(0, 1, 0), 180, istudio::math::Vector3(0.4, 0.4, 0.4), istudio::graphic::Color(255, 255, 255));
            _powerWall.draw(istudio::math::Vector3(8, 0.2, 6), istudio::math::Vector3(0, 1, 0), 180, istudio::math::Vector3(0.4, 0.4, 0.4), istudio::graphic::Color(255, 255, 255));
        } if (_isTalking && _dialog.front() == "The first is bombUp, it allow you to place one more bomb at the same time.") {
             _floor.draw(istudio::math::Vector3(7, 0, 5), 1, istudio::graphic::Color(255, 255, 255));
              _powerBomb.draw(istudio::math::Vector3(7, 0.2, 5), 0.2, istudio::graphic::Color(255, 255, 255));
        } if (_isTalking && _dialog.front() == "The second is fireUp, it increases the power of your bombs by one.") {
            _floor.draw(istudio::math::Vector3(8, 0, 5), 1, istudio::graphic::Color(255, 255, 255));
            _powerFire.draw(istudio::math::Vector3(8, 0.2, 5), 0.2, istudio::graphic::Color(255, 255, 255));
        } if (_isTalking && _dialog.front() == "The third is speedUp, it increases your speed.") {
            _floor.draw(istudio::math::Vector3(7, 0, 6), 1, istudio::graphic::Color(255, 255, 255));
            _powerSpeed.draw(istudio::math::Vector3(7, 0.2, 6), istudio::math::Vector3(0, 1, 0), 180, istudio::math::Vector3(0.4, 0.4, 0.4), istudio::graphic::Color(255, 255, 255));
        } if (_isTalking && _dialog.front() == "The last is wallPass. When you pick it up you can go through walls !") {
            _floor.draw(istudio::math::Vector3(8, 0, 6), 1, istudio::graphic::Color(255, 255, 255));
            _powerWall.draw(istudio::math::Vector3(8, 0.2, 6), istudio::math::Vector3(0, 1, 0), 180, istudio::math::Vector3(0.4, 0.4, 0.4), istudio::graphic::Color(255, 255, 255));
        }
        win.endDrawCamera();
        if (_isTalking == 1) {
            istudio::graphic::Text::drawText("Press SPACE to skip the dialog", 120, 340, 20, istudio::graphic::Color(255, 255, 255));
            _textBox.draw(istudio::math::Vector2(0, 200), 0.7f, istudio::graphic::Color(255, 255, 255), 0.05, 0.3, 45);
            if (_dialog.front() == "You see this little red thing ? It's you.")
                _stickPoint.draw(istudio::math::Vector2(460, 570), 1, istudio::graphic::Color(255, 255, 255));
            else if (_dialog.front() == "And this green guy here is the bad guy.")
                _stickPoint.draw(istudio::math::Vector2(460, 80), 1, istudio::graphic::Color(255, 255, 255));
            else if (_dialog.front() == "A bomb !")
                _stickBomb.draw(istudio::math::Vector2(60, 360), 1, istudio::graphic::Color(255, 255, 255));
            else if (_dialog.front() == "If not, here are all of the available bonuses in the game.")
                _stickBase.draw(istudio::math::Vector2(30, 360), 1, istudio::graphic::Color(255, 255, 255));
            else
                _stickBase.draw(istudio::math::Vector2(30, 360), 1, istudio::graphic::Color(255, 255, 255));
        } else if (_isTalking == 2) {
            _textBox.draw(istudio::math::Vector2(0, 200), 0.7f, istudio::graphic::Color(255, 255, 255), 0.05, 0.3, 45);
            _stickBase.draw(istudio::math::Vector2(30, 360), 1, istudio::graphic::Color(255, 255, 255));
        } if (_isPaused) {
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
            if (_pauseButton.update())
                _isPaused = true;
        istudio::graphic::Text::drawFPS(0, 0);
        return (0);
    }

}