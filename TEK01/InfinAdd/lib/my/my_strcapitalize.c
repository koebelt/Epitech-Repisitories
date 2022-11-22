/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-matheo.vitali
** File description:
** my_strcapitalize
*/

int verify_previous_is_letter(char *str, int i)
{
    int verif = 0;
    int a = 0;

    while (a == 0) {
        if (str[i - 1] > 64 && str[i - 1] < 91)
            verif += 1;
        else if (str[i - 1] > 96 && str[i - 1] < 123)
            verif += 1;
        a += 1;
    }
    return (verif);
}

int verify_previous_character(char *str, int i)
{
    if (str[i - 1] > 64 && str[i - 1] < 91) {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
        i += 1;
    }
    else if (str[i - 1] > 96 && str[i - 1] < 123) {
        if (str[i] > 64 && str[i] < 91)
            str[i] += 32;
        i += 1;
    }
    return (str);
}

char verify_character(char *str, int i)
{
    if (str[i - 1] > 47 && str[i - 1] < 58) {
        if (str[i] > 64 && str[i] < 91 )
            str[i] += 32; 
    }
    else if (verify_previous_is_letter(str, i) == 0) {
        if (str[i] > 96 && str[i] < 123)
            str[i] -= 32;
    }
    else
        verify_previous_character(str, i);
    return (str);
}

char *my_strcapitalize(char *str)
{
    if (str[0] > 96 && str[0] < 123)
        str[0] -= 32;
    else if (str[0] == '\0')
        return (0);
    for (int i = 1; str[i] != '\0'; i += 1) {
        if (str[i] > 64 && str[i] < 91 || str[i] > 96 && str[i] < 123)
            verify_character(str, i);
    }
    return (str);
}