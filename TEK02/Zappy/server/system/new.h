/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** new
*/

#ifndef NEW_H_
    #define NEW_H_

    #include "./object.h"

Object *new(const Class *class, ...);
Object *va_new(const Class *class, va_list *ap);
void delete(Object *ptr);

#endif /* !NEW_H_ */
