/*
** EPITECH PROJECT, 2020
** my_str_is_lower
** File description:
** retern the thortesr str
*/


char *my_strislower(char *str1, char *str2)
{
    if (my_strlen(str1) <= my_strlen(str2))
        return(str1);
    else
        return(str2);
}


