/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-matheo.vitali
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
        i += 1;
    }
    return (str);
}