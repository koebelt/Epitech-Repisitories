/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Billboard
*/

#include "Billboard.hpp"

namespace istudio {

namespace graphic {

    Billboard::Billboard(std::string filename) : _texture(istudio::graphic::Texture(filename))
    {
        _isLoaded = true;
    }

    Billboard::~Billboard()
    {
        unload();
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
        if (!_isLoaded) return;
        DrawBillboard(camera.getCCamera(), _texture.getCTexture(), position.getCVector(), size, tint.getCColor());
    }

    void Billboard::unload()
    {
        if (!_isLoaded) return;
        _isLoaded = false;
        _texture.unload();
    }
}
}