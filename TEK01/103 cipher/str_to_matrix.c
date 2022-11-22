/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** returns a matrix depending on the given string avd collumn number
*/

#include <stdlib.h>
#include "include.h"

float **str_to_matrix(char *str, int collumns, int ligns)
{
    float **matrix = malloc(sizeof(float *) * (ligns + 1));

    for (int i = 0; i < ligns; i++)
        matrix[i] = malloc(sizeof(float) * collumns);
    for (int i = 0, k = 0; i < ligns; i++) {
        for (int j = 0; j < collumns; j++, k++) {
            matrix[i][j] = (k <= my_strlen(str)) ? str[k] : 0;
        }
    }
    return(matrix);
}

float **str_to_matrix_decrypt(char **tab, int collumns, int ligns)
{
    float **matrix = malloc(sizeof(float *) * (ligns + 1));

    for (int i = 0; i < ligns; i++)
        matrix[i] = malloc(sizeof(float) * collumns);
    for (int i = 0, k = 0; i < ligns; i++) {
        for (int j = 0; j < collumns; j++, k++) {
            matrix[i][j] = my_getnbr(tab[k]);
        }
    }
    return(matrix);
}


int find_lines_nbr(char *str, int collumns)
{
    float ligns_approx = (float)my_strlen(str) / (float)collumns;
    int ligns_int = my_strlen(str) / collumns;
    int ligns = ligns_approx > ligns_int ? ligns_int + 1 : ligns_int;

    return (ligns);
}

int find_lines_nbr_decrypt(char *str, int collumns)
{
    float ligns_approx = (float)my_space_nbr(str) / (float)collumns;
    int ligns_int = my_space_nbr(str) / collumns;
    int ligns = ligns_approx > ligns_int ? ligns_int + 1 : ligns_int;

    return (ligns);
}
