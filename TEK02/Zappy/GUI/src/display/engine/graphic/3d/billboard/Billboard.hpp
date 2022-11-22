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

namespace zappy {

    namespace graphic {

        class Billboard {
            public:
                Billboard(std::string filename);
                ~Billboard();
                void draw(graphic::Camera camera, math::Vector3 position, float size, graphic::Color tint);
                void draw(graphic::Camera camera, graphic::Texture texture, math::Rectangle source, math::Vector3 position, math::Vector3 up, math::Vector2 size, math::Vector2 origin, float rotation, graphic::Color tint);

                protected :
                private :
                    zappy::graphic::Texture _texture;
        };

    }

}