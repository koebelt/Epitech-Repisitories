/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IndieStudio
*/

#include "IndieStudio.hpp"
#include "game/system/entities/EntityAI.hpp"

#include "./game/scenes/GameScene.hpp"
#include "./game/scenes/MenuScene.hpp"
#include "./game/scenes/TutoScene.hpp"
#include "./game/scenes/SettingScene.hpp"
#include "./game/scenes/PreGameScene.hpp"
#include "./game/managers/EntityManager.hpp"
#include "./game/utils/Matrix.hpp"

//#include "./tools/NCurses.hpp"

#include <iostream>

void istudio::IndieStudio::IndieStudio::init()
{
    _sceneManager << std::make_unique<GameScene>();
    _sceneManager << std::make_unique<MenuScene>();
    _sceneManager << std::make_unique<SettingScene>();
    _sceneManager << std::make_unique<PreGameScene>();
    _sceneManager << std::make_unique<TutoScene>();
    _sceneManager << istudio::Scene::MENU;
    start();
}

void istudio::IndieStudio::start()
{
    istudio::Window window(1920, 1080, "Let's Bomb us!");
    window.audio.setMasterVolume(masterVolume);
    istudio::Time::setTargetFPS(60);
    _sceneManager->load();
    while(!window.shouldClose()) {
        _sceneManager->eventScene(window);
        window.clearBackground(istudio::graphic::Color(255, 255, 255));
        window.beginDrawing();
        if (_sceneManager->renderScene(window))
            break;
        window.endDrawing();
    }
}