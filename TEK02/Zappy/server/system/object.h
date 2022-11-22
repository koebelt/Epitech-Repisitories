/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** object
*/

#ifndef OBJECT_H_
    #define OBJECT_H_

    #include <sys/types.h>
    #include <sys/queue.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <string.h>
    #include "raise.h"

    #define MAX_FUNCTIONS 30

typedef void Object;
typedef void (*ctor_t)(Object *t, va_list *args);
typedef void (*dtor_t)(Object *t);
typedef char *(*to_string_t)(Object *t);
typedef Object *(*binary_operator_t)(const Object *t, const Object *other);
typedef bool (*binary_comparator_t)(const Object *t, const Object *other);

typedef struct {
    const size_t        __size__;
    const char          *__name__;
    ctor_t              __ctor__;
    dtor_t              __dtor__;
    to_string_t         __str__;
    binary_operator_t   __add__;
    binary_operator_t   __sub__;
    binary_operator_t   __mul__;
    binary_operator_t   __div__;
    binary_comparator_t __eq__;
    binary_comparator_t __gt__;
    binary_comparator_t __lt__;
    void *__functions__[MAX_FUNCTIONS];
} Class;

#define str(o) (((Class *)o)->__str__ != NULL ? ((Class *)o)->__str__(o) :\
strdup(((Class *)o)->__name__))
#define addition(a, b) ((Class *)a)->__add__(a, b)
#define subtraction(a, b) ((Class *)a)->__sub__(a, b)
#define multiplication(a, b) ((Class *)a)->__mul__(a, b)
#define division(a, b) ((Class *)a)->__div__(a, b)
#define eq(a, b) ((Class *)a)->__eq__(a, b)
#define gt(a, b) ((Class *)a)->__gt__(a, b)
#define lt(a, b) ((Class *)a)->__lt__(a, b)
#define find(a, i) ((Class *)a)->__functions__[i]

#endif /* !OBJECT_H_ */
