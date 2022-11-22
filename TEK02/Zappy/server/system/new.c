/*
** EPITECH PROJECT, 2022
** Rush2
** File description:
** new
*/

#include "new.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Create a new instance of a class
** @param class (Class*): Desired class to create
**
** @return new instance of class
**/
Object *new(const Class *class, ...)
{
    va_list ap;
    void *player_class = NULL;

    if (class == NULL)
        raise("NULL_CLASS");
    player_class = malloc(class->__size__);
    if (player_class == NULL)
        raise("Out of memory");
    va_start(ap, class);
    memcpy(player_class, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(player_class, &ap);
    va_end(ap);
    return (player_class);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Create a new instance of a class with an existing va_list
** @param class (Class*): Desired class to create
**
** @return new instance of class
**/
Object *va_new(const Class *class, va_list *ap)
{
    void *player_class = NULL;

    if (class == NULL)
        raise("NULL_CLASS");
    player_class = malloc(class->__size__);
    if (player_class == NULL)
        raise("Out of memory");
    memcpy(player_class, class, sizeof(Class));
    if (class->__ctor__)
        class->__ctor__(player_class, ap);
    return (player_class);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Delete an instance of a class
** @param class (Class*): Desired class to delete
**
** @return Nothing
**/
void delete(Object *ptr)
{
    Class *elem = ptr;

    if (ptr == NULL)
        raise("Cannot delete object");
    if (elem->__dtor__)
        elem->__dtor__(ptr);
    free(ptr);
}
