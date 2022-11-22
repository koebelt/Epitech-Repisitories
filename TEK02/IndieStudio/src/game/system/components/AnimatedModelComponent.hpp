/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** AnimatedModelComponent
*/

#ifndef ANIMATEDMODELCOMPONENT_HPP_
#define ANIMATEDMODELCOMPONENT_HPP_

#include "../IComponent.hpp"
#include "../../utils/Vector.hpp"

namespace istudio {
    namespace graphic {
        class Model;
        class AnimatedModel;
    }

    class AnimatedModelComponent : public IComponentDrawable {
        public:
            AnimatedModelComponent(istudio::graphic::AnimatedModel *animated, istudio::graphic::Model *idle, float scale = 1, float scaleAnim = 1);
            ~AnimatedModelComponent() = default;

            void update();
            void draw();
        protected:
        private:
            istudio::graphic::AnimatedModel *_animation;
            istudio::graphic::Model *_idle;
            VectorF _direction;
            float _scale;
            float _scaleAnim;
    };
}

#endif /* !ANIMATEDMODELCOMPONENT_HPP_ */
