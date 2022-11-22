/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** error_handling
*/

#include "../include/header.h"

static int is_label_char(char c)
{
    for (int j = 0; LABEL_CHARS[j]; j++) {
        if (c == LABEL_CHARS[j])
            return (0);
    }
    return (1);
}

void check_label_name(char *fct_name)
{
    for (int i = 0; fct_name[i]; i++) {
        if (fct_name[i] != LABEL_CHAR && is_label_char(fct_name[i]))
            exit(84);
    }
}

static int is_a_valid_type(args_type_t tab, args_type_t op)
{
    switch (tab) {
        case T_REG:
            return (op == T_REG);
        case T_IND:
            return (op == T_IND);
        case (T_REG | T_IND):
            return (op == T_REG || op == T_IND);
        case (T_DIR):
            return (op == T_DIR);
        case (T_DIR | T_REG):
            return (op == T_DIR || op == T_REG);
        case (T_IND | T_DIR):
            return (op == T_IND || op == T_DIR);
        case (T_IND | T_DIR | T_REG):
            return (1);
    }
    return (0);
}

static void check_type_and_nb_line(line_t *line, int i)
{
    if (op_tab[i].nbr_args != line->op.nbr_args)
        exit (84);
    for (int j = 0; j < line->op.nbr_args; ++j) {
        if (is_a_valid_type(op_tab[i].type[j], line->op.type[j]));
        else
            exit(84);
    }
}

void check_line(line_t *line)
{
    int error = 84;

    if (!my_strcmp(line->type, ".name") || !my_strcmp(line->type, ".comment"))
        return;
    for (int i = 0; op_tab[i].code ; i++) {
        if (!my_strcmp(op_tab[i].mnemonique, line->op.mnemonique)) {
            error = 0;
            check_type_and_nb_line(line, i);
        }
    }
    if (error)
        exit(84);
}
