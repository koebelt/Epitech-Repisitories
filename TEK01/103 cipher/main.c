/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** main.c
*/

#include <stdlib.h>
#include "include.h"

void disp_matrix(float **matrix, int collumns, int ligns)
{

    for (int i = 0; i < ligns; ++i) {
        for (int j = 0; j < collumns; ++j) {
            printf("%.2f%s", matrix[i][j], (j < collumns - 1) ? "\t" : "");
        }
        printf("\n");
    }
}

int find_key_size(char *key)
{
    int len = my_strlen(key);

    if (len == 1)
        return (1);
    if (len <= 4)
        return (2);
    else
        return (3);
}

void decrypt(char **av)
{
    int key_len = find_key_size(av[2]);
    float **key = str_to_matrix(av[2], key_len, key_len);
    int collumns = key_len;
    int ligns = find_lines_nbr_decrypt(av[1], collumns);
    float **inversed_key = malloc(sizeof(float *) * key_len);
    float **matrix = str_to_matrix_decrypt(my_str_to_word_array(av[1]), collumns, ligns);

    for (int i = 0; i < key_len; ++i)
        inversed_key[i] = malloc(sizeof(float) * key_len);
    inversed_key = inverse_matrix(key, inversed_key, key_len);
    printf("Key matrix:\n");
    for(int i = 0; i < key_len; ++i) {
        for (int j = 0; j < key_len; ++j) {
            if (inversed_key[i][j] == 0)
                printf("0.0%s", ((j < key_len - 1) ? "\t" : ""));
            else
                printf("%.3f%s", inversed_key[i][j], ((j < key_len - 1) ? "\t" : ""));
        }
        printf("\n");
    }
    printf("\n");
    matrix = multiply_matrix(matrix, inversed_key, collumns, ligns);
    printf("Decrypted message:\n");
    for(int i = 0; i < ligns; ++i)
        for (int j = 0; j < collumns; ++j) {
            if (matrix[i][j] > 0)
                printf("%c", matrix[i][j] - 0.5 > (int)matrix[i][j] ? (int)matrix[i][j] + 1 : (int)matrix[i][j]);
        }
    printf("\n");
}

void encrypt(char **av)
{
    int key_len = find_key_size(av[2]);
    float **key = str_to_matrix(av[2], key_len, key_len);
    int collumns = key_len;
    int ligns = find_lines_nbr(av[1], collumns);
    float **matrix = str_to_matrix(av[1], collumns, ligns);

    matrix = multiply_matrix(matrix, key, collumns, ligns);
    printf("Key matrix:\n");
    for(int i = 0; i < key_len; ++i) {
        for (int j = 0; j < key_len; ++j) {
            if (key[i][j] == 0)
                printf("0%s", ((j < key_len - 1) ? "\t" : ""));
            else
                printf("%.0f%s", key[i][j], ((j < key_len - 1) ? "\t" : ""));
        }
        printf("\n");
    }
    printf("\n");
    printf("Encrypted message:\n");
    for(int i = 0; i < ligns; ++i)
        for (int j = 0; j < collumns; ++j)
            printf("%.0f%s", matrix[i][j], (i == ligns - 1 && j == collumns - 1) ? "" : " ");
    printf("\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage();
        return (0);
    }
    if (error_management(ac, av) == 84)
        return(84);
    if(av[3][0] == '0')
        encrypt(av);
    else if (av[3][0] == '1')
        decrypt(av);
}
