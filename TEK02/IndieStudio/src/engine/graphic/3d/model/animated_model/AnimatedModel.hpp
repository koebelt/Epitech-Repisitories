/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** AnimatedModel
*/

#pragma once

extern "C" {
    #include <raylib.h>
}
#include <string>
#include <list>
#include <tuple>
#include "../../../../math/Math.hpp"
#include "../../../color/Color.hpp"

namespace istudio
{
    namespace graphic
    {
        class AnimatedModel
        {
        public:
            AnimatedModel() = default;
            AnimatedModel(std::string modelFilename, std::string texture, std::list<std::string> animFilenames);
            AnimatedModel(std::string modelFilename, std::string texture, std::string animFilename, int animCount);
            ~AnimatedModel();

            void load(std::string modelFilename, std::string texture, std::list<std::string> animFilenames);
            void load(std::string modelFilename, std::string texture, std::string animFilename, int animCount);

            void play(int anim);

            int draw(math::Vector3 position, float scale, graphic::Color tint);
            int draw(math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphic::Color tint);

            bool isPlaying() const {return _isPlaying;};

            void unload();

        protected:
        private:
            int _mode;
            bool _isPlaying = false;
            bool _isLoaded = false;
            ::Texture _texture;
            ::Model _model;
            std::list<std::pair<int, ::ModelAnimation *>> _animations;
            std::list<unsigned int> _animN;
            int _currentAnim = 0;
            int _currentFrame = 0;
            unsigned int _animCount = 0;
        };

    }
}
