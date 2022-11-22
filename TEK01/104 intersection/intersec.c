/*
** EPITECH PROJECT, 2020
** B-MAT-100-STG-1-1-104intersection-matheo.vitali
** File description:
** intersec
*/

#include "include.h"

void manage_delta(float delta, float a, float b, char **av)
{
    float t_one;
    float t_two;

    if (delta < 0)
        printf("No intersection point.\n");
    else if (delta > 0) {
        t_one = (b * -1 + sqrt(delta)) / (2 * a);
        t_two = (b * -1 - sqrt(delta)) / (2 * a);
        printf("2 intersection points:\n");
        printf("(%.3f, %.3f, %.3f)\n", (atof(av[2]) + t_one * atof(av[5])), (atof(av[3]) + t_one * atof(av[6])), (atof(av[4]) + t_one * atof(av[7])));
        printf("(%.3f, %.3f, %.3f)\n", (atof(av[2]) + t_two * atof(av[5])), (atof(av[3]) + t_two * atof(av[6])), (atof(av[4]) + t_two * atof(av[7])));
    } else {
        t_one = (b * -1) / (2 * a);
        printf("1 intersection point:\n");
        printf("(%.3f, %.3f, %.3f)\n", (atof(av[2]) + t_one * atof(av[5])), (atof(av[3]) + t_one * atof(av[6])), (atof(av[4]) + t_one * atof(av[7])));
    }
}

float sphere(int ac, char **av)
{
    float a = (pow(atof(av[5]), 2) + pow(atof(av[6]), 2) + pow(atof(av[7]), 2));
    float b = 2 * ((atof(av[2]) * atof(av[5])) + (atof(av[3]) * atof(av[6])) + (atof(av[4]) * atof(av[7])));
    float c = (pow(atof(av[2]), 2) + pow(atof(av[3]), 2) + pow(atof(av[4]), 2)) - pow(atof(av[8]), 2);
    float delta = pow(b, 2) - 4 * a * c;
    manage_delta(delta, a, b, av);
    return (0);
}

float cylinder(int ac, char **av)
{
    float a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2);
    float b = 2 * (atof(av[2]) * atof(av[5]) + atof(av[3]) * atof(av[6]));
    float c = (pow(atof(av[2]), 2) + pow(atof(av[3]), 2)) - pow(atof(av[8]), 2);
    float delta = pow(b, 2) - 4 * a * c;

    if (c == 0)
        printf("There is an infinite number of intersection points.");
    else
        manage_delta(delta, a, b, av);
    return (0);
}

float cone(int ac, char **av)
{
    float angle = (atof(av[8]) * M_PI) / 180;
    float a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) - (pow(atof(av[7]), 2) * pow(tan(angle), 2));
    float b = (2 * atof(av[2]) * atof(av[5])) + (2 * atof(av[3]) * atof(av[6])) - (2 * atof(av[4]) * atof(av[7]) * pow(tan(angle), 2));
    float c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) - (pow(atof(av[4]), 2) * pow(tan(angle), 2));
    float delta = pow(b, 2) - 4 * a * c;

    if (c == 0)
        printf("There is an infinite number of intersection points.");
    else
        manage_delta(delta, a, b, av);
    return (0);
}

int error_handeling(int ac, char **av)
{
    if (ac != 9)
        return (84);
    if (atof(av[5]) == 0 && atof(av[6]) == 0 && atof(av[7]) == 0)
        return (84);
    if (atof(av[1]) > 3 || atof(av[1]) < 1)
        return (84);
    if (atof(av[1]) == 1 && atof(av[8]) <= 0 || atof(av[1]) == 2 && atof(av[8]) <= 0)
        return (84);
    if (atof(av[1]) == 3 && (atof(av[8]) <= 0 || atof(av[8]) >= 90))
        return (84);
    for (int i = 2; i < 7; ++i) {
        if (av[i][0] != '-' && av[i][0] < '0' && av[i][0] > '9')
            return (84);
        for (int j = 1; av[i][j] != '\0'; ++j)
            if (av[i][j] < '0' || av[i][j] > '9')
                return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (error_handeling(ac, av) == 84)
        return (84);
    if (atof(av[1]) == 1) {
        printf("Sphere of radius %.0f\n", atof(av[8]));
        printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", atof(av[2]), atof(av[3]), atof(av[4]), atof(av[5]), atof(av[6]), atof(av[7]));
        sphere(ac, av);
    } else if (atof(av[1]) == 2) {
        printf("Cylinder of radius %.0f\n", atof(av[8]));
        printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", atof(av[2]), atof(av[3]), atof(av[4]), atof(av[5]), atof(av[6]), atof(av[7]));
        cylinder(ac, av);
    } else {
        printf("Cone with a %.0f degree angle\n", atof(av[8]));
        printf("Line passing through the point (%.0f, %.0f, %.0f) and parallel to the vector (%.0f, %.0f, %.0f)\n", atof(av[2]), atof(av[3]), atof(av[4]), atof(av[5]), atof(av[6]), atof(av[7]));
        cone(ac, av);
    }
}