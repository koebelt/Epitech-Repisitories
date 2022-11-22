/*
** EPITECH PROJECT, 2022
** server
** File description:
** vector_next
*/

#include "./vector.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Apply a modulo on vector class
** @param this (VectorClass*): Pointer on Vector class
** @param int (modx): Modulo to apply on x
** @param int (mody): Modulo to apply on y
**
** @return New Vector that been calculated
**/
VectorClass *vector_mod(VectorClass *this, int modx, int mody)
{
    if (this->x < 0)
        this->x = modx - 1;
    if (this->y < 0)
        this->y = mody - 1;
    this->x = this->x % modx;
    this->y = this->y % mody;
    return (this);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Check if two vector are equal
** @param this (VectorClass*): Pointer on Vector class
** @param other (VectorClass*): Pointer on other Vector class
**
** @return true if vector are equal else false
**/
bool vector_eq(VectorClass *this, VectorClass *other)
{
    return (this->x == other->x && this->y == other->y);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Check if vector is greater than other
** @param this (VectorClass*): Pointer on Vector class
** @param other (VectorClass*): Pointer on other Vector class
**
** @return true if vector is greater else false
**/
bool vector_gt(VectorClass *this, VectorClass *other)
{
    return (((this->x - other->x) + (this->y - other->y)) > 0);
}