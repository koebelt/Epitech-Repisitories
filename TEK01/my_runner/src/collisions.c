/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** collisions.c
*/

#include "include.h"

int ground_collision(hero_t *hero, window_obj_t *window)
{
    if (hero->sprite.pos.y >= 505) {
        if (hero->is_falling || hero->is_jumping) {
            hero->sprite.rect.left = 0;
            hero->sprite.rect.top = 0;
        }
        hero->is_jumping = 0;
        hero->is_falling = 0;
        hero->sprite.pos.y = 505;
        return (1);
    }
    return (0);
}

void apply_detected_collisions(hero_t *hero, sfFloatRect area,
    window_obj_t *window)
{
    if (area.width >= area.height) {
        if (sfFloatRect_contains(&area, area.left, hero->sprite.pos.y)) {
            hero->sprite.pos.y = hero->sprite.pos.y + area.height;
        } else {
            if (hero->is_falling || hero->is_jumping) {
                hero->sprite.rect.left = 0;
                hero->sprite.rect.top = 0;
            }
            hero->is_falling = 0;
            hero->is_jumping = 0;
            hero->sprite.pos.y = hero->sprite.pos.y - area.height + 1;
        }
    } else if (area.width < area.height && hero->sprite.pos.y > 300) {
        hero->is_dead = 1;
        window->game.background.velocity = 0;
        init_death(hero, window->clock, window->game.death, window);
    }
}

int global_collisions(hero_t *hero, int occurences, sprite_t *obstacle,
    window_obj_t *window)
{
    int collisions = 0;
    for (int i = 0; i < occurences; ++i) {
        sfFloatRect area;
        sfFloatRect hero_box = sfSprite_getGlobalBounds(hero->sprite.sprite);
        sfFloatRect sprite_box = sfSprite_getGlobalBounds(obstacle[i].sprite);
        if (sfFloatRect_intersects(&hero_box, &sprite_box, &area)) {
            apply_detected_collisions(hero, area, window);
            collisions = 1;
        }
    }
    return (collisions);
}

int portal_collision(hero_t *hero, obstacles_t *obstacles, window_obj_t *window)
{
    int collisions = 0;
    for (int i = 0; i < obstacles->nbr_of_occurences[9]; ++i) {
        sfFloatRect area;
        sfFloatRect hero_box = sfSprite_getGlobalBounds(hero->sprite.sprite);
        sfFloatRect sprite_box =
        sfSprite_getGlobalBounds(obstacles->obs9[i].sprite);

        if (sfFloatRect_intersects(&hero_box, &sprite_box, &area)) {
            window->index = 2;
            init_win(&window->win, window);
            window->high_score[window->menu.map_index - 1] = "100";
            collisions = 1;
        }
    }
    return (collisions);
}
