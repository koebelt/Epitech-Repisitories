/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Mesh
*/

#pragma once

extern "C" {
    #include "raylib.h"
}

#include <vector>
#include "../../../math/Math.hpp"
#include "../../color/Color.hpp"
#include "../../2d/2d.hpp"

namespace zappy {
    namespace graphic {
        class Mesh {
            public:
                Mesh() = default;
                ~Mesh() = default;

                //Generation
                void genPoly(int sides, float radius);
                void genPlane(float width, float length, int resX, int resZ);
                void genCube(float width, float height, float length);
                void genSphere(float radius, int rings, int slices);
                void genHemiSphere(float radius, int rings, int slices);
                void genCylinder(float radius, float height, int slices);
                void genCone(float radius, float height, int slices);
                void genTorus(float radius, float size, int radSeg, int sides);
                void genKnot(float radius, float size, int radSeg, int sides);
                void genHeightmap(Image heightmap, zappy::math::Vector3 size);
                void genCubicmap(Image cubicmap, zappy::math::Vector3 cubeSize);

                ::Mesh getCMesh() { return _mesh; };

            protected:
            private:
                ::Mesh _mesh;

        };
    }
}
