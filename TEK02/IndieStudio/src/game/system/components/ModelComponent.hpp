/*
** EPITECH PROJECT, 2022
** IndieStudio
** File description:
** ModelComponent
*/

#ifndef MODELCOMPONENT_HPP_
#define MODELCOMPONENT_HPP_

#include "../IComponent.hpp"
#include "../../utils/Vector.hpp"

namespace istudio {
    namespace graphic {
        class Model;
    }
    /**
     ** @author Paul Gazeau-Rousseau
     **
     ** @brief Model component to encapsulate a model linked to an entity
     **
    */
    class ModelComponent : public IComponentDrawable {
        public:
            ModelComponent(istudio::graphic::Model *model, float scale = 1);
            ~ModelComponent() = default;

            void update();
            void draw();
        protected:
        private:
            istudio::graphic::Model *_model;
            VectorF _direction;
            float _scale;
    };
}

#endif /* !MODELCOMPONENT_HPP_ */
