/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** transpose.c
*/

#include <stdlib.h>
#include "include.h"

float **transpose(float **matrix, int collumns, int ligns)
{
    float **new_matrix = malloc(sizeof(float *) * collumns);

    for (int i = 0; i < collumns; ++i)
        new_matrix[i] = malloc(sizeof(float) * ligns);
    for (int i = 0; i < collumns; ++i)
        for (int j = 0; j < ligns; ++j) {
            new_matrix[i][j] += matrix[j][i];
        }
    return (new_matrix);
}
