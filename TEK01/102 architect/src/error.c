/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-matheo.vitali
** File description:
** error
*/

#include "include.h"

int check_for_flag(char **av, int i)
{
    if (av[i + 3][1] == 't' || av[i + 3][1] == 's'
    || av[i + 3][1] == 'r' || av[i + 3][1] == 'z')
        return (1);
    else
        return (0);
}

int check_for_flag2(char **av, int i)
{
    if (av[i + 2][1] == 't' || av[i + 2][1] == 's'
    || av[i + 2][1] == 'r' || av[i + 2][1] == 'z')
        return (1);
    else
        return (0);
}

int flags_t_and_z(char **av, int i)
{
    if (av[i + 1] == NULL || av[i + 2] == NULL ||
    check_for_float(av[i + 1]) == 0 || check_for_float(av[i + 2]) == 0)
        return (84);
    if (av[i + 3] != NULL) {
        if (check_for_float(av[i + 3]) == 1 || check_for_flag(av, i) == 0) {
            return (84);
        }
    }
    return (0);
}

int flags_s_and_r(char **av, int i)
{
    if (av[i + 1] == NULL || check_for_float(av[i + 1]) == 0) {
        return (84);
    }
    if (av[i + 2] != NULL) {
        if (check_for_float(av[i + 2]) == 1 || check_for_flag2(av, i) == 0) {
            return (84);
        }
    }
    return (0);
}

int error_handling(char **av, int ac)
{
    int error = 0;

    if (ac < 3 || check_for_float(av[1]) != 1 || check_for_float(av[2]) != 1)
        return (84);
    for (int i = 1; av[i] != NULL; i += 1) {
        if (av[i][1] == 't' || av[i][1] == 'z') {
            error = flags_t_and_z(av, i);
        }else if (av[i][1] == 's' || av[i][1] == 'r') {
            error = flags_s_and_r(av, i);
        }
        if (error == 84)
            return (84);
    }
}