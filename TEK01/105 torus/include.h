/*
** EPITECH PROJECT, 2021
** B-MAT-100-STG-1-1-105torus-matheo.vitali
** File description:
** include
*/

#ifndef INCLUDE_H_
#define INCLUDE_H_

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define ABS(x) x < 0 ? -x : x

typedef struct coefficients {
    double a0;
    double a1;
    double a2;
    double a3;
    double a4;
} coef_t;

#endif /* !INCLUDE_H_ */
