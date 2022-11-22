/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** randomize
*/

#include "../include/include.h"

static int randomize_helper(FILE *in)
{
    unsigned int seed;

    if (!in)
        return (-1);

    if (fread(&seed, sizeof(seed), 1, in) == 1) {
        fclose(in);
        srand(seed);
        return (0);
    }
    fclose(in);
    return (-1);
}

int randomize(void)
{
    if (!randomize_helper(fopen("/dev/urandom", "r")))
        return (0);
    if (!randomize_helper(fopen("/dev/arandom", "r")))
        return (0);
    if (!randomize_helper(fopen("/dev/random", "r")))
        return (0);
    return (-1);
}