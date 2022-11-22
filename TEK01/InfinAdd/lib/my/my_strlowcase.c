/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-matheo.vitali
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i += 1;
    }
    return (str);
}