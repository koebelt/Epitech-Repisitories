/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Material
*/

#include "Material.hpp"

namespace istudio {
    namespace graphic {
        Material::Material(std::string filename, int *materialCount)
        {
            _monMat = LoadMaterials(filename.c_str(), materialCount);
        }
        Material::Material(const Material &mat)
        {
            _monMat = mat._monMat;
        }
        Material::~Material()
        {
            UnloadMaterial(*_monMat);
        }
    }
}