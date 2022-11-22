/*
** EPITECH PROJECT, 2022
** server
** File description:
** sound
*/

#ifndef SOUND_H_
    #define SOUND_H_

    #include <sys/queue.h>
    #include "../objects/vector.h"

TAIL_HEAD_OF(listnodes, s_node);

typedef struct s_position {
    double g;
    double h;
    double f;
    VectorClass *position;
} t_position;

typedef TAIL_OF(s_node, t_position, nodes);
typedef struct s_node t_node;

typedef struct s_utils {
    struct listnodes *openlist;
    struct listnodes *closelist;
    t_node *current;
    t_node *end;
} t_utils;

t_node *find_sound_direction(VectorClass *emitterPos, VectorClass *target,
int sizeX, int sizeY);
int find_sound_direction_next(t_utils utils, int sizeX, int sizeY, int row);
t_node *create_node(t_position position);

int get_direction_number(VectorClass *eye_dir, VectorClass *target);

#endif /* !SOUND_H_ */
