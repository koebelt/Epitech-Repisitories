/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-matheo.vitali
** File description:
** matrix.c
*/

#include "include.h"

float **set_matrix(void)
{
    int size = 0;
    float **matrix = malloc(sizeof(float *) * 4);

    for (; size != 3; size += 1) {
        matrix[size] = malloc(sizeof(float) * 3);
    }
    matrix[size] = NULL;
    matrix[0][0] = 1;
    matrix[0][1] = 0;
    matrix[0][2] = 0;
    matrix[1][0] = 0;
    matrix[1][1] = 1;
    matrix[1][2] = 0;
    matrix[2][0] = 0;
    matrix[2][1] = 0;
    matrix[2][2] = 1;
    return (matrix);
}

float *matrix_and_vector_mult(float **matrix, float *nbr)
{
    float *nbr1 = malloc(sizeof(float) * 2);

    nbr1[0] = nbr[0] * matrix[0][0] + nbr[1] * matrix[0][1] + 1 * matrix[0][2];
    nbr1[1] = nbr[0] * matrix[1][0] + nbr[1] * matrix[1][1] + 1 * matrix[1][2];
    return (nbr1);
}

float **matrix_and_matrix_mult(float **matrix, float **matrix2)
{
    float **matrix_res = set_matrix();
    int i = 0;
    int size = 0;
    int a = 0;

    for (int big_s = 0; big_s != 3; big_s += 1) {
        matrix_res[big_s][a] = matrix[big_s][i] * matrix2[size][i] +
        matrix[big_s][i + 1] * matrix2[size + 1][i] +
        matrix[big_s][i + 2] * matrix2[size + 2][i];
        matrix_res[big_s][a + 1] = matrix[big_s][i] * matrix2[size][i + 1] +
        matrix[big_s][i + 1] * matrix2[size + 1][i + 1] +
        matrix[big_s][i + 2] * matrix2[size + 2][i + 1];
        matrix_res[big_s][a + 2] = matrix[big_s][i] * matrix2[size][i + 2] +
        matrix[big_s][i + 1] * matrix2[size + 1][i + 2] +
        matrix[big_s][i + 2] * matrix2[size + 2][i + 2];
    }
    return (matrix_res);
}

void disp_matrix(float **matrix, float *nbr)
{
    for (int size = 0; size != 3; size += 1) {
        for (int i = 0; i != 3; i += 1)
            printf("%.2f%s", matrix[size][i], i != 2 ? "\t" : "");
        printf("\n");
    }
    printf("(%.2f, %.2f) => ", nbr[0], nbr[1]);
    nbr = matrix_and_vector_mult(matrix, nbr);
    printf("(%.2f, %.2f)\n", nbr[0], nbr[1]);
}
