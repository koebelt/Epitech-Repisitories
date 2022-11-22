/*
** EPITECH PROJECT, 2021
** Elementary_C_Programming
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; ++i);
    return(i);
}
