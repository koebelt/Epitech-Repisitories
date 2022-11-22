/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** deter.c
*/

#include "include.h"

float determinant(float **matrix)
{
    float deter = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    return (deter);
}

float matrix_determinant(float **matrix, int key_len)
{
    float det = 0;

    for (int i = 0; i < key_len; i += 1)
        det += matrix[0][i] * cofactor(matrix, 0, i, key_len);
    return (det);
}
