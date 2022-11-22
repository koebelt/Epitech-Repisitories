/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-matheo.vitali
** File description:
** operations.c
*/

#include "include.h"

float **rotation(char **av, float **matrix, int *i)
{
    float **new_matrix = set_matrix();

    printf ("Rotation by a %s degree angle\n", av[*i + 1]);
    *i += 1;
    new_matrix[0][0] = cos((str_to_float(av[*i])) * 0.0174532);
    new_matrix[0][1] = sin((str_to_float(av[*i])) * 0.0174532) * -1;
    new_matrix[1][0] = sin((str_to_float(av[*i])) * 0.0174532);
    new_matrix[1][1] = cos((str_to_float(av[*i])) * 0.0174532);
    matrix = matrix_and_matrix_mult(new_matrix, matrix);
    return (matrix);
}

float **reflection(char **av, float **matrix, int *i)
{
    float **new_matrix = set_matrix();

    printf ("Reflection over an axis with an inclination angle of %s degrees\n",
    av[*i + 1]);
    *i += 1;
    new_matrix[0][0] = cos((2 * (str_to_float(av[*i]) * 0.0174532)));
    new_matrix[0][1] = sin((2 * (str_to_float(av[*i]) * 0.0174532)));
    new_matrix[1][0] = sin((2 * (str_to_float(av[*i]) * 0.0174532)));
    new_matrix[1][1] = cos((2 * (str_to_float(av[*i]) * 0.0174532))) * -1;
    matrix = matrix_and_matrix_mult(new_matrix, matrix);
    return (matrix);
}

float **scaling(char **av, float **matrix, int *i)
{
    float **new_matrix = set_matrix();

    printf ("Scaling by factors %s and %s\n", av[*i + 1], av[*i + 2]);
    *i += 1;
    new_matrix[0][0] = str_to_float(av[*i]);
    *i += 1;
    new_matrix[1][1] = str_to_float(av[*i]);
    matrix = matrix_and_matrix_mult(new_matrix, matrix);
    return (matrix);
}

float **translation(char **av, float **matrix, int *i)
{
    float **new_matrix = set_matrix();

    printf ("Translation along vector (%s, %s)\n", av[*i + 1], av[*i + 2]);
    *i += 1;
    new_matrix[0][2] = str_to_float(av[*i]);
    *i += 1;
    new_matrix[1][2] = str_to_float(av[*i]);
    matrix = matrix_and_matrix_mult(new_matrix, matrix);
    return (matrix);
}
