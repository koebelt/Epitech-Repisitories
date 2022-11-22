/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** energy_system
*/

#include "../include/include.h"

void init_energy(energy_t *energy, sfClock **clock)
{
    energy->background = init_sprite((sprite_info_t){20, 50, 1, 1, 0, 0, 0, 0,
    "assets/game_ui/Bar_vide_zap.png"});
    energy->energy_bar = init_sprite((sprite_info_t){105, 73, 1, 1, 0, 0, 34, 0,
    "assets/game_ui/bar_3.png"});
    energy->cooldown = ENERGY_COOLDOWN;
    energy->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    init_text(&energy->disp_value, 40, "0", (sfVector2f){53, 63});
    sfText_setOutlineThickness(energy->disp_value.text, 2);
    sfText_setOutlineColor(energy->disp_value.text, sfBlack);
    energy->value = 0;
}

void display_energy(energy_t *energy, window_t *window)
{
    sfTime time = sfClock_getElapsedTime(window->clock);
    float seconds = time.microseconds / 1000000.0 - energy->t_0;

    if (seconds >= energy->cooldown / 100) {
        if (energy->energy_bar.rect.width >= energy->energy_bar.size_text.x);
        else
            energy->value += 0.01;
        energy->t_0 = sfClock_getElapsedTime(window->clock).microseconds /
        1000000.0;
    }
    energy->energy_bar.rect.width = energy->value * 36.8;
    sfText_setString(energy->disp_value.text,
    my_int_to_str((int)energy->value));
    sfSprite_setTextureRect(energy->energy_bar.sprite,
    energy->energy_bar.rect);
    sfRenderWindow_drawSprite(window->window,
    energy->background.sprite, sfFalse);
    sfRenderWindow_drawSprite(window->window,
    energy->energy_bar.sprite, sfFalse);
    sfRenderWindow_drawText(window->window, energy->disp_value.text, sfFalse);
}