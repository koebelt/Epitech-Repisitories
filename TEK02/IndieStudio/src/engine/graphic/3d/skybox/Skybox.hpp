/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-istudio-ethan.husser
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

namespace istudio {
    namespace graphic {
        class Skybox {
            public:
                Skybox();
                Skybox(std::string filename);
                ~Skybox();

                void draw();
                void load(std::string filename);
                void unload();

            protected:
            private:
                ::Model _skybox;
                bool _isLoaded = false;
                static TextureCubemap GenTextureCubemap(Shader shader, Texture2D panorama, int size, int format);
        };
    }
}
