/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Animation
*/

#pragma once

#include <string>
#include <tuple>
#include <list>
#include <chrono>
#include "../../../math/Math.hpp"
#include "../texture/Texture.hpp"

namespace istudio {
    namespace graphic {
        class Animation {
            public:
                Animation(std::string filename, std::list<std::tuple<float, istudio::math::Vector2, float, float>> keyframes);
                ~Animation();

                void start();
                void update();

                bool isFinished();

            protected:
            private:
                istudio::graphic::Texture _texture;
                std::list<std::tuple<float, istudio::math::Vector2, float, float>> _keyframes;
        };
    }
}
