/*
** EPITECH PROJECT, 2022
** system
** File description:
** Camera2d
*/

#pragma once

    #include <string>
    extern "C" {
        #include <raylib.h>
    }
    #include "../../math/Math.hpp"

namespace zappy {
    namespace graphic {

        // Camera projection
        typedef enum
        {
            PERSPECTIVE = 0, // Perspective projection
            ORTHOGRAPHIC     // Orthographic projection
        } CameraProjection;

        class Camera {
            public:
                Camera(math::Vector3 position = math::Vector3(0.0f, 0.0f, 0.0f), math::Vector3 target = math::Vector3(1.0f, 0.0f, 0.0f), math::Vector3 up = math::Vector3(0.0f, 1.0f, 0.0f), float fovy = 0, int projection = CameraProjection::PERSPECTIVE);
                ~Camera() = default;

                ::Camera3D getCCamera();
                void setPosition(math::Vector3 position, math::Vector3 target, math::Vector3 rotation);
                void setMode(int mode); // Set camera mode (multiple camera modes available)
                void update();
                void drawGrid(int size, float meshSize);
                math::Vector3 getPosition() { return _camera.position; };
                math::Vector3 getTarget() { return _camera.target; };
                math::Vector3 getRotation() { return _camera.up; };

            protected:
            private:
                ::Camera3D _camera;
        };

    }

}
