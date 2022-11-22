/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team
*/

#ifndef VECTOR_H_
    #define VECTOR_H_

    #define _GNU_SOURCE

    #include <sys/queue.h>
    #include <stdio.h>
    #include "./player.h"
    #include "../system/object.h"
    #include "../includes/list.h"
    #include "../includes/prerequisite.h"

typedef struct {
    Class   base;
    int x;
    int y;
} VectorClass;

void vector_ctor(VectorClass *this, va_list *args);
void vector_dtor(VectorClass *this);
char *vector_str(VectorClass *obj);

VectorClass *vector_add(VectorClass *this, VectorClass *other);
VectorClass *vector_sub(VectorClass *this, VectorClass *other);
VectorClass *vector_mul(VectorClass *this, int mult);
VectorClass *vector_mod(VectorClass *this, int, int);
bool vector_eq(VectorClass *this, VectorClass *other);
bool vector_gt(VectorClass *this, VectorClass *other);

static const VectorClass _vectordescription = {
    (Class) {
        .__size__ = sizeof(VectorClass),
        .__name__ = "Team",
        .__ctor__ = (ctor_t)&vector_ctor,
        .__dtor__ = NULL,
        .__str__ = (to_string_t)&vector_str,
        .__add__ = (binary_operator_t)&vector_add,
        .__sub__ = (binary_operator_t)&vector_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = (binary_comparator_t)&vector_eq,
        .__gt__ = (binary_comparator_t)&vector_gt,
        .__lt__ = NULL,
        .__functions__ = {
            vector_mod,
            vector_mul
        }
    },
    .x = 0,
    .y = 0
};

static const Class *Vector = (const Class *)&_vectordescription;

    #define Vector_Mod(o, x, y) ((VectorClass *(*)(VectorClass *, int, int))\
    find(o, 0))(o, x, y)
    #define Vector_Mul(o, m) ((VectorClass *(*)(VectorClass *, int))\
    find(o, 1))(o, m)

#endif /* !VECTOR_H_ */
