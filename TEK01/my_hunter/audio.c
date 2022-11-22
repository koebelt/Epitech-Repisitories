/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-thomas.koebel
** File description:
** audio.c
*/

#include "include.h"

void set_audio(sfSound **sound, char *path)
{
    sfSoundBuffer *buffer;
    
    buffer = sfSoundBuffer_createFromFile(path);
    *sound = sfSound_create();
    sfSound_setBuffer(*sound, buffer);
}
