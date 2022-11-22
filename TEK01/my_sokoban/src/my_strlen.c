/*
** EPITECH PROJECT, 2020
** B-PSU-101-STG-1-1-navy-thomas.koebel
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; ++i);
    return(i);
}
