/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** vector
*/

#include "./vector.h"
#include "../system/new.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Vector Class
** @param this (VectorClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void vector_ctor(VectorClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Str function for Vector Class
** @param this (VectorClass*): Pointer on class
**
** @return Desired Vector has string
**/
char *vector_str(VectorClass *this)
{
    char *buffer = NULL;

    asprintf(&buffer, "%d %d", this->x, this->y);
    return (buffer);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Combine two vector in one
** @param this (VectorClass*): Pointer on Vector class
** @param other (VectorClass*): Pointer on other Vector class
**
** @return New Vector that combine with addition
**/
VectorClass *vector_add(VectorClass *this, VectorClass *other)
{
    this->x += other->x;
    this->y += other->y;
    return (this);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Combine two vector in one
** @param this (VectorClass*): Pointer on Vector class
** @param other (VectorClass*): Pointer on other Vector class
**
** @return New Vector that combine with substraction
**/
VectorClass *vector_sub(VectorClass *this, VectorClass *other)
{
    return (new(Vector, this->x - other->x, this->y - other->y));
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Combine two vector in one
** @param this (VectorClass*): Pointer on Vector class
** @param other (VectorClass*): Pointer on other Vector class
**
** @return New Vector that combine with multiplication
**/
VectorClass *vector_mul(VectorClass *this, int mult)
{
    return (new(Vector, this->x * mult, this->y * mult));
}