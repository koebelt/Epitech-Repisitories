/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** Npcs_with_quest
*/

#include "exterior.h"

static void quest_log_second(window_t *window)
{
    if (window->ext.npcs.third.show_quest == 1) {
        sfText_setPosition(window->ext.npcs.third.text.text,
        (sfVector2f) {window->ext.player.sprite.pos.x - 235,
        window->ext.player.sprite.pos.y - 65});
        sfRenderWindow_drawText(window->window,
        window->ext.npcs.third.text.text, NULL);
    }
    if (window->ext.npcs.fourth.show_quest == 1) {
        sfText_setPosition(window->ext.npcs.fourth.text.text,
        (sfVector2f) {window->ext.player.sprite.pos.x - 235,
        window->ext.player.sprite.pos.y - 105});
        sfRenderWindow_drawText(window->window,
        window->ext.npcs.fourth.text.text, NULL);
    }
}

void quest_log_mid(window_t *window)
{
    if (window->ext.npcs.first.show_quest == 1) {
        sfText_setPosition(window->ext.npcs.first.text.text,
        (sfVector2f) {window->ext.player.sprite.pos.x - 235,
        window->ext.player.sprite.pos.y - 105});
        sfRenderWindow_drawText(window->window,
        window->ext.npcs.first.text.text, NULL);
    }
    if (window->ext.npcs.second.show_quest == 1) {
        sfText_setPosition(window->ext.npcs.second.text.text,
        (sfVector2f) {window->ext.player.sprite.pos.x - 235,
        window->ext.player.sprite.pos.y - 65});
        sfRenderWindow_drawText(window->window,
        window->ext.npcs.second.text.text, NULL);
    }
}

void quest_log(window_t *window)
{
    if (window->ext.npcs.show_scroll == 1) {
        sfSprite_setPosition(window->ext.npcs.scroll.sprite,
        (sfVector2f) {window->ext.player.sprite.pos.x - 375,
        window->ext.player.sprite.pos.y - 215});
        sfRenderWindow_drawSprite(window->window,
        window->ext.npcs.scroll.sprite, NULL);
        quest_log_mid(window);
        quest_log_second(window);
    }
}

void updating_indicator(quest_t *quest)
{
    if (quest->taken == 1 && quest->done == 0) {
        sfSprite_setPosition(quest->question_mark.sprite, (sfVector2f)
        {quest->question_mark.pos.x, quest->question_mark.pos.y + 1610});
        sfSprite_setPosition(quest->exclamation_mark.sprite, (sfVector2f)
        {quest->exclamation_mark.pos.x, quest->exclamation_mark.pos.y - 2000});
    }
    if (quest->taken == 2 && quest->done == 0) {
        sfSprite_setPosition(quest->question_mark.sprite, (sfVector2f)
        {quest->question_mark.pos.x, quest->question_mark.pos.y - 1610});
        sfSprite_setPosition(quest->question_mark_complete.sprite, (sfVector2f)
        {quest->question_mark_complete.pos.x,
        quest->question_mark_complete.pos.y + 1610});
    }
    if (quest->done == 1) {
        sfSprite_setPosition(quest->question_mark_complete.sprite, (sfVector2f)
        {quest->question_mark_complete.pos.x,
        quest->question_mark_complete.pos.y - 1610});
    }
}

void init_npcs_with_quest(npcs_with_quest_t *npcs, window_t *window)
{
    npcs->show_scroll = 0;
    npcs->scroll.t_0 = 0.0;
    init_sprite(&npcs->scroll,
    (sprite_info_t){300, 300, 1.4, 0, 0, 512, 256, SCROLL_TEXT}, window);
    window->ext.npcs.scroll.scale.y = 1.6;
    sfSprite_setScale(npcs->scroll.sprite, npcs->scroll.scale);
}
