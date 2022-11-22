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

namespace istudio {
    namespace graphic {
        class Mesh {
            public:
                Mesh() = default;
                ~Mesh() = default;
                Mesh(::Mesh mesh) : _mesh(mesh) {}; 

                static Mesh genPoly(int sides, float radius);
                static Mesh genPlane(float width, float length, int resX, int resZ);
                static Mesh genCube(float width, float height, float length);
                static Mesh genSphere(float radius, int rings, int slices);
                static Mesh genHemiSphere(float radius, int rings, int slices);
                static Mesh genCylinder(float radius, float height, int slices);
                static Mesh genCone(float radius, float height, int slices);
                static Mesh genTorus(float radius, float size, int radSeg, int sides);
                static Mesh genKnot(float radius, float size, int radSeg, int sides);
                static Mesh genHeightmap(Image heightmap, istudio::math::Vector3 size);
                static Mesh genCubicmap(Image cubicmap, istudio::math::Vector3 cubeSize);

                ::Mesh getCMesh() { return _mesh; };

            protected:
            private:
                ::Mesh _mesh;

        };
    }
}
