/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** move_arrow
*/

#include "dongeon.h"

void move_arrow_start(spell_t *spell)
{
    sfFloatRect box = sfSprite_getGlobalBounds(spell->sprite.sprite);
    float proj_pos_x = spell->sprite.pos.x;

    if (spell->sprite.scale.x < 0)
        proj_pos_x -= box.width;
}

int move_arrow(spell_t *spell, monster_t *monster, player_dong_t *player,
window_t *window)
{
    sfFloatRect box = sfSprite_getGlobalBounds(spell->sprite.sprite);
    float proj_pos_x = spell->sprite.pos.x;

    move_arrow_start(spell);
    if (is_wall_collision_projectile((sfFloatRect) {proj_pos_x +
    spell->stats.speed, spell->sprite.pos.y, box.width, box.height},
    player->current->collisions, player->current->sprite.scale.x)) {
        spell->sprite.pos.x += spell->stats.speed;
        sfSprite_setPosition(spell->sprite.sprite, spell->sprite.pos);
    } else {
        delete_used_spell(&monster->spell, spell->id);
        return (0);
    }
    proj_pos_x = proj_pos_x;
    if (!damage_player_at_range(spell, player, window));
    else {
        delete_used_spell(&monster->spell, spell->id);
        return (0);
    }
    return (1);
}