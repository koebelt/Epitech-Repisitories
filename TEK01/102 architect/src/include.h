/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-matheo.vitali
** File description:
** include.h
*/
#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef INCLUDE_H_
#define INCLUDE_H_

int str_to_int(char *);
float str_to_float(char *);
float **set_matrix(void);
float *matrix_and_vector_mult(float **, float *);
float **matrix_and_matrix_mult(float **, float **);
void disp_matrix(float **, float *);
float **rotation(char **, float **, int *);
float **translation(char **, float **, int *);
float **scaling(char **, float **, int *);
float **reflection(char **, float **, int *);
int error_handling(char **av, int ac);
int check_for_float(char *str);

#endif /* INCLUDE_H_ */
