/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Image
*/

#include "Image.hpp"

namespace istudio {

namespace graphic {

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Image constructor
    ** @param filename (std::string): File that contains the image
    **/
    Image::Image(std::string filename)
    {
        _img = LoadImage(filename.c_str());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Image constructor using another image
    ** @param image (Image): Image already existing, used to create another image
    **/
    Image::Image(const Image &image)
    {
        _img = ImageCopy(image._img);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Image destructor
    **/
    Image::~Image()
    {
        UnloadImage(getCImg());
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function resize (Class Image): Function to resize an image
    ** @param newWidth (int): Width for the image
    ** @param newHeight (int): Height for the image
    **
    ** @return Nothing
    **/
    void Image::resize(int newWidth, int newHeight)
    {
        ImageResize(&_img, newWidth, newHeight);
    }
}
}
