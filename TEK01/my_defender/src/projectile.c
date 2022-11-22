/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** projectile
*/

#include "../include/include.h"

void create_projectile(projectile_t **list, soldier_info_t soldier_info,
sfClock **clock, int target)
{
    projectile_t *element;

    element = malloc(sizeof(*element));
    element->sprite = init_sprite(soldier_info.walk_info);
    sfSprite_setOrigin(element->sprite.sprite,
    (sfVector2f){element->sprite.rect.width / 2,
    element->sprite.rect.height / 2});
    element->damages = soldier_info.damages;
    element->used = 0;
    element->target = target;
    element->next = *list;
    *list = element;
}

void damages_enemy_at_range(projectile_t *proj, soldiers_t *enemy)
{
    sfFloatRect enemy_rect = sfSprite_getGlobalBounds(enemy->sprite.sprite);
    sfFloatRect proj_rect = sfSprite_getGlobalBounds(proj->sprite.sprite);

    if (sfFloatRect_intersects(&enemy_rect, &proj_rect, NULL) &&
    proj->used == 0) {
        enemy->health -= proj->damages;
        proj->used = 1;
    }
}

void move_to_enemy(projectile_t *proj, soldiers_t *enemy)
{
    sfVector2f tmp = {enemy->sprite.pos.x - proj->sprite.pos.x,
    enemy->sprite.pos.y - proj->sprite.pos.y};
    float angle = atan2(enemy->sprite.pos.y - proj->sprite.pos.y,
    enemy->sprite.pos.x - proj->sprite.pos.x) * 180 / 3.14159265;

    for (int i = 0; tmp.x > 3 || tmp.x < -3; tmp.x = tmp.x / 1.1,
    tmp.y = tmp.y / 1.1);
    for (int i = 0; tmp.y > 3 || tmp.y < -3; tmp.x = tmp.x / 1.1,
    tmp.y = tmp.y / 1.1);
    proj->sprite.pos.x += tmp.x;
    proj->sprite.pos.y += tmp.y;
    sfSprite_setRotation(proj->sprite.sprite, angle);
    sfSprite_setPosition(proj->sprite.sprite, proj->sprite.pos);
    damages_enemy_at_range(proj, enemy);
}

void calc_projectile_position(projectile_t *list, soldiers_t *enemies)
{
    projectile_t *tmp_proj;
    soldiers_t *tmp_enemies;
    int id = 0;

    tmp_proj = list;
    tmp_enemies = enemies;
    while (tmp_proj != NULL) {
        while (tmp_enemies != NULL) {
            tmp_proj->target == tmp_enemies->id ?  id = tmp_enemies->id: 0;
            id != 0 ? move_to_enemy(tmp_proj, tmp_enemies) : 0;
            tmp_enemies = tmp_enemies->next;
        }
        if (id);
        else
            tmp_proj->used = 1;
        tmp_proj = tmp_proj->next;
    }
}

void print_projectiles(projectile_t *list, sfRenderWindow *window,
sfClock **clock)
{
    projectile_t *tmp;

    tmp = list;
    while (tmp != NULL) {
        sfRenderWindow_drawSprite(window, tmp->sprite.sprite, sfFalse);
        tmp = tmp->next;
    }
}