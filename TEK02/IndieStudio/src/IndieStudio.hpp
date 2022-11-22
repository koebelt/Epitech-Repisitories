/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** IndieStudio
*/

#ifndef INDIESTUDIO_HPP_
#define INDIESTUDIO_HPP_

#include "./game/system/entities/EntityPlayer.hpp"
#include "./game/managers/SceneManager.hpp"
#include "./game/utils/Matrix.hpp"
#include "./engine/Engine.hpp"

namespace istudio {
    class IndieStudio {
        public:
            static void init();
            static void start(); // Game Loop

            static SceneManager &getScenes() { return _sceneManager; };
            static Matrix &getMatrix() { return _map; };

            inline static float masterVolume = 1.0;
            inline static float musicVolume = 5;
            inline static float soundVolume = 5;
        protected:
        private:
            inline static Matrix _map{13, 13};
            inline static SceneManager _sceneManager{};
    };
}

#endif /* !INDIESTUDIO_HPP_ */
