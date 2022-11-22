/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Shader
*/

#pragma once

    extern "C" {
        #include <raylib.h>
    }

    #include "../../color/Color.hpp"
    #include "../../../math/Math.hpp"

namespace istudio {

namespace graphic {

    typedef enum
    {
        LIGHT_DIRECTIONAL,
        LIGHT_POINT
    } LightType;

    class Shader {
        public:
            Shader(const char *vsFileName, const char *fsFileName);
            Shader(const Shader &shader);
            ~Shader();
            int getLocation(const char *uniformName);
            int getLocationAttrib(const char *attribName);
            void setValue(int locIndex, const void *value, int uniformType);
            void setValueV(int locIndex, const void *value, int uniformType, int count);
            void setValueMatrix(int locIndex, Matrix mat);
            void setValueTexture(int locIndex, Texture2D texture);
            ::Shader getCShader()
            {
                return {_shader};
            };
            int *getLocs() { return _shader.locs; };
        private:
            ::Shader _shader;
    };

}
}