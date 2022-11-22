/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Font
*/

#pragma once

extern "C" {
        #include <raylib.h>
    }

namespace istudio {

    class Font {
        public:
            Font(const char *fileName);
            Font(const Font &font);
            Font();
            void load(const char *fileName);
            void unload();
            ::Font getCFont() { return _font; };
            ~Font();

        protected:
        private:
            bool _isLoaded = false;
            ::Font _font;
    };


}
