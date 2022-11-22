/*
** EPITECH PROJECT, 2021
** B-MAT-200-STG-2-1-106bombyx-matheo.vitali
** File description:
** main
*/

#include "include.h"

void calc_from_to(double x, double i0, double i1, double growth)
{
    for (int i = i0; i <= i1; ++i) {
        printf("%.2f %.2f\n", growth, x);
        x = growth * x * ((1000 - x) / 1000);
    }
}

void without_growth_rate(double n, int i0, int i1, char **av)
{
    /* double x = n;
    double gr = 1.0;
    int i = 0; */

    /* for (growth = 1.0; growth <= 4; growth += 0.01) {
        x = n;
        for (int i = 1; i <= i0; ++i) {
            x = growth * x * ((1000 - x) / 1000);
        }
        calc_from_to(x, i0, i1, growth);
    } */
    for (double gr = 1.00; gr <= 4; gr += 0.01) {
        n = atof(av[1]);
        for (int i = 1; i < i0; i++)
            n = gr * n * ((1000.f - n) / 1000.f);
        for (int init = i0; init <= i1; init++) {
            printf("%.2lf %.2f\n", gr, n);
            n = gr * n * ((1000.f - n) / 1000.f);
        }
    }
}

void with_growth_rate(double n, double k)
{
    double x = n;

    for (int i = 1; i <= 100; ++i) {
        printf("%d %.2f\n", i, x);
        x = k * x * ((1000 - x) / 1000);
    }
}

int information(void)
{
    printf("USAGE\n\t./106bombyx n [k | i0 i1]\n\nDESCRIPTION\n\tn\t\tnumber");
    printf(" of first generation individuals\n\tk\t\tgrowth rate from 1 to 4");
    printf("\n\ti0\t\tinitial generation (included)\n\ti1\t\tfinal ");
    printf("generation (included)\n");
}

int error_handling(char **av, int ac)
{
    if (ac != 4 && ac != 3)
        return (84);
    for (int i = 0; av[1][i] != '\0'; i += 1) {
            if ((av[1][i] < '0' || av[1][i] > '9') && av[1][i] != '.')
                return (84);
        }
    if (ac == 3) {
        for (int i = 0; av[2][i] != '\0'; i += 1) {
            if ((av[2][i] < '0' || av[2][i] > '9') && av[2][i] != '.')
                return (84);
        }
        if (atof(av[2]) < 1 || atof(av[2]) > 4)
            return (84);
        if (atof(av[1]) < 1)
            return (84);
    } else {
        if (atof(av[1]) < 1)
            return (84);
        if (atof(av[3]) < atof(av[2]))
            return (84);
        if (atof(av[2]) < 0 || atof(av[3]) < 0)
            return (84);
        for (int i = 0; av[2][i] != '\0'; i += 1) {
            if ((av[2][i] < '0' || av[2][i] > '9') && av[2][i] != '.')
                return (84);
        }
        for (int i = 0; av[3][i] != '\0'; i += 1) {
            if ((av[3][i] < '0' || av[3][i] > '9') && av[3][i] != '.')
                return (84);
        }
    }
}

int main(int ac, char **av)
{
    if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        information();
        return (0);
    }
    if (error_handling(av, ac) == 84)
        return (84);
    if (ac == 4)
        without_growth_rate(atof(av[1]), atoi(av[2]), atoi(av[3]), av);
    else if (ac != 4)
        with_growth_rate(atof(av[1]), atof(av[2]));
}