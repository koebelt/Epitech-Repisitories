/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Material
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
        class Material {
            public:
                Material(std::string filename, int *materialCount);
                Material(const Material &mat);
                ~Material();
                ::Material getCMat() { return *_monMat; };
                void setTexture(int mapType, zappy::graphic::Texture texture) { SetMaterialTexture(_monMat, mapType, texture.getCTexture()); };

            protected:
            private:
                ::Material *_monMat;
        };
    }
}

