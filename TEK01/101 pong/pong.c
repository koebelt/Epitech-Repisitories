/*
** EPITECH PROJECT, 2020
** pong
** File description:
** pong
*/

#include <stdlib.h>
#include <math.h>
#include "include/my.h"
#include <stdio.h>

void give_vector(float a, float b, float c)
{
    printf("%c",'(');
    printf("%.2f%s%.2f%s%.2f%s",a, ", ",b, ", ",c, ")");
    printf("%c",'\n');
}

void print_vectors(char **av, float a, float b, float c)
{
    float d = strtof(av[4], NULL);
    float e = strtof(av[5], NULL);
    float f = strtof(av[6], NULL);
    float r = d - a;
    float h = e - b;
    float g = f - c;
    float time = strtof(av[7], NULL);
    float x = d + (r * time);
    float y = e + (h * time);
    float z = f + (g * time);

    printf("%s\n", "The velocity vector of the ball is:");
    give_vector(r, h, g);
    printf("%s%.0f%s\n", "At time t + ", time, ", ball coordinates will be:");
    give_vector(x, y, z);
}

void verif_hit(float f, float c, float angle)
{
    if ((f - c) < 0 && f > 0)
        printf("%s\n%.2f%s\n", "The incidence angle is:", angle, " degrees");
    else if ((f - c) > 0 && f < 0)
        printf("%s\n%.2f%s\n", "The incidence angle is:", angle, " degrees");
    else
        printf("%s\n", "The ball won't reach the paddle.");
}

int pong_main(char **av)
{
    float a = strtof(av[1], NULL);
    float b = strtof(av[2], NULL);
    float c = strtof(av[3], NULL);
    float d = strtof(av[4], NULL);
    float e = strtof(av[5], NULL);
    float f = strtof(av[6], NULL);
    float r = d - a;
    float h = e - b;
    float g = f - c;
    float norm = sqrt(pow(r, 2) + pow(h, 2) + pow(g, 2));
    float angle = asin(g / norm);
    angle = angle * (180 / 3.1415926535);
    if (angle < 0)
        angle = angle * -1;
    print_vectors(av, a, b, c);
    verif_hit(f, c, angle);
    return (0);
}

int main(int ac, char **av)
{
    if (error_handling(ac, av) == 84)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        usage(av);
        return (0);
    }
    pong_main(av);
    return (0);
}