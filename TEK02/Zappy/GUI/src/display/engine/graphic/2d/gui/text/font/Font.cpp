/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Font
*/

#include "Font.hpp"

namespace zappy {

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Font constructor
    ** @param fileName (char): Name of the file that countains the font
    **/
    Font::Font(const char *fileName)
    {
        _isLoaded = true;
        _font = LoadFontEx(fileName, 100, 0, 250);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Font constructor
    **/
    Font::Font()
    {
        _isLoaded = true;
        _font = GetFontDefault();
    }
    
    Font::Font(const Font &font)
    {
        _isLoaded = true;
        _font = font._font;
    }
    
    void Font::load(const char *fileName)
    {
        _isLoaded = true;

        _font = LoadFontEx(fileName, 100, 0, 250);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Font destructor
    **/
    Font::~Font()
    {
        if (!_isLoaded) return;
        _isLoaded = false;
        UnloadFont(_font);
    }

    void Font::unload()
    {
        if (!_isLoaded) return;
        _isLoaded = false;
        UnloadFont(_font);
    }

}