/*
** EPITECH PROJECT, 2020
** bistromatique
** File description:
** error managing
*/

#include "include/my.h"

int check_opbase(char *base, char *op)
{
    int error = 0;

    if (my_strlen(op) != 7)
        return (84);
    for (int i = 0; base[i]; ++i)
        for (int j = 0; op[j]; ++j)
            error = base[i] == op[j] ? 84 : error;
    for (int i = 0; base[i]; ++i)
        for (int j = i + 1; base[j]; ++j)
            error = base[i] == base[j] ? 84 : error;
    for (int i = 0; op[i]; ++i)
        for (int j = i + 1; op[j]; ++j)
            error = op[i] == op[j] ? 84 : error;
    return (error);
}

int check_str(char *str, char *base, char *op)
{
    int count = 0;
    int match = 0;

    for (int i = 0; str[i]; ++i) {
        count = str[i] == op[0] ? count + 1 : count;
        count = str[i] == op[1] ? count - 1 : count;
    }
    if (count || !(*str))
        return (84);
    for (int i = 0; str[i]; ++i) {
        match = 0;
        for (int j = 0; base[j]; ++j)
            match = base[j] == str[i] ? 1 : match;
        for (int j = 0; op[j]; ++j)
            match = op[j] == str[i] ? 1 : match;
        if (!match)
            return (84);
    }
    return (0);
}

int check_parent_format(char *str, char *base, char *op)
{
    int error = 0;

    for (int i = 0; str[i]; ++i)
        for (int j = 0; base[j]; ++j) {
            error = str[i] == base[j] && str[i + 1] == op[0] ? 84 : error;
            error = str[i] == op[1] && str[i + 1] == base[j] ? 84 : error;
        }
    return (error);
}

int check_op_format(char *str, char *op)
{
    int error = 0;

    for (int i = 0; str[i]; ++i) {
        for (int j = 2; op[j]; ++j) {
            error = str[i] == op[j] && str[i + 1] == op[4] ? 84 : error;
            error = str[i] == op[j] && str[i + 1] == op[5] ? 84 : error;
            error = str[i] == op[j] && str[i + 1] == op[6] ? 84 : error;
            error = str[i] == op[j] && !str[i + 1] ? 84 : error;
        }
        for (int j = 4; op[j]; ++j) {
            error = str[i] == op[2] && str[i + 1] == op[j] ? 84 : error;
            error = str[i] == op[3] && str[i + 1] == op[j] ? 84 : error;
        }
    }
    return (error);
}

int errors(char *str, char *base, char *op)
{
    if (check_opbase(base, op) || check_str(str, base, op)) {
        my_putstr("syntax error\n");
        return (84);
    } else if (check_parent_format(str, base, op)
        || check_op_format(str, op)) {
        my_putstr("syntax error\n");
        return (84);
    }
    return (0);
}
