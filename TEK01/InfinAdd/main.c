/*
** EPITECH PROJECT, 2020
** main
** File description:
** main for the add_inf prog
*/

#include <stdlib.h>
#include "./include/my.h"

int my_is_neg(char *str)
{
    if (str[0] == '-')
        return (1);
    else
        return (0);
}

int my_putstr0(char const *str)
{
    int i = 0;
    int is_null = 1;

    while (str[i] != '\0') {
        if (str[i] != '0' || is_null == 0) {
            my_putchar(str[i]);
            is_null = 0;
        }
        i += 1;
    }
}

int check_num(char **data)
{
    for (int i = 0; data[1][i] != '\0'; ++i)
        if ((data[1][i] >= '0' && data[1][i] <= '9') || data[1][0] == '-')
            return (0);
    for (int i = 0; data[2][i] != '\0'; ++i)
        if ((data[2][i] >= '0' && data[2][i] <= '9') || data[2][0] == '-')
            return (0);
    return (1);
}

int main(int argc, char **argv)
{
    if (argc != 3)
        return (84);
    if (my_is_neg(argv[1]) == 1 && my_is_neg(argv[2]) == 1) {
        argv[1]++;
        argv[2]++;
        my_putchar('-');                                                                                                           
        infin_add(argv[1], argv[2]);
    } else if (my_is_neg(argv[1]) == 1 || my_is_neg(argv[2]) == 1) {
        infin_sub(argv[1], argv[2]);
    } else {
        infin_add(argv[1], argv[2]);
    }
    my_putchar('\n');
    return (0);
}
