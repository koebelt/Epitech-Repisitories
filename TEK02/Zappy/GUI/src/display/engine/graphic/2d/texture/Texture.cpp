/*
** EPITECH PROJECT, 2022
** system
** File description:
** Texture
*/

#include "Texture.hpp"

namespace zappy
{
    namespace graphic
    {
        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Texture constructor
        ** @param fileName (std::string): File that contains the texture
        **/
        Texture::Texture(std::string fileName)
        {
            _isLoaded = true;
            _texture = LoadTexture(fileName.c_str());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Texture constructor
        ** @param image (graphic::Image): Image used to create the texture
        **/
        Texture::Texture(graphic::Image image)
        {
            _isLoaded = true;
            _texture = LoadTextureFromImage(image.getCImg());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Texture constructor
        ** @param image (graphic::Image): Image used to create the texture
        **/
        Texture::Texture(const Texture &texture)
        {
            _isLoaded = true;
            _texture = texture._texture;
        }
        
        /**
        ** @author : koebelt <thomas.koebel@epitech.eu>
        **
        ** @brief Class Texture constructor
        ** @param image (graphic::Image): cubemap image
        ** @param layout (int): layout of the cubemap
        **/
        Texture::Texture(graphic::Image image, int layout)
        {
            _isLoaded = true;
            _texture = LoadTextureCubemap(image.getCImg(), layout);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class Texture destructor
        **/
        Texture::~Texture()
        {
            unload();
        }
        
        void Texture::load(std::string filename)
        {
            _isLoaded = true;
            _texture = LoadTexture(filename.c_str());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function setWrappingMode (Class Texture): Function to set the wrapping mode of the image
        ** @param wrapMode (int): Mode for the wrapping
        **
        ** @return Nothing
        **/
        void Texture::setWrappingMode(int wrapMode)
        {
            if (!_isLoaded) return;
            SetTextureWrap(_texture, wrapMode);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function draw (Class Texture): Function to draw a texture using coordinates
        ** @param texture (Texture2D): Texture to draw
        ** @param posX (int): X coordinate
        ** @param posY (int): Y coordinate
        ** @param tint (int): Tint for the texture
        **
        ** @return Nothing
        **/
        void Texture::draw(int posX, int posY, Color tint)
        {
            if (!_isLoaded) return;
            DrawTexture(_texture, posX, posY, tint.getCColor());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function draw (Class Texture): Function to draw a texture using a vector
        ** @param texture (Texture2D): Texture to draw
        ** @param position (Vector2): Vector for the position
        ** @param tint (int): Tint for the texture
        **
        ** @return Nothing
        **/
        void Texture::draw(zappy::math::Vector2 position, Color tint)
        {
            if (!_isLoaded) return;
            DrawTextureV(_texture, position.getCVector(), tint.getCColor());
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Function draw (Class Texture): Function to draw a texture using a vector, a rotation and a scale
        ** @param texture (Texture2D): Texture to draw
        ** @param position (Vector2): Vector for the position
        ** @param rotation (float): Rotation of the texture
        ** @param scale (float): Scale of the texture
        ** @param tint (int): Tint for the texture
        **
        ** @return Nothing
        **/
        void Texture::draw(zappy::math::Vector2 position, float rotation, float scale, Color tint)
        {
            if (!_isLoaded) return;
            DrawTextureEx(_texture, position.getCVector(), rotation, scale, tint.getCColor());
        }
        
        void Texture::draw(zappy::math::Vector2 position, zappy::math::Rectangle rect, Color tint)
        {
            if (!_isLoaded) return;
            DrawTextureRec(_texture, rect.getCRectangle(), position.getCVector(), tint.getCColor());
        }
        
        void Texture::draw(zappy::math::Vector2 position, zappy::math::Rectangle rect, float scale, Color tint)
        {
            if (!_isLoaded) return;
            DrawTextureTiled(_texture, rect.getCRectangle(), {position.x, position.y, rect.width * scale, rect.height * scale}, {0, 0}/*position.getCVector()*/, 0, scale, tint.getCColor());
        }

        void Texture::unload()
        {
            if (!_isLoaded) return;
            _isLoaded = false;
            UnloadTexture(_texture);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class RenderTexture constructor
        ** @param width (int): Width of the render
        ** @param height (int): Heigth of the texture
        **/
        RenderTexture::RenderTexture(int width, int height)
        {
            _renderTexture = LoadRenderTexture(width, height);
        }

        /**
        ** @author : Mathéo Vitali
        **
        ** @brief Class RenderTexture destructor
        **/
        RenderTexture::~RenderTexture()
        {
            UnloadRenderTexture(_renderTexture);
        }

    }
}