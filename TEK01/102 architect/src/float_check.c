/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-102architect-matheo.vitali
** File description:
** float_check
*/

int check_for_float(char *str)
{
    int flot = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if ((str[i] - 48 < 0 || str[i] - 48 > 9) && str[i] != '-')
            flot += 1;
    }
    if (flot == 0)
        return (1);
    else
        return (0);
}