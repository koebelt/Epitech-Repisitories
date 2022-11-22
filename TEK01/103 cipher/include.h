/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** include.h
*/

#ifndef INCLUDE_H_
# define INCLUDE_H_

#include <stdlib.h>
#include <stdio.h>

int my_strlen(char const *str);
float **str_to_matrix(char *str, int collumns, int ligns);
float **transpose(float **matrix, int collumns, int ligns);
int my_space_nbr(char *str);
void encrypt(char **);
float **two_matrix(float **matrix, float **matrix2, int i, int j, int);
float cofactor(float **matrix, int i, int j, int);
float matrix_determinant(float **matrix, int);
int find_lines_nbr(char *str, int collumns);
int find_lines_nbr_decrypt(char *str, int collumns);
float **multiply_matrix(float **matrix1, float **matrix2, int length_matrix, int height_matrix);
float **str_to_matrix_decrypt(char **, int, int);
int my_getnbr(char *str);
char **my_str_to_word_array(char const *str);
float **inverse_matrix(float **matrix, float **matrix2, int);
float determinant(float **matrix);
void usage(void);
int error_management(int ac, char **av);
void disp_matrix(float **matrix, int collumns, int ligns);

#endif /* INCLUDE_H_ */
