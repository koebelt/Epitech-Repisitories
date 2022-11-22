/*
** EPITECH PROJECT, 2022
** system
** File description:
** Texture
*/

#pragma once

#include <string>
#include "../image/Image.hpp"
#include "../../color/Color.hpp"
#include "../../../math/Math.hpp"
    extern "C" {
        #include <raylib.h>
    }

namespace zappy {

    namespace graphic {

        typedef enum
        {
            REPEAT = 0,    // Repeats texture in tiled mode
            CLAMP,         // Clamps texture to edge pixel in tiled mode
            MIRROR_REPEAT, // Mirrors and repeats the texture in tiled mode
            MIRROR_CLAMP   // Mirrors and clamps to border the texture in tiled mode
        } TextureWrap;

        class Texture {
            public:
                Texture() {};
                Texture(std::string fileName);
                Texture(graphic::Image image);
                Texture(graphic::Image image, int layout);
                Texture(const Texture &texture);
                ~Texture();

                void load(std::string filename);
                ::Texture getCTexture() { return _texture; };
                void setWrappingMode(int wrapMode);
                int getWidth() const {
                    if (!_isLoaded) return 0;
                    return _texture.width;
                };
                int getHeight() const {
                    if (!_isLoaded) return 0;
                    return _texture.height;
                };
                void draw(int posX, int posY, Color tint);
                void draw(zappy::math::Vector2 position, Color tint);
                void draw(zappy::math::Vector2 position, zappy::math::Rectangle rect, Color tint);
                void draw(zappy::math::Vector2 position, zappy::math::Rectangle rect, float scale, Color tint);
                void draw(zappy::math::Vector2 position, float rotation, float scale, Color tint);

                void unload();

                protected:
                private:
                    bool _isLoaded = false;
                    ::Texture _texture;
        };


        class RenderTexture {
            public:
                RenderTexture(int width, int height);
                ~RenderTexture();

            protected:
            private:
                ::RenderTexture _renderTexture;
        };

    }
}

