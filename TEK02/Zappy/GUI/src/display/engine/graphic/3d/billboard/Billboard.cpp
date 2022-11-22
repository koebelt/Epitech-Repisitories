/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Billboard
*/

#include "Billboard.hpp"

namespace zappy {

namespace graphic {

    Billboard::Billboard(std::string filename) : _texture(zappy::graphic::Texture(filename))
    {
    }

    Billboard::~Billboard()
    {
        UnloadTexture(_texture.getCTexture());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function drawBillboard (Class Model): Function to draw a billboard
    ** @param camera (graphic::Camera): Camera to draw the billboard
    ** @param position (Vector3): Vector for the drawing process
    ** @param size (float): Size of the billboard
    ** @param tint (graphic::Color) Tint of the billboard
    **
    ** @return Nothing
    **/
    void Billboard::draw(graphic::Camera camera, math::Vector3 position, float size, graphic::Color tint)
    {
        DrawBillboard(camera.getCCamera(), _texture.getCTexture(), position.getCVector(), size, tint.getCColor());
    }

    // void Model::drawBillboardRec(graphic::Camera camera, graphic::Texture texture, math::Rectangle source, math::Vector3 position, math::Vector2 size, graphic::Color tint)
    // {
    //     DrawBillboardRec(camera.getCCamera(), texture.getCTexture(), source.getCRectangle(), position.getCVector(), size.getCVector(), tint.getCColor());
    // }

    // void Model::drawBillboardPro(graphic::Camera camera, graphic::Texture texture, math::Rectangle source, math::Vector3 position, math::Vector3 up, math::Vector2 size, math::Vector2 origin, float rotation, graphic::Color tint)
    // {
    //     DrawBillboardPro(camera.getCCamera(), texture.getCTexture(), source.getCRectangle(), position.getCVector(), up.getCVector(), size.getCVector(), origin.getCVector(), rotation, tint.getCColor());
    // }
}
}