/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** usage
*/

#include <stdio.h>

void usage(void)
{
    printf("USAGE\n");
    printf("    ./103cipher message key flag\n\n");
    printf("DESCRIPTION\n");
    printf("    message    a message, made of ASCII characters\n");
    printf("    key        the encryption key, made of ASCII characters\n");
    printf("    flag       0 for the message to be encrypted, 1 to be decyrpted\n");
}