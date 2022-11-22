/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-matheo.vitali
** File description:
** main.c
*/

#include "include.h"

int index_finder(char *tab, char c)
{
    for (int i = 0; tab[i]; ++i) {
        if (tab[i] == c)
            return (i);
        }
    return (-1);
}

int usage(char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        printf("USAGE\n");
        printf("\t./102architect x y transfo1 arg11 [arg12] [transfo2 arg12");
        printf(" [arg22]] ...\n\n");
        printf("DESCRIPTION\n");
        printf("\tx  abscissa of the original point\n");
        printf("\ty  ordinate of the original point\n\n");
        printf("\ttransfo arg1 [arg2]\n");
        printf("\t-t i j\ttranslation along vector (i, j)\n");
        printf("\t-z m n\tscaling by factors m (x-axis) and n (y-axis)\n");
        printf("\t-r d\trotation centered in O by a d degree angle\n");
        printf("\t-s d\treflection over the axis passing through O with an");
        printf(" inclination\n");
        printf("\t\tangle of d degrees\n");
        return (0);
    }
}

int main(int ac, char **av)
{
    float **(*function_tab[4]) (char **, float **, int *) = {translation,
        rotation, scaling, reflection};
    char index_tab[5] =  {'t', 'r', 'z', 's', 0};
    float *nbr = malloc(sizeof(float) * 4);
    float **matrix = set_matrix();

    if (error_handling(av, ac) == 84)
        return (84);
    av[ac - 1] == NULL;
    if (usage(av) == 0)
        return (0);
    nbr[0] = str_to_int(av[1]);
    nbr[1] = str_to_int(av[2]);
    for (int i = 3; av[i]; ++i) {
        if (av[i][0] == '-') {
            int index = index_finder(index_tab, av[i][1]);
            matrix = (*function_tab[index]) (av, matrix, &i);
        }
    }
    disp_matrix(matrix, nbr);
}
