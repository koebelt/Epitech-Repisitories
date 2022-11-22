/*
** EPITECH PROJECT, 2022
** server
** File description:
** sound_next
*/

#include "./sound.h"
#include "../objects/vector.h"
#include "../system/new.h"
#include <math.h>

static double get_distance(VectorClass *start, VectorClass *target, int sizeX,
int sizeY)
{
    double temp = sqrt(pow(start->x - target->x, 2) + pow(start->y -
    target->y, 2));
    double temp1 = sqrt(pow(start->x - (target->x + sizeX), 2) + pow(start->y -
    target->y, 2));
    double temp2 = sqrt(pow(start->x - target->x, 2) + pow(start->y -
    (target->y + sizeY), 2));
    double temp3 = sqrt(pow((start->x + sizeX) - target->x, 2) + pow(start->y -
    target->y, 2));
    double temp4 = sqrt(pow(start->x - target->x, 2) + pow((start->y + sizeY) -
    target->y, 2));

    if (temp < temp1 && temp < temp2 && temp < temp3 && temp < temp4)
        return (temp);
    if (temp1 < temp && temp1 < temp2 && temp1 < temp3 && temp1 < temp4)
        return (temp1);
    if (temp2 < temp && temp2 < temp3 && temp2 < temp4 && temp2 < temp1)
        return (temp2);
    if (temp3 < temp && temp3 < temp2 && temp3 < temp4 && temp3 < temp1)
        return (temp3);
    return (temp4);
}

static t_node *list_contains(struct listnodes *list, VectorClass *position)
{
    for (t_node *np = list->tqh_first; np != NULL; np = np->entries.tqe_next) {
        if (eq(position, np->object->position))
            return (np);
    }
    return (NULL);
}

int find_sound_direction_next(t_utils utils, int sizeX, int sizeY, int row)
{
    t_node *child = NULL;
    t_position tmp = {0};
    t_node *tmep = NULL;

    for (int c = -1; c <= 1; c++) {
        tmp.position = Vector_Mod(addition(new(Vector, c, row),
        utils.current->object->position), sizeX, sizeY);
        if (list_contains(utils.closelist, tmp.position))
            continue;
        tmp.g = utils.current->object->g + get_distance(utils.current->\
        object->position, tmp.position, sizeX, sizeY);
        tmp.h = get_distance(utils.end->object->position, tmp.position,
        sizeX, sizeY);
        tmp.f = tmp.g + tmp.h;
        child = create_node(tmp);
        if ((tmep = list_contains(utils.openlist, tmp.position)))
            if (tmp.g > tmep->object->g)
                continue;
        TAILQ_INSERT_TAIL(utils.openlist, child, entries);
    }
}