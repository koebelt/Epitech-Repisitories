/*
** EPITECH PROJECT, 2020
** my_putstr.c
** File description:
** 
*/

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return(0);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}