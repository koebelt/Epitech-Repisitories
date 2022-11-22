/*
** EPITECH PROJECT, 2021
** My_Defender
** File description:
** sprite_utilities2
*/

#include "../include/include.h"

void init_text(text_t *text, int size, char *str, sfVector2f pos)
{
    text->font = sfFont_createFromFile("assets/fonts/BADABB__.TTF");
    text->text = sfText_create();
    text->pos.x = pos.x;
    text->pos.y = pos.y;
    sfText_setFont(text->text, text->font);
    sfText_setString(text->text, str);
    sfText_setCharacterSize(text->text, size);
    sfText_setColor(text->text, sfWhite);
    sfText_setPosition(text->text, text->pos);
}

void init_circle(circle_t *circle, sfVector2f pos, float radius)
{
    sfColor color = sfColor_fromRGBA(255, 255, 255, 100);
    circle->circle = sfCircleShape_create();
    circle->pos.x = pos.x;
    circle->pos.y = pos.y;
    circle->radius = radius;
    sfCircleShape_setRadius(circle->circle, circle->radius);
    sfCircleShape_setPosition(circle->circle, circle->pos);
    sfCircleShape_setFillColor(circle->circle, color);
}

void sound_set_audio(sfSound **sound, char *path, int volume)
{
    sfSoundBuffer *buffer;

    buffer = sfSoundBuffer_createFromFile(path);
    *sound = sfSound_create();
    sfSound_setBuffer(*sound, buffer);
    sfSound_setVolume(*sound, volume);
}

void music_set_audio(sfMusic **music, char *path, int volume)
{
    *music = sfMusic_createFromFile(path);
    sfMusic_setLoop(*music, sfTrue);
    sfMusic_setVolume(*music, volume);
}