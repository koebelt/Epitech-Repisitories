/*
** EPITECH PROJECT, 2020
** bistro matic
** File description:
** main
*/

#include "include/my.h"
#include "include/bistro.h"
#include <stdlib.h>
#include <unistd.h>

int usage(int ac)
{
    if (ac == 4)
        return (0);
    return (84);
}

char *reading(int len)
{
    char *str = malloc(sizeof(char) * (len + 1));

    if (!str)
        return (NULL);
    read(0, str, len + 1);
    str[len] = '\0';
    return (str);
}

int main(int ac, char **av)
{
    char *expr;

    if (usage(ac) || !(expr = reading(my_getnbr(av[3]))) ||
        errors(expr, av[1], av[2]))
        return (84);
    if (!(expr = str_format(expr, av[2])) || !(expr = eval_expr(expr, av[1])))
        return (84);
    my_putstr(expr);
    my_putchar('\n');
    free(expr);
    return (0);
}
