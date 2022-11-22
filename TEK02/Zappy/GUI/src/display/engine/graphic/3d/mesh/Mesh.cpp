/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Mesh
*/

#include "Mesh.hpp"


namespace zappy
{
    namespace graphic
    {
        void Mesh::genPoly(int sides, float radius)
        {
            _mesh = GenMeshPoly(sides, radius);
        }
        
        void Mesh::genPlane(float width, float length, int resX, int resZ)
        {
            _mesh = GenMeshPlane(width, length, resX, resZ);
        }
        
        void Mesh::genCube(float width, float height, float length)
        {
            _mesh = GenMeshCube(width, height, length);
        }
        
        void Mesh::genSphere(float radius, int rings, int slices)
        {
            _mesh = GenMeshSphere(radius, rings, slices);
        }
        
        void Mesh::genHemiSphere(float radius, int rings, int slices)
        {
            _mesh = GenMeshHemiSphere(radius, rings, slices);
        }
        
        void Mesh::genCylinder(float radius, float height, int slices)
        {
            _mesh = GenMeshCylinder(radius, height, slices);
        }
        
        void Mesh::genCone(float radius, float height, int slices)
        {
            _mesh = GenMeshCone(radius, height, slices);
        }
        
        void Mesh::genTorus(float radius, float size, int radSeg, int sides)
        {
            _mesh = GenMeshTorus(radius, size, radSeg, sides);
        }
        
        void Mesh::genKnot(float radius, float size, int radSeg, int sides)
        {
            _mesh = GenMeshKnot(radius, size, radSeg, sides);
        }
        
        void Mesh::genHeightmap(Image heightmap, zappy::math::Vector3 size)
        {
            _mesh = GenMeshHeightmap(heightmap.getCImg(), size.getCVector());
        }
        
        void Mesh::genCubicmap(Image cubicmap, zappy::math::Vector3 cubeSize)
        {
            _mesh = GenMeshCubicmap(cubicmap.getCImg(), cubeSize.getCVector());
        }
    }
}