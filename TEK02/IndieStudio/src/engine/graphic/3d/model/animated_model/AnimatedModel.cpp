/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** AnimatedModel
*/

#include "AnimatedModel.hpp"


namespace istudio
{
    namespace graphic
    {
        AnimatedModel::AnimatedModel(std::string modelFilename, std::string texture, std::list<std::string> animFilenames)
        {
            _isLoaded = true;
            _model = LoadModel(modelFilename.c_str());
            _texture = LoadTexture(texture.c_str());
            SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
            _mode = 1;
            _animCount = animFilenames.size();
            for (auto it = animFilenames.begin(); it != animFilenames.end(); ++it) {
                _animN.push_front(0);
                _animations.push_back(std::pair<int, ::ModelAnimation *>(0, LoadModelAnimations(it->c_str(), &_animN.front())));
            }
        }

        AnimatedModel::AnimatedModel(std::string modelFilename, std::string texture, std::string animFilename, int animCount)
        {
            _isLoaded = true;
            _model = LoadModel(modelFilename.c_str());
            _texture = LoadTexture(texture.c_str());
            SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
            _mode = 0;
            _animCount = animCount;
            for (int i = 0; i < animCount; ++i) {
                _animN.push_front(i);
                _animations.push_back(std::pair<int, ::ModelAnimation *>(i, LoadModelAnimations(animFilename.c_str(), &_animN.front())));
            }
        }

        AnimatedModel::~AnimatedModel()
        {
            unload();
        }

        void AnimatedModel::load(std::string modelFilename, std::string texture, std::list<std::string> animFilenames)
        {
            _isLoaded = true;
            _model = LoadModel(modelFilename.c_str());
            _texture = LoadTexture(texture.c_str());
            SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
            _mode = 1;
            _animCount = animFilenames.size();
            for (auto it = animFilenames.begin(); it != animFilenames.end(); ++it) {
                _animN.push_front(0);
                _animations.push_back(std::pair<int, ::ModelAnimation *>(0, LoadModelAnimations(it->c_str(), &_animN.front())));
            }
        }

        void AnimatedModel::load(std::string modelFilename, std::string texture, std::string animFilename, int animCount)
        {
            _isLoaded = true;
            _model = LoadModel(modelFilename.c_str());
            _texture = LoadTexture(texture.c_str());
            SetMaterialTexture(&_model.materials[0], MATERIAL_MAP_DIFFUSE, _texture);
            _mode = 0;
            _animCount = animCount;
            for (int i = 0; i < animCount; ++i) {
                _animN.push_front(i);
                _animations.push_back(std::pair<int, ::ModelAnimation *>(i, LoadModelAnimations(animFilename.c_str(), &_animN.front())));
            }
        }

        void AnimatedModel::play(int anim)
        {
            _currentAnim = anim;
        }

        int AnimatedModel::draw(math::Vector3 position, float scale, graphic::Color tint)
        {
            if (!_isLoaded) return 0;
            int i = 0;
            for (auto it = _animations.begin(); it != _animations.end(); ++it, ++i) {
                if (i == _currentAnim) {
                    _currentFrame++;
                    UpdateModelAnimation(_model, it->second[it->first], _currentFrame);
                    DrawModel(_model, position.getCVector(), scale, tint.getCColor());
                    if (_currentFrame >= it->second[it->first].frameCount) {
                        _currentFrame = 0;
                        return 1;
                    }
                    break;
                }
            }
            return 0;
        }

        int AnimatedModel::draw(math::Vector3 position, math::Vector3 rotationAxis, float rotationAngle, math::Vector3 scale, graphic::Color tint)
        {
            if (!_isLoaded)
                return 0;
            int i = 0;
            for (auto it = _animations.begin(); it != _animations.end(); ++it, ++i) {
                if (i == _currentAnim) {
                    _currentFrame++;
                    UpdateModelAnimation(_model, it->second[it->first], _currentFrame);
                    DrawModelEx(_model, position.getCVector(), rotationAxis.getCVector(), rotationAngle, scale.getCVector(), tint.getCColor());
                    if (_currentFrame >= it->second[it->first].frameCount) {
                        _currentFrame = 0;
                        return 1;
                    }
                    break;
                }
            }
            return 0;
        }

        void AnimatedModel::unload()
        {
            if (!_isLoaded) return;
            _isLoaded = false;
            UnloadTexture(_texture);
            for (auto it = _animations.begin(); it != _animations.end(); ++it)
            {
                for (unsigned int i = 0; i < it->first; i++)
                    UnloadModelAnimation(it->second[i]);
            }
            UnloadModel(_model);
        }
    }
}
