/*
** EPITECH PROJECT, 2021
** B-CPE-201-STG-2-1-corewar-thibaut.ruscher
** File description:
** write_on_file
*/

#include "../include/header.h"

void fill_line(char **tab, list_t *element, list_t **list)
{
    element->id += 1;
    for (int i = 0; i < 4; ++i)
        element->ptr.line.op.type[i] = 0;
    element->ptr.line.type = tab[0];
    if (element->ptr.line.type[my_strlen(element->ptr.line.type) - 1] == '\n')
        element->ptr.line.type[my_strlen(element->ptr.line.type) - 1] = '\0';
    if (tab[1]) {
        element->ptr.line.op.args = my_str_to_word_array(tab[1],
        ", \t\v\f\r\n");
    } else
        element->ptr.line.op.args = NULL;
    element->ptr.line.op.mnemonique = tab[0];
    element->ptr.line.op.nbr_args = my_tab_len(element->ptr.line.op.args);
    fill_line_next(element);
    if (element->ptr.line.type[0] != '.')
        calc_size_of_line(element);
    for (list_t *tmp = *list; tmp != NULL; tmp = tmp->next)
        if (tmp->id != 100)
            tmp->ptr.line.type[0] != '.' ? element->ptr.function.adress +=
            tmp->ptr.line.nb_bytes : 0;
    check_line(&element->ptr.line);
}

void fill_function(char **tab, list_t *element, list_t **list)
{
    element->id += 100;
    element->ptr.function.name = tab[0];
    element->ptr.line.type = tab[0];
    check_label_name(element->ptr.function.name);
    tab[0][my_strlen(tab[0]) - 1] == ':' ?
    element->ptr.function.name[my_strlen(tab[0]) - 1] = '\0' : 0;
    fill_line(my_nstr_to_array(tab[1], " \t\n\v\f\r", 2), element, list);
}

void fill_empty_function(char **tab, list_t *element, list_t **list)
{
    element->id = 100;
    element->ptr.function.name = tab[0];
    check_label_name(element->ptr.function.name);
    tab[0][my_strlen(tab[0]) - 1] == ':' ?
    element->ptr.function.name[my_strlen(tab[0]) - 1] = '\0' : 0;
    element->ptr.line.nb_bytes = 0;
    element->ptr.function.adress = 0;
    for (list_t *tmp = *list; tmp != NULL; tmp = tmp->next)
        tmp->ptr.line.type[0] != '.' ? element->ptr.function.adress +=
        tmp->ptr.line.nb_bytes : 0;
}

void put_in_cmdlist(char *cmdline, list_t **list)
{
    list_t *element;
    list_t *tmp = *list;
    char **tab = my_nstr_to_array(cmdline, " \t\v\f\r\n", 2);

    element = malloc(sizeof(*element));
    if (element == NULL)
        exit(84);
    if (tab[1]) {
        element->ptr.function.adress = 0;
        element->id = 0;
        if (my_strcmp(tab[0], ".name") && my_strcmp(tab[0], ".comment")) {
            tab[0][my_strlen(tab[0]) - 1] == ':' ?
            fill_function(tab, element, list) : fill_line(tab, element, list);
        } else {
            element->ptr.line.op.args = malloc(sizeof(char *) * 1);
            element->ptr.line.type = tab[0];
            element->ptr.line.op.args[0] = tab[1];
        }
        put_in_cmdlist_next(list, element, tmp);
    } else if (tab[0][my_strlen(tab[0]) - 1] == ':')
        put_in_cmdlist_second(tab, element, list, tmp);
}

int main(int ac, char **av)
{
    FILE *temp;

    if (ac != 2)
        return (84);
    if (!end_with_s(av[1]))
        return (84);
    temp = fopen(add_cor_at_the_end(av[1]), "w");
    if (temp == NULL)
        return (84);
    start_reading(av[1], temp);
    fclose(temp);
}