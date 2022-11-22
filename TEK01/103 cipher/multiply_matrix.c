/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** multiply_matrix.c
*/

#include <stdlib.h>
#include "include.h"

float **malloc_matrix(float **matrix, float **matrix2)
{
    float **matrix_res = NULL;
    int lines = 0;
    int column = 0;

    for (; matrix[lines] != NULL; lines += 1);
    matrix_res = malloc(sizeof(float *) * lines);
    for (; matrix2[0][column]; column += 1);
    for (int i = 0; matrix[i] != NULL; i += 1)
        matrix_res[i] = malloc(sizeof(float) * column);
    return (matrix_res);
}

float **multiply_matrix(float **matrix1, float **matrix2, int length_matrix, int height_matrix)
{
    float **matrix = malloc_matrix(matrix1, matrix2);
    int size2 = 0;
    int column2 = 0;
    int size_matrix = 0;

    for (int size = 0; size != height_matrix; size += 1, size_matrix += 1) {
        for (int column = 0; column != 3; column += 1) {
            for (; size2 != length_matrix; size2 += 1)
                matrix[size][size_matrix] += matrix1[size][size2] * matrix2[size2][column];
            size2 = 0;
            size_matrix += 1;
        }
        size_matrix = -1;
    }
    return (matrix);
}
