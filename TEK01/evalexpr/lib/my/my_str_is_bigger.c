/*
** EPITECH PROJECT, 2020
** my_is_bigger
** File description:
** returns the biggest str of the parameters
*/

char *my_str_is_bigger(char *str1, char *str2)
{
    if (my_strlen(str1) > my_strlen(str2))
        return(str1);
    else
        return(str2);
}
