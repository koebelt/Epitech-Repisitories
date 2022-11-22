/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-ethan.husser
** File description:
** ig_ui
*/

#include "../include/include.h"

void display_card(card_t *card, window_t *window)
{
    if (card->is_moved) {
        sfSprite_setPosition(card->sprite.sprite, (sfVector2f){window->mouse.x -
        (card->sprite.size_text.x / 2) * card->sprite.scale.x, window->mouse.y -
        (card->sprite.size_text.y / 2) * card->sprite.scale.y});
    } else
        sfSprite_setPosition(card->sprite.sprite, card->sprite.pos);
    if (window->game.allies.energy.value < card->cost)
        sfSprite_setColor(card->sprite.sprite, sfColor_fromRGB(150, 150, 150));
    else
        sfSprite_setColor(card->sprite.sprite, sfColor_fromRGB(255, 255, 255));
    sfRenderWindow_drawSprite(window->window, card->sprite.sprite, sfFalse);
}

void display_ig_ui(ig_ui_t *ig_ui, window_t *window)
{
    sfRenderWindow_drawSprite(window->window, ig_ui->card_support.sprite,
    sfFalse);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &ig_ui->play_level);
    button_hover_color_animation(sfMouse_getPositionRenderWindow(window->window)
    , &ig_ui->pause_level);
    sfRenderWindow_drawSprite(window->window, ig_ui->card_support.sprite,
    sfFalse);
    if (window->game.has_started)
        sfRenderWindow_drawSprite(window->window, ig_ui->pause_level.sprite,
        sfFalse);
    else
        sfRenderWindow_drawSprite(window->window, ig_ui->play_level.sprite,
        sfFalse);

    for (int i = 0; i < window->level.cards; i++) {
        display_card(&ig_ui->cards[i], window);
    }
}