/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** set_inv_first
*/

#include "inventory.h"

void set_inv_pos_fifth(window_t *window)
{
    sfText_setPosition(window->inventory.level_nbr.text,
    window->inventory.level_nbr.pos);
    window->inventory.exp_nbr.pos.x = 415 +
    window->view_center.x - 500;
    window->inventory.exp_nbr.pos.y = 530 +
    window->view_center.y - 400;
    window->inventory.exp_next_lvl.pos.x = 475 +
    window->view_center.x - 500;
    window->inventory.exp_next_lvl.pos.y = 530 +
    window->view_center.y - 400;
    sfText_setPosition(window->inventory.exp_nbr.text,
    window->inventory.exp_nbr.pos);
    sfText_setPosition(window->inventory.exp_next_lvl.text,
    window->inventory.exp_next_lvl.pos);
    sfText_setColor(window->inventory.exp_nbr.text,
    window->inventory.exp_color);
    sfText_setColor(window->inventory.exp_next_lvl.text,
    window->inventory.exp_color);
    set_inv_pos_sixth(window);
}

void set_inv_pos_forth(window_t *window)
{
    sfText_setColor(window->inventory.exp.text, window->inventory.exp_color);
    window->inventory.slash.pos.x = 455 +
    window->view_center.x - 500;
    window->inventory.slash.pos.y = 530 +
    window->view_center.y - 400;
    sfText_setPosition(window->inventory.slash.text,
    window->inventory.slash.pos);
    sfText_setColor(window->inventory.slash.text, window->inventory.exp_color);
    window->inventory.level.pos.x = 360 +
    window->view_center.x - 500;
    window->inventory.level.pos.y = 505 +
    window->view_center.y - 400;
    sfText_setPosition(window->inventory.level.text,
    window->inventory.level.pos);
    window->inventory.level_nbr.pos.x = 445 +
    window->view_center.x - 500;
    window->inventory.level_nbr.pos.y = 505 +
    window->view_center.y - 400;
    set_inv_pos_fifth(window);
}

void set_inv_pos_third(window_t *window)
{
    window->inventory.stat_armor_nbr.pos.x = 447 +
    window->view_center.x - 500;
    window->inventory.stat_armor_nbr.pos.y = 470 +
    window->view_center.y - 400;
    sfText_setPosition(window->inventory.stat_damage_nbr.text,
    window->inventory.stat_damage_nbr.pos);
    sfText_setPosition(window->inventory.stat_attack_speed_nbr.text,
    window->inventory.stat_attack_speed_nbr.pos);
    sfText_setPosition(window->inventory.stat_speed_nbr.text,
    window->inventory.stat_speed_nbr.pos);
    sfText_setPosition(window->inventory.stat_armor_nbr.text,
    window->inventory.stat_armor_nbr.pos);
    window->inventory.exp_color = sfColor_fromRGB(186, 85, 211);
    window->inventory.exp.pos.x = 360 +
    window->view_center.x - 500;
    window->inventory.exp.pos.y = 530 +
    window->view_center.y - 400;
    sfText_setPosition(window->inventory.exp.text,
    window->inventory.exp.pos);
    set_inv_pos_forth(window);
}

void set_inv_pos_second(window_t *window)
{
    sfText_setPosition(window->inventory.stat_attack_speed.text,
    window->inventory.stat_attack_speed.pos);
    sfText_setPosition(window->inventory.stat_speed.text,
    window->inventory.stat_speed.pos);
    sfText_setPosition(window->inventory.stat_armor.text,
    window->inventory.stat_armor.pos);
    window->inventory.stat_damage_nbr.pos.x = 447 +
    window->view_center.x - 500;
    window->inventory.stat_damage_nbr.pos.y = 369 +
    window->view_center.y - 400;
    window->inventory.stat_attack_speed_nbr.pos.x = 447 +
    window->view_center.x - 500;
    window->inventory.stat_attack_speed_nbr.pos.y = 403 +
    window->view_center.y - 400;
    window->inventory.stat_speed_nbr.pos.x = 447 +
    window->view_center.x - 500;
    window->inventory.stat_speed_nbr.pos.y = 437 +
    window->view_center.y - 400;
    set_inv_pos_third(window);
}

void set_inv_pos(window_t *window)
{
    window->inventory.stat_damage.pos.x = 345 +
    window->view_center.x - 500;
    window->inventory.stat_damage.pos.y = 371 +
    window->view_center.y - 400;
    window->inventory.stat_attack_speed.pos.x =
    335 + window->view_center.x - 500;
    window->inventory.stat_attack_speed.pos.y =
    406 + window->view_center.y - 400;
    window->inventory.stat_speed.pos.x = 352 +
    window->view_center.x - 500;
    window->inventory.stat_speed.pos.y = 437 +
    window->view_center.y - 400;
    window->inventory.stat_armor.pos.x = 347 +
    window->view_center.x - 500;
    window->inventory.stat_armor.pos.y = 470 +
    window->view_center.y - 400;
    sfText_setPosition(window->inventory.stat_damage.text,
    window->inventory.stat_damage.pos);
    set_inv_pos_second(window);
}