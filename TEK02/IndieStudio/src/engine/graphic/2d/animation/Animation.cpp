/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Animation
*/

#include "Animation.hpp"


namespace istudio
{
    namespace graphic
    {
        Animation::Animation(std::string filename, std::list<std::tuple<float, istudio::math::Vector2, float, float>> keyframes)
        {
            _texture.load(filename);
            for (auto it : keyframes) {
                
            }
        }
        
        Animation::~Animation()
        {
            
        }
        
        void Animation::start()
        {
            
        }
        
        void Animation::update()
        {
            
        }
        
        bool Animation::isFinished()
        {
            
        }
    }
}