/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** list
*/

#ifndef LIST_H_
    #define LIST_H_

    #include "../system/object.h"

    #define LIST_HEAD_OF(name, type) LIST_HEAD(name, type);
    #define LIST_OF(name, type, o) \
    struct name { \
        type *object; \
        LIST_ENTRY(name) entries; \
    } o; \

    #define TAIL_HEAD_OF(name, type) TAILQ_HEAD(name, type);
    #define TAIL_OF(name, type, o) \
    struct name { \
        type *object; \
        TAILQ_ENTRY(name) entries; \
    } o;

#endif /* !LIST_H_ */
