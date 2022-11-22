/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Model
*/

#include "Model.hpp"

namespace zappy {
    namespace graphic {

        // BoundingBox::BoundingBox(Model model)
        // {
        //     _boundingBox = GetModelBoundingBox(model.getCModel());
        // }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Model constructor using a filename
        ** @param filename (std::string): File that countains the model
        **/
        Model::Model(std::string filename)
        {
            _model = LoadModel(filename.c_str());
            _boundingBox = GetModelBoundingBox(_model); // BoundingBox(_model);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Model constructor using a mesh
        ** @param mesh (zappy::graphic::Mesh): Mesh to use
        **/
        Model::Model(zappy::graphic::Mesh mesh)
        {
            _model = LoadModelFromMesh(mesh.getCMesh());
            _boundingBox = GetModelBoundingBox(_model); // BoundingBox(_model);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Model constructor using an already existant model
        ** @param model (zappy::graphic::Model): Model to use
        **/
        Model::Model(const Model &model)
        {
            _model = model._model;
            _boundingBox = model._boundingBox;
        }
        
        Model::Model(std::string filename, std::string filename_text)
        {
            _model = LoadModel(filename.c_str());
            _boundingBox = GetModelBoundingBox(_model); // BoundingBox(_model);
            _model.materials[0].maps[0].texture = LoadTexture(filename_text.c_str());
            has_texture = true;
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Model destructor
        **/
        Model::~Model()
        {
            if (has_texture)
                UnloadTexture(_model.materials[0].maps[0].texture);
            UnloadModel(_model);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function draw (Class Model): Function to draw a model
        ** @param position (Vector3): Position to drawn the model
        ** @param scale (float): Scale of the model
        ** @param tint (Color): Color of the model
        **/
        void Model::draw(math::Vector3 position, float scale, graphic::Color tint)
        {
            DrawModel(_model, position.getCVector(), scale, tint.getCColor());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function draw (Class Model): Function to draw a model with an axis and an angle of rotation
        ** @param position (Vector3): Position to draw the model
        ** @param rotationAxis (Vector3): Axis rotation to draw the model
        ** @param rotationAngle (Vector3): Angle rotation to draw the model
        ** @param scale (float): Scale of the model
        ** @param tint (Color): Color of the model
        **/
        void Model::draw(math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphic::Color tint)
        {
            DrawModelEx(_model, position.getCVector(), rotationAxis.getCVector(), rotationAngle, scale.getCVector(), tint.getCColor());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function drawWires (Class Model): Function to draw the wires of a model
        ** @param position (Vector3): Position to draw the wires
        ** @param scale (float): Scale of the wires
        ** @param tint (Color): Color of the wires
        **/
        void Model::drawWires(math::Vector3 position, float scale, graphic::Color tint)
        {
            DrawModelWires(_model, position.getCVector(), scale, tint.getCColor());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function drawWires (Class Model): Function to draw the wires of a model using an axis and an angle of rotation
        ** @param position (Vector3): Position to draw the wires
        ** @param rotationAxis (Vector3): Axis rotation to draw the wires
        ** @param rotationAngle (Vector3): Angle rotation to draw the wires
        ** @param scale (float): Scale of the wires
        ** @param tint (Color): Color of the wires
        **/
        void Model::drawWiresEx(math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphic::Color tint)
        {
            DrawModelWiresEx(_model, position.getCVector(), rotationAxis.getCVector(), rotationAngle, scale.getCVector(), tint.getCColor());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function drawBoundingBox (Class Model): Function to draw a bounding box
        ** @param box (::BoundingBox): Box to draw
        ** @param color (graphic::Color): Color of the box
        **
        ** @return Nothing
        **/
        void Model::drawBoundingBox(::BoundingBox box, graphic::Color color)
        {
            DrawBoundingBox(box, color.getCColor());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setShader (Class Model): Function to set a shader for a model
        ** @param shader (graphic::Shader): Shader to apply to the model
        **
        ** @return Nothing
        **/
        void Model::setShader(graphic::Shader *shader)
        {
            _model.materials[0].shader = shader->getCShader();
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setTexture (Class Model): Function to set a texture to a model
        ** @param texture (graphic::Texture): Texture to apply to the model
        ** @param materialMap (int): Material to apply to the texture
        **
        ** @return Nothing
        **/
        void Model::setTexture(graphic::Texture *texture, int materialMap)
        {
            _model.materials[0].maps[materialMap].texture = texture->getCTexture();
        }


         /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function checkCollisionSphere (Class Model): Function to check if two spheres collide
        ** @param center1 (Vector3): Center of the first sphere
        ** @param radius1 (float): Radius of the first sphere
        ** @param center2 (Vector3): Center of the second sphere
        ** @param radius2 (float): Radius of the second sphere
        **
        ** @return bool
        **/
        bool Model::checkCollisionSpheres(math::Vector3 center1, float radius1, math::Vector3 center2, float radius2)
        {
            return CheckCollisionSpheres(center1.getCVector(), radius1, center2.getCVector(), radius2);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function checkCollisionBoxes (Class Model): Function to check if this box is colliding with another one
        ** @param box (BoundingBox): Box to check if there is collision with
        **
        ** @return bool
        **/
        bool Model::checkCollisionBoxes(BoundingBox box)
        {
            return CheckCollisionBoxes(_boundingBox, box);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function checkCollisionBoxSphere(Class Model): Function to check if this box is colliding with a sphere
        ** @param center (Vector3): Center of the sphere
        ** @param radius (float): Radius of the sphere
        **
        ** @return bool
        **/
        bool Model::checkCollisionBoxSphere(math::Vector3 center, float radius)
        {
            return CheckCollisionBoxSphere(_boundingBox, center.getCVector(), radius);
        }
    }
}

