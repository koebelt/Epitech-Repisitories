/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Model
*/

// * TODO : Encapsuling Camera, BoundingBox, Texture2D, Color

#pragma once

#include <string>

extern "C" {
    #include <raylib.h>
}

#include "../../../math/Math.hpp"
#include "../../color/Color.hpp"
#include "../../camera/Camera.hpp"
#include "../../2d/2d.hpp"
#include "../shader/Shader.hpp"
#include "../mesh/Mesh.hpp"

namespace istudio {

    namespace graphic {
        // class BoundingBox {
        //     public:
        //         BoundingBox(Model model);
        //         ~BoundingBox();
        //         ::BoundingBox getCBoundingBox() {return _boundingBox;};

        //     protected:
        //     private:
        //         ::BoundingBox _boundingBox;
        // };
        class Model {
            public:
                Model() = default;
                Model(istudio::graphic::Mesh mesh);
                Model(istudio::graphic::Mesh mesh, std::string filename_text);
                Model(std::string filename);
                Model(std::string filename, std::string filename_text);
                Model(const Model &model);
                ~Model();
                ::Model getCModel() { return _model; };

                //Model Drawing Functions
                void load(istudio::graphic::Mesh mesh, std::string filename_text);
                void load(std::string filename, std::string filename_text);
                void draw(math::Vector3 position, float scale, graphic::Color tint); // Draw a model (with texture if set)
                void draw(math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphic::Color tint); // Draw a model with extended parameters
                void drawWires(math::Vector3 position, float scale, graphic::Color tint);                                                         // Draw a model wires (with texture if set)
                void drawWiresEx(math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphic::Color tint); // Draw a model wires (with texture if set) with extended parameters
                void drawBoundingBox(BoundingBox box, graphic::Color color);                                                                           // Draw bounding box (wires)
                void setShader(graphic::Shader *shader);
                void setTexture(graphic::Texture *texture, int materialMap = 0);
                void unload();

                //Collision
                bool checkCollisionSpheres(math::Vector3 center1, float radius1, math::Vector3 center2, float radius2);        // Check collision between two spheres
                bool checkCollisionBoxes(BoundingBox box);                                      // Check collision between two bounding boxes
                bool checkCollisionBoxSphere(math::Vector3 center, float radius);                       // Check collision between box and sphere
            protected:
            private:
                ::Model _model;
                ::BoundingBox _boundingBox;
                bool has_texture = false;
                bool _isLoaded = false;
        };
    }
}
