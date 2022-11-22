/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-matheo.vitali
** File description:
** music_utilities
*/

#include "../../include/include.h"

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