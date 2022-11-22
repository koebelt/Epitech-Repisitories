/*
** EPITECH PROJECT, 2022
** B-YEP-400-STG-4-1-indiestudio-ethan.husser
** File description:
** Mesh
*/

#include "Mesh.hpp"


namespace istudio
{
    namespace graphic
    {
        Mesh Mesh::genPoly(int sides, float radius)
        {
            return (Mesh(GenMeshPoly(sides, radius)));
        }
        
        Mesh Mesh::genPlane(float width, float length, int resX, int resZ)
        {
            return (Mesh(GenMeshPlane(width, length, resX, resZ)));
        }
        
        Mesh Mesh::genCube(float width, float height, float length)
        {
            return (Mesh(GenMeshCube(width, height, length)));
        }
        
        Mesh Mesh::genSphere(float radius, int rings, int slices)
        {
            return (Mesh(GenMeshSphere(radius, rings, slices)));
        }
        
        Mesh Mesh::genHemiSphere(float radius, int rings, int slices)
        {
            return (Mesh(GenMeshHemiSphere(radius, rings, slices)));
        }
        
        Mesh Mesh::genCylinder(float radius, float height, int slices)
        {
            return (Mesh(GenMeshCylinder(radius, height, slices)));
        }
        
        Mesh Mesh::genCone(float radius, float height, int slices)
        {
            return (Mesh(GenMeshCone(radius, height, slices)));
        }
        
        Mesh Mesh::genTorus(float radius, float size, int radSeg, int sides)
        {
            return (Mesh(GenMeshTorus(radius, size, radSeg, sides)));
        }
        
        Mesh Mesh::genKnot(float radius, float size, int radSeg, int sides)
        {
            return (Mesh(GenMeshKnot(radius, size, radSeg, sides)));
        }
        
        Mesh Mesh::genHeightmap(Image heightmap, istudio::math::Vector3 size)
        {
            return (Mesh(GenMeshHeightmap(heightmap.getCImg(), size.getCVector())));
        }
        
        Mesh Mesh::genCubicmap(Image cubicmap, istudio::math::Vector3 cubeSize)
        {
            return (Mesh(GenMeshCubicmap(cubicmap.getCImg(), cubeSize.getCVector())));
        }
    }
}