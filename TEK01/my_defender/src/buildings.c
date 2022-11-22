/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** buildings
*/

#include "../include/include.h"

void init_building(building_t *building, building_info_t info, sfClock **clock)
{
    info.info.rect_y = ((info.level - 1) * info.info.rect_width);
    building->sprite = init_sprite(info.info);
    building->health = info.health + ((info.level) * 0.25 * info.health);
    building->max_health = building->health;
    building->health_bar = init_sprite(info.health_bar_info);
    building->damages = info.damages + ((info.level) * 0.25 * info.damages);
    building->cooldown = info.cooldown;
    building->projectiles = NULL;
    building->projectile = info.projectile;
    if (info.radius > 0)
        init_circle(&building->range, (sfVector2f){info.info.pos_x - info.radius
        + building->sprite.rect.width / 2 , info.info.pos_y - info.radius +
        building->sprite.rect.height / 2}, info.radius);
    building->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
}

int tower_attack(building_t *building, soldiers_t *enemy, sfClock **clock)
{
    sfTime time = sfClock_getElapsedTime(*clock);
    float seconds = time.microseconds / 1000000.0 - building->t_0;

    if (seconds >= building->cooldown) {
        building->projectile.pos_x = building->sprite.pos.x;
        building->projectile.pos_y = building->sprite.pos.y;
        create_projectile(&building->projectiles, (soldier_info_t){0,
        building->damages, 0, 0, building->projectile, 0, 0}, clock, enemy->id);
        building->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    }
}

int has_an_enemy_in_range(building_t *build, soldiers_t *enemy, sfClock **clock)
{
    soldiers_t *tmp = NULL;
    sfFloatRect rect;

    tmp = enemy;
    while (tmp != NULL) {
        rect = sfSprite_getGlobalBounds(tmp->sprite.sprite);
        if (intersects(build->range, rect)) {
            tower_attack(build, tmp, clock);
            return (1);
        }
        tmp = tmp->next;
    }
}

void anim_building_health_bar(building_t *building, window_t *window)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(building->sprite.sprite);

    sfSprite_setPosition(building->health_bar.sprite, (sfVector2f){rect.left,
    rect.top - 10});

    building->health_bar.rect.width = building->health * 327 /
    building->max_health;
    sfSprite_setTextureRect(building->health_bar.sprite,
    building->health_bar.rect);
    sfRenderWindow_drawSprite(window->window,
    building->health_bar.sprite, sfFalse);
}

void display_building(building_t *build, window_t *window, soldiers_t *enemies)
{
    if (build->health > 0) {
        sfRenderWindow_drawSprite(window->window,
        build->sprite.sprite, sfFalse);
        anim_building_health_bar(build, window);
        if (build->damages != 0) {
            has_an_enemy_in_range(build, enemies, &window->clock);
            calc_projectile_position(build->projectiles, enemies);
            print_projectiles(build->projectiles, window->window,
            &window->clock);
            delete_used_projectiles(&build->projectiles);
        }
    }
}