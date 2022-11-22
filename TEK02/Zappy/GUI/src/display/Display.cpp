/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Display
*/

#include "Display.hpp"


namespace zappy
{
    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class Display constructor
    **/
    Display::Display()
    {
        _window.init(1920, 1080, "Zappy GUI");
        zappy::Time::setTargetFPS(60);
        srand(time(NULL));
    }

    /**
    ** @author : Ethan HUSSER, Thomas KOEBEL
    **
    ** @brief Class loop method
    ** @param listener (zappy::Listener &): Class that listen the server
    **/
    void Display::loop(zappy::Listener &listener)
    {
        int mode = 0;
        zappy::graphic::Camera camera(zappy::math::Vector3(5.0f, 3.0f, 5.0f), zappy::math::Vector3(0.0f, 1.0f, 0.0f), zappy::math::Vector3(0.0f, 1.0f, 0.0f), 45.0f, CAMERA_PERSPECTIVE);
        zappy::Map map;
        zappy::graphic::Billboard bill("./GUI/assets/desert.png");
        zappy::Fruits fruit;
        zappy::graphic::Mesh sphere;
        sphere.genSphere(0.03, 10, 10);
        zappy::graphic::Model fruit_model(sphere);
        zappy::graphic::Mesh square;
        square.genPlane(1, 1, 1, 1);
        zappy::graphic::Model floor_model(square);
        zappy::graphic::Texture floor_texture("./GUI/assets/metal_texture.png");
        zappy::graphic::Mesh square2;
        square2.genPlane(1, 1, 1, 1);
        zappy::graphic::Model broadcast_model(square2);
        zappy::graphic::Texture broadcast_texture("./GUI/assets/broadcast.png");
        zappy::graphic::Mesh square3;
        square3.genPlane(1, 1, 1, 1);
        zappy::graphic::Model evolution_model(square3);
        zappy::graphic::Texture evolution_texture("./GUI/assets/magic_circle.png");
        zappy::graphic::Model trantorian_model("./GUI/assets/amogus.obj");
        zappy::graphic::Texture trantorian_texture("./GUI/assets/amogus.png");
        zappy::graphic::Model egg_model("./GUI/assets/egg.obj");
        zappy::graphic::AnimatedModel walk("./GUI/assets/amongus.iqm", "./GUI/assets/amogus.png", "./GUI/assets/amongus.iqm", 1);
        zappy::graphic::AnimatedModel take("./GUI/assets/amongus.iqm", "./GUI/assets/amogus.png", "./GUI/assets/take.iqm", 1);
        zappy::graphic::Skybox skybox("./GUI/assets/skybox.png");
        zappy::graphic::Texture inventoru_bg("./GUI/assets/text_card.png");
        zappy::graphic::Texture food_texture("./GUI/assets/food.png");
        zappy::graphic::Texture linemate_texture("./GUI/assets/linemate.png");
        zappy::graphic::Texture deraumere_texture("./GUI/assets/deraumere.png");
        zappy::graphic::Texture sibur_texture("./GUI/assets/sibur.png");
        zappy::graphic::Texture mendiane_texture("./GUI/assets/mendiane.png");
        zappy::graphic::Texture phiras_texture("./GUI/assets/phiras.png");
        zappy::graphic::Texture thystame_texture("./GUI/assets/thystame.png");
        std::queue<std::string> queue;
        std::vector<zappy::Team> Teams;

        trantorian_model.setTexture(&trantorian_texture);
        floor_model.setTexture(&floor_texture);
        broadcast_model.setTexture(&broadcast_texture);
        evolution_model.setTexture(&evolution_texture);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                map(i, j) = zappy::Tile({3, 1, 4, 2, 1, 1, 2}, {});
            }
        }

        std::chrono::time_point<std::chrono::system_clock> timeRef = std::chrono::system_clock::now();
        camera.setPosition(zappy::math::Vector3(map.getWidth() / 2, 5.0f, map.getHeight()), zappy::math::Vector3(map.getWidth() / 2, 0.0f, map.getHeight() / 2), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
        camera.setMode(CAMERA_FREE);

        while (!_window.shouldClose())
        {
            zappy::Interpreter::update(listener.getQueue(), map, Teams, _timeUnit, playerIt);
            listener.clearQueue();

            if (_window.keyboard.isKeyPressed(zappy::event::C) && !_isInventory) {
                if (mode == 0) {
                    mode = 1;
                    camera.setPosition(zappy::math::Vector3(map.getWidth(), 8.0f, map.getHeight()), zappy::math::Vector3(map.getWidth() / 2, 0.0f, map.getHeight() / 2), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
                    camera.setMode(CAMERA_ORBITAL);
                } else {
                    mode = 0;
                    camera.setPosition(zappy::math::Vector3(map.getWidth() / 2, 5.0f, map.getHeight()), zappy::math::Vector3(map.getWidth() / 2, 0.0f, map.getHeight() / 2), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
                    camera.setMode(CAMERA_FREE);
                }
            } if (_window.keyboard.isKeyPressed(zappy::event::I)) {
                if (_isInventory) {
                    _isInventory = false;
                    camera.setPosition(zappy::math::Vector3(map.getWidth() / 2, 5.0f, map.getHeight()), zappy::math::Vector3(map.getWidth() / 2, 0.0f, map.getHeight() / 2), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
                    camera.setMode(CAMERA_FREE);
                } else {
                    _isInventory = true;
                    teamIt = Teams.begin();
                    playerIt = teamIt->getTrantorians().begin();
                    if (!(Teams.begin()->getTrantorians().begin() == Teams.begin()->getTrantorians().end())) {
                        if (playerIt->_isEgg == false)
                            listener.requestPlayerInventory(std::to_string(playerIt->_id));
                        camera.setMode(CAMERA_ORBITAL);
                    }
                }
            } if (_isInventory && _window.keyboard.isKeyPressed(zappy::event::TAB)) {
                if (!(teamIt->getTrantorians().begin() == teamIt->getTrantorians().end())) {
                    playerIt++;
                    if (playerIt == teamIt->getTrantorians().end())
                        playerIt = teamIt->getTrantorians().begin();
                                if (playerIt->_isEgg == false)
                        listener.requestPlayerInventory(std::to_string(playerIt->_id));
                    camera.setMode(CAMERA_ORBITAL);
                }
            } if (_isInventory && _window.keyboard.isKeyPressed(zappy::event::SPACE)) {
                teamIt++;
                if (teamIt == Teams.end())
                    teamIt = Teams.begin();
                playerIt = teamIt->getTrantorians().begin();
                if (!(teamIt->getTrantorians().begin() == teamIt->getTrantorians().end())) {
                    if (playerIt->_isEgg == false)
                        listener.requestPlayerInventory(std::to_string(playerIt->_id));
                    camera.setPosition(zappy::math::Vector3(playerIt->_currentPos.first + 2, 5.0f, playerIt->_currentPos.second + 2), zappy::math::Vector3(playerIt->_currentPos.first + 0.5, 0.0f, playerIt->_currentPos.second + 0.5), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
                    camera.setMode(CAMERA_ORBITAL);
                } else {
                    camera.setPosition(zappy::math::Vector3(map.getWidth() / 2, 5.0f, map.getHeight()), zappy::math::Vector3(map.getWidth() / 2, 0.0f, map.getHeight() / 2), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
                    camera.setMode(CAMERA_FREE);
                }
            } if (_isInventory && _window.keyboard.isKeyPressed(zappy::event::R)) {
                if (!(teamIt->getTrantorians().begin() == teamIt->getTrantorians().end())) {
                    if (playerIt->_isEgg == false)
                        listener.requestPlayerInventory(std::to_string(playerIt->_id));
                }
            }

            camera.update();
            _window.beginDrawing();
            _window.clearBackground(zappy::graphic::Color(255, 255, 255));
            _window.drawCamera(camera);
            skybox.draw();

            for (int i = 0; i < map.getHeight(); i++)
                for (int j = 0; j < map.getWidth(); j++)
                    floor_model.draw(zappy::math::Vector3(j + 0.5, 0, i + 0.5), 1, zappy::graphic::Color(255, 255, 255));
            for (float i = 0; i < map.getHeight(); i++)
                for (float j = 0; j < map.getWidth(); j++)
                    fruit.draw(map(j, i)._fruits, {j, i}, fruit_model);
            for (auto it = Teams.begin(); it != Teams.end(); it++) {
                for (auto it2 = it->getEvolutions().begin(); it2 != it->getEvolutions().end() ; it2++) {
                    it2->first.z += 1;
                    evolution_model.draw(zappy::math::Vector3(it2->first.x + 0.5, 0.01, it2->first.y + 0.5), zappy::math::Vector3(0, 1, 0), it2->first.z, zappy::math::Vector3(1, 1, 1), it->getColor());
                }
                it->draw(trantorian_model, egg_model, walk, broadcast_model, map.getHeight(), map.getWidth(), Teams, _timeUnit);
            }

            _window.endDrawCamera();

            if (listener.getIsServerLost())
                zappy::graphic::Text::drawText("Connection with the server has been lost", 140, 500, 80, zappy::graphic::Color(255, 0, 50));

            if (_isInventory) {
                inventoru_bg.draw(zappy::math::Vector2(120, 750), 0, 2, zappy::graphic::Color(255, 255, 255));

                zappy::graphic::Text::drawText("TAB: to cycle through players of this team      SPACE: to cycle through teams      R: to refresh this player's inventory", 500, 800, 20, zappy::graphic::Color(255, 255, 255));
                zappy::graphic::Text::drawText("Team: " + teamIt->getName(), 200, 860, 20, zappy::graphic::Color(255, 255, 255));
                if (teamIt->getTrantorians().begin() == teamIt->getTrantorians().end()) {
                    zappy::graphic::Text::drawText("There is currently no Players in this team", 400, 900, 30, zappy::graphic::Color(255, 255, 255));
                } else {
                    if (playerIt == teamIt->getTrantorians().end()) {
                        playerIt = teamIt->getTrantorians().begin();
                        if (playerIt->_isEgg == false) {
                            listener.requestPlayerInventory(std::to_string(playerIt->_id));
                        }
                        camera.setPosition(zappy::math::Vector3(playerIt->_currentPos.first + 2, 5.0f, playerIt->_currentPos.second + 2), zappy::math::Vector3(playerIt->_currentPos.first + 0.5, 0.0f, playerIt->_currentPos.second + 0.5), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
                        camera.setMode(CAMERA_ORBITAL);
                    } else if (playerIt->_inventory.size() >= 7) {
                        zappy::graphic::Text::drawText("Level: " + std::to_string(playerIt->_level), 200, 910, 20, zappy::graphic::Color(255, 255, 255));
                        camera.setPosition(zappy::math::Vector3(playerIt->_currentPos.first + 2, 5.0f, playerIt->_currentPos.second + 2), zappy::math::Vector3(playerIt->_currentPos.first + 0.5, 0.0f, playerIt->_currentPos.second + 0.5), zappy::math::Vector3(0.0f, 1.0f, 0.0f));
                        if (playerIt->_isEgg == false) {
                            zappy::graphic::Text::drawText("ID: " + std::to_string(playerIt->_id), 200, 960, 20, zappy::graphic::Color(255, 255, 255));
                            zappy::graphic::Text::drawText("Food: " + std::to_string(playerIt->_inventory[zappy::Fruits::FOOD]), 400, 850, 20, zappy::graphic::Color(255, 255, 255));
                            food_texture.draw(zappy::math::Vector2(400, 890), 0, 0.5, zappy::graphic::Color(255, 255, 255));
                            zappy::graphic::Text::drawText("Linemate: " + std::to_string(playerIt->_inventory[zappy::Fruits::LINERNATE]), 550, 850, 20, zappy::graphic::Color(255, 255, 255));
                            linemate_texture.draw(zappy::math::Vector2(550, 890), 0, 0.2, zappy::graphic::Color(255, 255, 255));
                            zappy::graphic::Text::drawText("Deraumere: " + std::to_string(playerIt->_inventory[zappy::Fruits::DERAUMERE]), 700, 850, 20, zappy::graphic::Color(255, 255, 255));
                            deraumere_texture.draw(zappy::math::Vector2(700, 890), 0, 0.2, zappy::graphic::Color(255, 255, 255));
                            zappy::graphic::Text::drawText("Sibur: " + std::to_string(playerIt->_inventory[zappy::Fruits::SIBUR]), 850, 850, 20, zappy::graphic::Color(255, 255, 255));
                            sibur_texture.draw(zappy::math::Vector2(850, 890), 0, 0.2, zappy::graphic::Color(255, 255, 255));
                            zappy::graphic::Text::drawText("Mendiane: " + std::to_string(playerIt->_inventory[zappy::Fruits::MENDIANE]), 1000, 850, 20, zappy::graphic::Color(255, 255, 255));
                            mendiane_texture.draw(zappy::math::Vector2(1000, 890), 0, 0.2, zappy::graphic::Color(255, 255, 255));
                            zappy::graphic::Text::drawText("Phiras: " + std::to_string(playerIt->_inventory[zappy::Fruits::PHIRAS]), 1150, 850, 20, zappy::graphic::Color(255, 255, 255));
                            phiras_texture.draw(zappy::math::Vector2(1150, 890), 0, 0.2, zappy::graphic::Color(255, 255, 255));
                            zappy::graphic::Text::drawText("Thystame: " + std::to_string(playerIt->_inventory[zappy::Fruits::THYSTAME]), 1300, 850, 20, zappy::graphic::Color(255, 255, 255));
                            thystame_texture.draw(zappy::math::Vector2(1300, 890), 0, 0.2, zappy::graphic::Color(255, 255, 255));
                        }
                    }
                }
            } else
                zappy::graphic::Text::drawText("Press C to change Camera", 10, 50, 20, zappy::graphic::Color(0, 0, 0));
                zappy::graphic::Text::drawText("Press I to toggle Inventory", 10, 10, 20, zappy::graphic::Color(0, 0, 0));

            _window.endDrawing();
        }
    }
}

