/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-zappy-ethan.husser
** File description:
** Skybox
*/

#pragma once

extern "C" {
    #include <raylib.h>
    #include "rlgl.h"
    #include "raymath.h"
}

#include <string>
#include "../../../math/Math.hpp"

namespace zappy {
    namespace graphic {
        class Skybox {
            public:
                Skybox(std::string filename);
                ~Skybox();

                void draw();

            protected:
            private:
                ::Model _skybox;
                static TextureCubemap GenTextureCubemap(Shader shader, Texture2D panorama, int size, int format);
        };
    }
}
