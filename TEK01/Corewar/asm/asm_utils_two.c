/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** asm_utils_two
*/

#include "../include/header.h"

void read_header_next(list_t *tmp, int j, header_t *header)
{
    char *str = NULL;
    void *values[] = {&header->prog_name, &header->comment};
    char *names[] = {NAME_CMD_STRING, COMMENT_CMD_STRING};

    if (tmp->id != 100 && !my_strcmp(tmp->ptr.line.type, names[j])) {
        str = get_str(tmp->ptr.line.op.args[0]);
        my_memcpy(values[j], str, my_strlen(str));
    }
}

void fill_line_next(list_t *element)
{
    for (int i = 0; element->ptr.line.op.args[i]; i++) {
        switch (element->ptr.line.op.args[i][0]) {
            case 'r':
                element->ptr.line.op.type[i] = T_REG;
                break;
            case '%':
                element->ptr.line.op.type[i] = T_DIR;
                break;
            default:
                element->ptr.line.op.type[i] = T_IND;
        }
    }
}

void put_in_cmdlist_next(list_t **list, list_t *element, list_t *tmp)
{
    element->next = NULL;
    if (*list == NULL) {
        *list = element;
        element->ptr.number = 0;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        element->ptr.number = tmp->ptr.number + 1;
        tmp->next = element;
    }
}

void put_in_cmdlist_second(char **tab, list_t *element, list_t **list,
list_t *tmp)
{
    fill_empty_function(tab, element, list);
    element->next = NULL;
    if (*list == NULL) {
        *list = element;
        element->ptr.number = 0;
    } else {
        while (tmp->next != NULL)
            tmp = tmp->next;
        element->ptr.number = tmp->ptr.number + 1;
        tmp->next = element;
    }
}

void calc_size_of_line(list_t *element)
{
    element->ptr.line.nb_bytes = has_coding_byte(element->ptr.line.type) ?
    2 : 1;
    for (int i = 0; i < 4; ++i) {
        if (element->ptr.line.op.type[i] == T_DIR) {
            element->ptr.line.nb_bytes +=  is_index(element->ptr.line.type) ?
            T_IND : T_DIR;
        } else
            element->ptr.line.nb_bytes += element->ptr.line.op.type[i];
    }
}