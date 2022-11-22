/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Image
*/

#pragma once

    extern "C" {
        #include <raylib.h>
    }

    #include <string>

namespace zappy {

namespace graphic {
    class Image {
        public:
            Image(std::string filename);
            Image(const Image &image);
            ~Image();

            void resize(int newWidth, int newHeight);
            ::Image getCImg() { return _img; };

        protected:
        private:
            ::Image _img;
    };
}
}

