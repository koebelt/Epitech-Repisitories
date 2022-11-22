/*
** EPITECH PROJECT, 2022
** B-CCP-400-STG-4-1-panoramix-thomas.koebel
** File description:
** error_management
*/

#include "panoramix.h"


int isInt(char *str)
{
    for (int i = 0; i < strlen(str); i++)
        if (!isdigit(str[i]))
            return (0);
    return (1);
}

void print_usage(void)
{
    printf("USAGE: ./panoramix <nb_villagers> <pot_size> <nb_fights> \
<nb_refills>\nValues must be >0.\n");
}

int error_management(int ac, char **av)
{
    if (ac != 5) {
        print_usage();
        return (84);
    }
    for (int i = 1; i < ac; i++)
        if (!isInt(av[i])) {
            print_usage();
            return (84);
        }
    return (0);
}