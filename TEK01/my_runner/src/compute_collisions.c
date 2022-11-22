/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** compute_collisions.c
*/

#include "include.h"

int is_collyding(hero_t *hero, obstacles_t *obstacles, window_obj_t *window)
{
    int collisions = ground_collision(hero, window) ? 1 : 0;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[0],
    obstacles->obs0, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[1],
    obstacles->obs1, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[2],
    obstacles->obs2, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[3],
    obstacles->obs3, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[4],
    obstacles->obs4, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[5],
    obstacles->obs5, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[6],
    obstacles->obs6, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[7],
    obstacles->obs7, window) ? 1 : collisions;
    collisions = global_collisions(hero, obstacles->nbr_of_occurences[8],
    obstacles->obs8, window) ? 1 : collisions;
    return (collisions);
}

int compute_collisions(hero_t *hero, obstacles_t *obstacles, window_obj_t *window)
{
    int collisions = is_collyding(hero, obstacles, window);

    sfSprite_setPosition(hero->sprite.sprite, hero->sprite.pos);
    portal_collision(hero, obstacles, window);
    if (!collisions) {
        if (!hero->is_jumping && !hero->is_falling) {
            init_fall(hero, &window->clock);
        }
        if (hero->is_falling && !hero->is_jumping) {
            anim_fall(hero, window, obstacles);
        }
    }
}
