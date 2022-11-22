/*
** EPITECH PROJECT, 2021
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** load_obs_2.c
*/

#include "include.h"

void load_obs5(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs5[obstacles->nbr_of_occurences[5]].sprite = sfSprite_create();
    obstacles->obs5[obstacles->nbr_of_occurences[5]].pos.x = x *
    obstacles->cell_size + 500;
    obstacles->obs5[obstacles->nbr_of_occurences[5]].pos.y = y *
    obstacles->cell_size + 282;
    obstacles->obs5[obstacles->nbr_of_occurences[5]].scale.x = 4;
    obstacles->obs5[obstacles->nbr_of_occurences[5]].scale.y = 4;
    obstacles->obs5[obstacles->nbr_of_occurences[5]].texture =
    sfTexture_createFromFile("ressources/obstacle5.png", NULL);
    sfSprite_setTexture(obstacles->obs5[obstacles->nbr_of_occurences[5]].sprite,
    obstacles->obs5[obstacles->nbr_of_occurences[5]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs5[obstacles->nbr_of_occurences[5]].sprite,
    obstacles->obs5[obstacles->nbr_of_occurences[5]].scale);
    obstacles->nbr_of_occurences[5] += 1;
}

void load_obs6(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs6[obstacles->nbr_of_occurences[6]].sprite = sfSprite_create();
    obstacles->obs6[obstacles->nbr_of_occurences[6]].pos.x = x *
    obstacles->cell_size + 500 - 10 * 4;
    obstacles->obs6[obstacles->nbr_of_occurences[6]].pos.y = y *
    obstacles->cell_size + 282;
    obstacles->obs6[obstacles->nbr_of_occurences[6]].scale.x = 4;
    obstacles->obs6[obstacles->nbr_of_occurences[6]].scale.y = 4;
    obstacles->obs6[obstacles->nbr_of_occurences[6]].texture =
    sfTexture_createFromFile("ressources/obstacle6.png", NULL);
    sfSprite_setTexture(obstacles->obs6[obstacles->nbr_of_occurences[6]].sprite,
    obstacles->obs6[obstacles->nbr_of_occurences[6]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs6[obstacles->nbr_of_occurences[6]].sprite,
    obstacles->obs6[obstacles->nbr_of_occurences[6]].scale);
    obstacles->nbr_of_occurences[6] += 1;
}

void load_obs7(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs7[obstacles->nbr_of_occurences[7]].sprite = sfSprite_create();
    obstacles->obs7[obstacles->nbr_of_occurences[7]].pos.x = x *
    obstacles->cell_size + 500;
    obstacles->obs7[obstacles->nbr_of_occurences[7]].pos.y = y *
    obstacles->cell_size + 282;
    obstacles->obs7[obstacles->nbr_of_occurences[7]].scale.x = 4;
    obstacles->obs7[obstacles->nbr_of_occurences[7]].scale.y = 4;
    obstacles->obs7[obstacles->nbr_of_occurences[7]].texture =
    sfTexture_createFromFile("ressources/obstacle7.png", NULL);
    sfSprite_setTexture(obstacles->obs7[obstacles->nbr_of_occurences[7]].sprite,
    obstacles->obs7[obstacles->nbr_of_occurences[7]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs7[obstacles->nbr_of_occurences[7]].sprite,
    obstacles->obs7[obstacles->nbr_of_occurences[7]].scale);
    obstacles->nbr_of_occurences[7] += 1;
}

void load_obs8(obstacles_t *obstacles, int x, int y)
{
    obstacles->obs8[obstacles->nbr_of_occurences[8]].sprite = sfSprite_create();
    obstacles->obs8[obstacles->nbr_of_occurences[8]].pos.x = x *
    obstacles->cell_size + 500 + 16 * 4;
    obstacles->obs8[obstacles->nbr_of_occurences[8]].pos.y = y *
    obstacles->cell_size + 282 + 16 * 4;
    obstacles->obs8[obstacles->nbr_of_occurences[8]].scale.x = 4;
    obstacles->obs8[obstacles->nbr_of_occurences[8]].scale.y = 4;
    obstacles->obs8[obstacles->nbr_of_occurences[8]].texture =
    sfTexture_createFromFile("ressources/obstacle8.png", NULL);
    sfSprite_setTexture(obstacles->obs8[obstacles->nbr_of_occurences[8]].sprite,
    obstacles->obs8[obstacles->nbr_of_occurences[8]].texture, sfFalse);
    sfSprite_setScale(obstacles->obs8[obstacles->nbr_of_occurences[8]].sprite,
    obstacles->obs8[obstacles->nbr_of_occurences[8]].scale);
    obstacles->nbr_of_occurences[8] += 1;
}

void load_obs9(obstacles_t *obstacles, int x, int y, sfClock *clock)
{
    obstacles->obs9[obstacles->nbr_of_occurences[9]].t_0 =
    sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].sprite = sfSprite_create();
    obstacles->obs9[obstacles->nbr_of_occurences[9]].pos.x = x *
    obstacles->cell_size + 500 + 16 * 4;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].pos.y = y *
    obstacles->cell_size + 200;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].scale.x = 1;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].scale.y = 1;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].rect.top = 0;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].rect.left = 0;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].rect.height = 320;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].rect.width = 320;
    obstacles->obs9[obstacles->nbr_of_occurences[9]].texture =
    sfTexture_createFromFile("ressources/Portal.png", NULL);
    sfSprite_setTexture(obstacles->obs9[obstacles->nbr_of_occurences[9]].sprite,
    obstacles->obs9[obstacles->nbr_of_occurences[9]].texture, sfFalse);
    sfSprite_setTextureRect(
    obstacles->obs9[obstacles->nbr_of_occurences[9]].sprite,
    obstacles->obs9[obstacles->nbr_of_occurences[9]].rect);
    sfSprite_setScale(obstacles->obs9[obstacles->nbr_of_occurences[9]].sprite,
    obstacles->obs9[obstacles->nbr_of_occurences[9]].scale);
    obstacles->nbr_of_occurences[9] += 1;
}
