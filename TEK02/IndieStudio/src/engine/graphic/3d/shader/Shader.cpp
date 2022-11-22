/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** Shader
*/

#include "Shader.hpp"

namespace istudio {

namespace graphic {

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Shader constructor
    ** @param vsFileName (char): File that contains the lighting for the shader
    ** @param fsFileName (char): File that contains the f# code for the shader
    **/
    Shader::Shader(const char *vsFileName, const char *fsFileName)
    {
        _shader = LoadShader(vsFileName, fsFileName);
    }
    
    Shader::Shader(const Shader &shader)
    {
        _shader = shader._shader;
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Class Shader destructor
    **/
    Shader::~Shader()
    {
        UnloadShader(_shader);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getLocation (Class Shader): Function to get the location of a shader
    ** @param uniformName (char): Name for the uniform
    **
    ** @return int
    **/
    int Shader::getLocation(const char *uniformName)
    {
        return GetShaderLocation(getCShader(), uniformName);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setValue (Class Shader): Function to set the uniform value of a shader
    ** @param locIndex (int): Location of the shader
    ** @param value (void *): Value of the shader
    ** @param uniformType (int): Type for the uniform
    **
    ** @return Nothing
    **/
    void Shader::setValue(int locIndex, const void *value, int uniformType)
    {
        return SetShaderValue(getCShader(), locIndex, value, uniformType);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setValueV (Class Shader): Function to set the uniform value vector of a shader
    ** @param locIndex (int): Location of the shader
    ** @param value (void *): Value of the uniform
    ** @param uniformType (int): Type of the uniform
    ** @param count (int): Count value
    **
    ** @return Nothing
    **/
    void Shader::setValueV(int locIndex, const void *value, int uniformType, int count)
    {
        return SetShaderValueV(getCShader(), locIndex, value, uniformType, count);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setValueMatrix (Class Shader): Function to set the value of a shader using a matrix
    ** @param locIndex (int): Location of the shader
    ** @param mat (Matrix): Matrix to set the value
    **
    ** @return Nothing
    **/
    void Shader::setValueMatrix(int locIndex, Matrix mat)
    {
        return SetShaderValueMatrix(getCShader(), locIndex, mat);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function setValueMatrix (Class Shader): Function to set the value of a shader using a texture
    ** @param locIndex (int): Location of the shader
    ** @param texture (Texture2D): Texture to set the value
    **
    ** @return Nothing
    **/
    void Shader::setValueTexture(int locIndex, Texture2D texture)
    {
        return SetShaderValueTexture(getCShader(), locIndex, texture);
    }

    /**
    ** @author : Mathéo Vitali
    **
    ** @brief Function getLocationAttrib (Class Shader): Function to get the location attribute of a shader
    ** @param attribName (char): Name of the attribute
    **
    ** @return int
    **/
    int Shader::getLocationAttrib(const char *attribName)
    {
        return GetShaderLocationAttrib(getCShader(), attribName);
    }
}
}