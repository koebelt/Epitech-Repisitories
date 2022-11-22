/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** load_obs.c
*/

#include "include.h"

void load_obs0(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs0[obstacles->nbr_of_occurences[0]].sprite = sfSprite_create();
    obstacles->obs0[obstacles->nbr_of_occurences[0]].pos.x = x *
    obstacles->cell_size + 500;
    obstacles->obs0[obstacles->nbr_of_occurences[0]].pos.y = y *
    obstacles->cell_size + 282;
    obstacles->obs0[obstacles->nbr_of_occurences[0]].scale.x = 4;
    obstacles->obs0[obstacles->nbr_of_occurences[0]].scale.y = 4;
    obstacles->obs0[obstacles->nbr_of_occurences[0]].texture =
    sfTexture_createFromFile("ressources/obstacle0.png", NULL);
    sfSprite_setTexture(obstacles->obs0[obstacles->nbr_of_occurences[0]].sprite,
    obstacles->obs0[obstacles->nbr_of_occurences[0]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs0[obstacles->nbr_of_occurences[0]].sprite,
    obstacles->obs0[obstacles->nbr_of_occurences[0]].scale);
    obstacles->nbr_of_occurences[0] += 1;
}

void load_obs1(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs1[obstacles->nbr_of_occurences[1]].sprite = sfSprite_create();
    obstacles->obs1[obstacles->nbr_of_occurences[1]].pos.x = x *
    obstacles->cell_size + 500 + 32 * 4;
    obstacles->obs1[obstacles->nbr_of_occurences[1]].pos.y = y *
    obstacles->cell_size + 282;
    obstacles->obs1[obstacles->nbr_of_occurences[1]].scale.x = 4;
    obstacles->obs1[obstacles->nbr_of_occurences[1]].scale.y = 4;
    obstacles->obs1[obstacles->nbr_of_occurences[1]].texture =
    sfTexture_createFromFile("ressources/obstacle1.png", NULL);
    sfSprite_setTexture(obstacles->obs1[obstacles->nbr_of_occurences[1]].sprite,
    obstacles->obs1[obstacles->nbr_of_occurences[1]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs1[obstacles->nbr_of_occurences[1]].sprite,
    obstacles->obs1[obstacles->nbr_of_occurences[1]].scale);
    obstacles->nbr_of_occurences[1] += 1;
}

void load_obs2(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs2[obstacles->nbr_of_occurences[2]].sprite = sfSprite_create();
    obstacles->obs2[obstacles->nbr_of_occurences[2]].pos.x = x *
    obstacles->cell_size + 500;
    obstacles->obs2[obstacles->nbr_of_occurences[2]].pos.y = y *
    obstacles->cell_size + 282 + 32 * 4;
    obstacles->obs2[obstacles->nbr_of_occurences[2]].scale.x = 4;
    obstacles->obs2[obstacles->nbr_of_occurences[2]].scale.y = 4;
    obstacles->obs2[obstacles->nbr_of_occurences[2]].texture =
    sfTexture_createFromFile("ressources/obstacle2.png", NULL);
    sfSprite_setTexture(obstacles->obs2[obstacles->nbr_of_occurences[2]].sprite,
    obstacles->obs2[obstacles->nbr_of_occurences[2]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs2[obstacles->nbr_of_occurences[2]].sprite,
    obstacles->obs2[obstacles->nbr_of_occurences[2]].scale);
    obstacles->nbr_of_occurences[2] += 1;
}

void load_obs3(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs3[obstacles->nbr_of_occurences[3]].sprite = sfSprite_create();
    obstacles->obs3[obstacles->nbr_of_occurences[3]].pos.x = x *
    obstacles->cell_size + 500;
    obstacles->obs3[obstacles->nbr_of_occurences[3]].pos.y = y *
    obstacles->cell_size + 282;
    obstacles->obs3[obstacles->nbr_of_occurences[3]].scale.x = 4;
    obstacles->obs3[obstacles->nbr_of_occurences[3]].scale.y = 4;
    obstacles->obs3[obstacles->nbr_of_occurences[3]].texture =
    sfTexture_createFromFile("ressources/obstacle3.png", NULL);
    sfSprite_setTexture(obstacles->obs3[obstacles->nbr_of_occurences[3]].sprite,
    obstacles->obs3[obstacles->nbr_of_occurences[3]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs3[obstacles->nbr_of_occurences[3]].sprite,
    obstacles->obs3[obstacles->nbr_of_occurences[3]].scale);
    obstacles->nbr_of_occurences[3] += 1;
}

void load_obs4(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs4[obstacles->nbr_of_occurences[4]].sprite = sfSprite_create();
    obstacles->obs4[obstacles->nbr_of_occurences[4]].pos.x = x *
    obstacles->cell_size + 500 + 10 * 4;
    obstacles->obs4[obstacles->nbr_of_occurences[4]].pos.y = y *
    obstacles->cell_size + 282;
    obstacles->obs4[obstacles->nbr_of_occurences[4]].scale.x = 4;
    obstacles->obs4[obstacles->nbr_of_occurences[4]].scale.y = 4;
    obstacles->obs4[obstacles->nbr_of_occurences[4]].texture =
    sfTexture_createFromFile("ressources/obstacle4.png", NULL);
    sfSprite_setTexture(obstacles->obs4[obstacles->nbr_of_occurences[4]].sprite,
    obstacles->obs4[obstacles->nbr_of_occurences[4]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs4[obstacles->nbr_of_occurences[4]].sprite,
    obstacles->obs4[obstacles->nbr_of_occurences[4]].scale);
    obstacles->nbr_of_occurences[4] += 1;
}
