/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** cofactor.c
*/

#include <stdlib.h>
#include "include.h"

float **two_matrix(float **matrix, float **matrix2, int i, int j, int key_len)
{
    int x = 0;
    int y = 0;

    for (int a = 0; a < key_len; a += 1, x += 1) {
        if (a == i) {
            a += 1;
        }
        for (int b = 0; b < key_len; b += 1) {
            if (b == j)
                b += 1;
            if (b < key_len && a < key_len) {
                matrix2[x][y] = matrix[a][b];
                y += 1;
            }
        }
        y = 0;
    }
    return (matrix2);
}

float cofactor(float **matrix, int i, int j, int key_len)
{
    float **matrix2 = malloc(sizeof(float *) * 2);
    float det = 0;

    for (int a = 0; a < 2; a += 1)
        matrix2[a] = malloc(sizeof(float) * 2);
    matrix2 = two_matrix(matrix, matrix2, i, j, key_len);
    det = (matrix2[0][0] * matrix2[1][1]) - (matrix2[0][1] * matrix2[1][0]);
    if ((i + j) % 2 != 0)
        det = det * -1;
    return (det);
}
