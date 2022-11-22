/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-101pong-matheo.vitali
** File description:
** error
*/

#include <stdlib.h>

int verif_arguments(char **av, int i, int a)
{
    if ((av[i][a] > 47 && av[i][a] < 58) || av[i][a] == '.' || av[i][a] == '-')
        return (0);
    printf("%s\n", "Wrong arguments");
    return (84);
}

int verif_time(char **av, int i)
{
    for (int i = 0; av[7][i] != '\0'; i += 1) {
        if (av[7][i] == '-') {
            printf("%s\n", "Wrong time");
            return (84);
        }
        else if (av[7][i] == '.') {
            printf("%s\n", "Wrong time");
            return (84);
        }
    }
    return (0);
}

int error_handling(int ac, char **av)
{
    int res = 0;
    int i = 1;

    if (ac > 8 || ac < 8 ) {
        printf("%s\n", "Wrong number of arguments");
        return (84);
    }
    for (; av[i] != NULL && res != 84; i += 1) {
        for (int a = 0; av[i][a] != '\0' && res != 84; a += 1) {
            res += verif_arguments(av, i, a);
        }
    }
    if (res > 0)
        return (84);
    i -= 1;
    res = verif_time(av, i);
    if (res == 84)
        return (84);
    return (0);
}