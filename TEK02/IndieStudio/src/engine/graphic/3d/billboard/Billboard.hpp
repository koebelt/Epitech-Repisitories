/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Billboard
*/

#pragma once

extern "C" {
    #include <raylib.h>
}

#include "../../../math/Math.hpp"
#include "../../color/Color.hpp"
#include "../../camera/Camera.hpp"
#include "../../2d/2d.hpp"
#include "../shader/Shader.hpp"

namespace istudio {

    namespace graphic {

        class Billboard {
            public:
                Billboard() {};
                Billboard(std::string filename);
                ~Billboard();

                void load(std::string filename);
                void draw(graphic::Camera camera, math::Vector3 position, float size, graphic::Color tint);
                void unload();

                protected :
                private :
                    bool _isLoaded = false;
                    istudio::graphic::Texture _texture;
        };

    }

}