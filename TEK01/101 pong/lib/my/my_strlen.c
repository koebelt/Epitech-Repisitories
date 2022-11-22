/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** a function that counsts and returns the number of characters in a string
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

