/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** menu
*/

#include "../include/include.h"

int menu_mouse_event7(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect setting_plus1_box =
    sfSprite_getGlobalBounds(menu->setting_plus1.sprite);

    if (sfFloatRect_contains(&setting_plus1_box, mouse.x, mouse.y)) {
        menu->music_bar.rect.width += 22;
        window->music_volume += 10;
        sfSprite_setPosition(menu->music_off.sprite, (sfVector2f){-300, -300});
        sfSprite_setPosition(menu->music_on.sprite, (sfVector2f){40, 40});
        if (menu->music_bar.rect.width > 212) {
            menu->music_bar.rect.width = 212;
            window->music_volume = 100;
        }
        sfSprite_setTextureRect(menu->music_bar.sprite, menu->music_bar.rect);
    } else
        menu_mouse_event8(menu, mouse, window);
}

int menu_mouse_event8(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect setting_minus1_box =
    sfSprite_getGlobalBounds(menu->setting_minus1.sprite);

    if (sfFloatRect_contains(&setting_minus1_box, mouse.x, mouse.y)) {
        menu->music_bar.rect.width -= 22;
        window->music_volume -= 10;
        if (menu->music_bar.rect.width <= 0) {
            menu->music_bar.rect.width = 0;
            window->music_volume = 0;
            sfSprite_setPosition(menu->music_off.sprite, (sfVector2f){40, 40});
            sfSprite_setPosition(menu->music_on.sprite,
            (sfVector2f){-300, -300});
        }
        sfSprite_setTextureRect(menu->music_bar.sprite, menu->music_bar.rect);
    } else
        menu_mouse_event9(menu, mouse, window);
}

int menu_mouse_event9(menu_t *menu, sfMouseButtonEvent mouse, window_t *window)
{
    sfFloatRect setting_plus2_box =
    sfSprite_getGlobalBounds(menu->setting_plus2.sprite);
    sfFloatRect how_to_play_box =
    sfSprite_getGlobalBounds(menu->how_to_play.sprite);

    if (sfFloatRect_contains(&setting_plus2_box, mouse.x, mouse.y)) {
        menu->sound_bar.rect.width += 22;
        window->sound_volume += 10;
        sfSprite_setPosition(menu->sound_off.sprite, (sfVector2f){-600, -600});
        sfSprite_setPosition(menu->sound_on.sprite, (sfVector2f){200, 40});
        if (menu->sound_bar.rect.width > 212) {
            menu->sound_bar.rect.width = 212;
            window->sound_volume = 100;
        }
        sfSprite_setTextureRect(menu->sound_bar.sprite, menu->sound_bar.rect);
    } else if (sfFloatRect_contains(&how_to_play_box, mouse.x, mouse.y))
        window->index = 7;
    else
        menu_mouse_event10(menu, mouse, window);
}

int menu_mouse_event10(menu_t *menu, sfMouseButtonEvent mouse,
window_t *window)
{
    sfFloatRect shop_button_box =
    sfSprite_getGlobalBounds(menu->shop_button.sprite);
    sfFloatRect setting_minus2_box =
    sfSprite_getGlobalBounds(menu->setting_minus2.sprite);

    if (sfFloatRect_contains(&setting_minus2_box, mouse.x, mouse.y)) {
        menu->sound_bar.rect.width -= 22;
        window->sound_volume -= 10;
        if (menu->sound_bar.rect.width <= 0) {
            menu->sound_bar.rect.width = 0;
            window->sound_volume = 0;
            sfSprite_setPosition(menu->sound_off.sprite, (sfVector2f){200, 40});
            sfSprite_setPosition(menu->sound_on.sprite,
            (sfVector2f){-600, -600});
        }
        sfSprite_setTextureRect(menu->sound_bar.sprite, menu->sound_bar.rect);
    } else if (sfFloatRect_contains(&shop_button_box, mouse.x, mouse.y)) {
        window->index = 6;
    }
}