/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** projectile2
*/

#include "../include/include.h"

void delete_projectiles_2(projectile_t **begin, projectile_t *prev,
projectile_t *next, projectile_t *curent)
{
    if (prev == NULL)
        *begin = next;
    else
        prev->next = next;
    free(curent);
}

void delete_used_projectiles(projectile_t **begin)
{
    projectile_t *prev = NULL;
    projectile_t *curent = *begin;
    projectile_t *next;

    while (curent != NULL) {
        next = curent->next;
        if (curent->used == 1)
            delete_projectiles_2(begin, prev, next, curent);
        else
            prev = curent;
        curent = next;
    }
}