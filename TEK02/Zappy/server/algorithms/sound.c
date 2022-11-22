/*
** EPITECH PROJECT, 2022
** server
** File description:
** sound
*/

#include "../objects/vector.h"
#include "./sound.h"
#include <math.h>

t_node *create_node(t_position position)
{
    struct s_node *new_node = malloc(sizeof(struct s_node));
    t_position *new_position = malloc(sizeof(t_position));

    if (!new_position || !new_node)
        return (0);
    new_position->f = position.f;
    new_position->g = position.g;
    new_position->h = position.h;
    new_position->position = position.position;
    new_node->object = new_position;
    return (new_node);
}

static t_node *find_best_node(struct listnodes *list)
{
    t_node *node = list->tqh_first;

    for (t_node *np = list->tqh_first; np != NULL; np = np->entries.tqe_next) {
        if (np->object->f < node->object->f)
            node = np;
    }
    return (node);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function that find the shortest vector beetween two point
** @param eye_dir (VectorClass*): The eye direction 
** @param target (VectorClass*): Position of the signal that coming from
**
** @return node that been found one time before end
**/
t_node *find_sound_direction(VectorClass *emitterPos, VectorClass *target,
int sizeX, int sizeY)
{
    struct listnodes open_list = {0};
    struct listnodes closed_list = {0};
    t_node *current = NULL;
    t_node *start = create_node((t_position) {0, 0, 0, emitterPos});
    t_node *end = create_node((t_position) {0, 0, 0, target});

    TAILQ_INIT(&open_list);
    TAILQ_INIT(&closed_list);
    TAILQ_INSERT_TAIL(&open_list, start, entries);
    while (open_list.tqh_first != NULL) {
        current = find_best_node(&open_list);
        TAILQ_REMOVE(&open_list, current, entries);
        if (eq(current->object->position, end->object->position))
            return (closed_list.tqh_first);
        TAILQ_INSERT_HEAD(&closed_list, current, entries);
        for (int r = -1; r <= 1; r++)
            find_sound_direction_next((t_utils) {&open_list, &closed_list,
            current, end}, sizeX, sizeY, r);
    }
    return (NULL);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function get_direction_number: Get the linked number of a specific
** direction
** @param eye_dir (VectorClass*): The eye direction 
** @param target (VectorClass*): Position of the signal that coming from
**
** @return direction that have been found
**/
int get_direction_number(VectorClass *eye_dir, VectorClass *target)
{
    double angle = atan2(target->y - eye_dir->y, target->x - eye_dir->x) *
    360.f / M_PI;
    int count = 1;
    double temp = 360.f - (45.f * (double) count); 

    angle = abs(angle);
    for (; angle > 0 && temp > angle; temp = 360.f - (45.f * (double) count),
    count++);
    return (count);
}