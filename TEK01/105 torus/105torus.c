/*
** EPITECH PROJECT, 2021
** B-MAT-100-STG-1-1-105torus-matheo.vitali
** File description:
** 105torus
*/

#include "include.h"

double function(coef_t *coef, double x)
{
    double res = coef->a4 * pow(x, 4) + coef->a3 * pow(x, 3) + coef->a2 * pow(x, 2) + coef->a1 * x + coef->a0;
    return (res);
}

float function_2(float x)
{
    float res = pow(x, 4) - 5 * pow(x, 3) + 6 * pow(x, 2) - 1;
    return (res);
}

double function_derived(coef_t *coef, double x)
{
    double res = 4 * coef->a4 * pow(x, 3) + 3 * coef->a3 * pow(x, 2) + 2 * coef->a2 * x + coef->a1;
    return (res);
}

double *bisection (coef_t *coef, double a, double b)
{
    double c = (a + b) / 2;
    double *res = malloc(sizeof(float) * 2);

    if (function(coef, a) * function(coef, c) < 0) {
        res[0] = a;
        res[1] = c;
    } else {
        res[0] = c;
        res[1] = b;
    }
    return (res);
}

double bisective_method(coef_t *coef, double a, double b, char **av)
{
    double *res = malloc(sizeof(double) * 2);
    int disp = 1;

    res[0] = a;
    res[1] = b;
    while (fabs(function(coef, (res[0] + res[1]) / 2)) > pow(10, atof(av[7]) * -1)) {
        if ((res[0] + res[1]) / 2 >= 1 || (res[0] + res[1]) / 2 <= 0)
            exit(84);
        printf("x = %.*f\n", disp, (res[0] + res[1]) / 2);
        res = bisection(coef, res[0], res[1]);
        if (disp < atoi(av[7]))
            disp += 1;
    }
    printf("x = %.*f\n", atoi(av[7]), (res[0] + res[1]) / 2);
    return ((res[0] + res[1]) / 2);
}

double newton(coef_t *coef, char **av)
{
    double xn = 0.5;
    double xnpls1 = xn - function(coef, xn) / function_derived(coef, xn);
    int disp = atoi(av[7]);

    printf("x = %.*g\n", atoi(av[7]), xn);
    while (fabs(function(coef, xn)) > pow(10, atof(av[7]) * -1)) {
        xn = xnpls1;
        if (xn >= 1 || xn <= 0)
            exit(84);
        if (function_derived(coef, xn) == 0)
            exit(84);
        xnpls1 = xn - function(coef, xn) / function_derived(coef, xn);
        if (xn != xnpls1)
            printf("x = %.*g\n", atoi(av[7]), xn);
    }
    return (xn);
}

double secant(coef_t *coef, char **av)
{
    double xnmin1 = 0;
    double xn = 1;
    double xnpls1 = 0;xn - (function(coef, xn) * (xn - xnmin1)) / (function(coef, xn) - function(coef, xnmin1));
    int disp = 1;

    while (fabs(function(coef, xn)) > pow(10, atof(av[7]) * -1)) {
        if (function(coef, xn) - function(coef, xnmin1) == 0)
            exit(84);
        xnpls1 = xn - (function(coef, xn) * (xn - xnmin1)) / (function(coef, xn) - function(coef, xnmin1));
        xnmin1 = xn;
        xn = xnpls1;
        if (xn >= 1 || xn <= 0)
            exit(84);
        if (function(coef, xn) - function(coef, xnmin1) == 0)
            exit(84);
        xnpls1 = xn - (function(coef, xn) * (xn - xnmin1)) / (function(coef, xn) - function(coef, xnmin1));
        disp = 8;
        if (xn == 0.5)
            printf("x = 0.5\n");
        else
            printf("x = %.*f\n", atoi(av[7]), xn);
    }
    return (xn);
}

int error_handeling(int ac, char **av)
{
    if (ac != 8)
        return (84);
    if (atoi(av[1]) > 3 || atoi(av[1]) < 1)
        return (84);
    if (atoi(av[7]) < 0)
        return (84);
    for (int i = 2; i < 8; ++i) {
        if (av[i][0] != '-' && (av[i][0] < '0' || av[i][0] > '9'))
            return (84);
        for (int j = 1; av[i][j] != '\0'; ++j)
            if (av[i][j] < '0' || av[i][j] > '9')
                return (84);
    }
    return (0);
}

int main (int ac, char **av)
{
    if (error_handeling(ac, av) == 84)
        return (84);

    coef_t coef = {atof(av[2]), atof(av[3]), atof(av[4]), atof(av[5]), atof(av[6])};

    if (ac != 8)
        return (84);
    if (atoi(av[1]) == 1)
        bisective_method(&coef, 0, 1, av);
    if (atoi(av[1]) == 2)
        newton(&coef, av);
    if (atoi(av[1]) == 3)
        secant(&coef, av);
    return (0);
}
