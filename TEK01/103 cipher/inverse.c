/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** inverse.c
*/

#include "include.h"

float **inverse(float **matrix)
{
    float **buffer = matrix;
    matrix[0][0] = buffer[1][1];
    matrix[0][1] = -buffer[0][1];
    matrix[1][0] = -buffer[1][0];
    matrix[1][1] = buffer[0][0];
    return (matrix);
}

float **inverse_three_matrix(float **matrix, float **matrix2, int key_len)
{
    for (int i = 0; i < key_len; i += 1) {
        for (int a = 0; a < key_len; a += 1)
            matrix2[i][a] = cofactor(matrix, i, a, key_len);
    }
    matrix2 = transpose(matrix2, key_len, key_len);
    for (int i = 0; i < key_len; i += 1) {
        for (int a = 0; a < key_len; a += 1) {
            if (matrix_determinant(matrix, key_len) == 0)
                exit(84);
            matrix2[i][a] = matrix2[i][a] * (1 / matrix_determinant(matrix, key_len));
        }
    }
    return (matrix2);
}

float **inverse_two_matrix(float **matrix, float **matrix2, int key_len)
{
    float det = determinant(matrix);
    float **buffer = malloc(sizeof(float *) * key_len);

    for(int i = 0; i < key_len; i += 1)
        buffer[i] = malloc(sizeof(float) * key_len);
    buffer[0][0] = matrix[1][1];
    buffer[0][1] = -matrix[0][1];
    buffer[1][0] = -matrix[1][0];
    buffer[1][1] = matrix[0][0];
    if (det == 0)
        exit(84);
    for (int i = 0; i < key_len; i += 1) {
        for (int a = 0; a < key_len; a += 1)
            matrix2[i][a] = buffer[i][a] * (1 / det);
    }
    return (matrix2);
}

float **inverse_matrix(float **matrix, float **matrix2, int key_len)
{
    if (key_len == 3)
        matrix2 = inverse_three_matrix(matrix, matrix2, key_len);
    else if (key_len == 1)
        matrix2[0][0] = 1 / matrix[0][0];
    else
        matrix2 = inverse_two_matrix(matrix, matrix2, key_len);
    return (matrix2);
}
