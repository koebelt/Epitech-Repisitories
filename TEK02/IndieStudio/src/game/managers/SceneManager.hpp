/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** SceneManager
*/

#ifndef SCENEMANAGER_HPP_
#define SCENEMANAGER_HPP_

#include <list>
#include <map>

#include "../scenes/Scene.hpp"
#include "./IManager.hpp"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Class SceneManager ( public IManager<IScene> ): Manager for scene
**/
namespace istudio {
    class SceneManager : public IManager<IScene> {
        public:
            SceneManager &operator<<(std::shared_ptr<IScene> scene);
            SceneManager &operator<<(int scene);

            std::shared_ptr<IScene> &operator[](int id);
            void add(std::shared_ptr<IScene> scene);
            void load(int scene);
            void loadAndKeepLast(int scene);
            void llast();

            std::shared_ptr<IScene> &operator->(); // Get current scene
            std::shared_ptr<IScene> &operator~(); // Get current scene
            std::shared_ptr<IScene> &operator*(); // Get last scene

            int getLast() { return _last; };
        private:
            int _current = -1;
            int _last = -1;
			std::map<int, std::shared_ptr<IScene>> _scenes = {};
    };
}

#endif /* !SCENEMANAGER_HPP_ */
