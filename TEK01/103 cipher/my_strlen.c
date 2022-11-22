/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-103cipher-matheo.vitali
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; ++i);
    return(i);
}

int my_space_nbr(char *str)
{
    int len = 0;

    for (int i = 0; str[i]; ++i)
        if (str[i] == ' ')
            ++len;
    ++len;
    return (len);
}
