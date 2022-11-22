/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-thomas.koebel
** File description:
** renit.c
*/

#include "include.h"

void renit_hero(sprite_t *hero, sfClock **clock)
{
    hero->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    hero->pos.x = 50;
    hero->pos.y = 504;
}

void renit_obs0(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs0[i].pos.x = x * obstacles->cell_size + 500;
    obstacles->obs0[i].pos.y = y * obstacles->cell_size + 282;
    sfSprite_setPosition(obstacles->obs0[i].sprite, obstacles->obs0[i].pos);

}

void renit_obs1(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs1[i].pos.x = x * obstacles->cell_size + 500 + 32 * 4;
    obstacles->obs1[i].pos.y = y * obstacles->cell_size + 282;
    sfSprite_setPosition(obstacles->obs1[i].sprite, obstacles->obs1[i].pos);
}

void renit_obs2(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs2[i].pos.x = x * obstacles->cell_size + 500;
    obstacles->obs2[i].pos.y = y * obstacles->cell_size + 282 + 32 * 4;
    sfSprite_setPosition(obstacles->obs2[i].sprite, obstacles->obs2[i].pos);
}

void renit_obs3(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs3[i].pos.x = x * obstacles->cell_size + 500;
    obstacles->obs3[i].pos.y = y * obstacles->cell_size + 282;
    sfSprite_setPosition(obstacles->obs3[i].sprite, obstacles->obs3[i].pos);
}

void renit_obs4(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs4[i].pos.x = x * obstacles->cell_size + 500 + 10 * 4;
    obstacles->obs4[i].pos.y = y * obstacles->cell_size + 282;
    sfSprite_setPosition(obstacles->obs4[i].sprite, obstacles->obs3[i].pos);
}

void renit_obs5(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs5[i].pos.x = x * obstacles->cell_size + 500;
    obstacles->obs5[i].pos.y = y * obstacles->cell_size + 282;
    sfSprite_setPosition(obstacles->obs5[i].sprite, obstacles->obs5[i].pos);
}

void renit_obs6(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs6[i].pos.x = x * obstacles->cell_size + 500 - 10 * 4;
    obstacles->obs6[i].pos.y = y * obstacles->cell_size + 282;
    sfSprite_setPosition(obstacles->obs6[i].sprite, obstacles->obs6[i].pos);
}

void renit_obs7(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs7[i].pos.x = x * obstacles->cell_size + 500;
    obstacles->obs7[i].pos.y = y * obstacles->cell_size + 282;
    sfSprite_setPosition(obstacles->obs7[i].sprite, obstacles->obs7[i].pos);
}

void renit_obs8(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs8[i].pos.x = x * obstacles->cell_size + 500 + 16 * 4;
    obstacles->obs8[i].pos.y = y * obstacles->cell_size + 282 + 16 * 4;
    sfSprite_setPosition(obstacles->obs8[i].sprite, obstacles->obs8[i].pos);
}

void renit_obs9(obstacles_t *obstacles, int x, int y, int i)
{
    obstacles->obs9[i].pos.x = x * obstacles->cell_size + 500 + 16 * 4;
    obstacles->obs9[i].pos.y = y * obstacles->cell_size + 200;
    sfSprite_setPosition(obstacles->obs9[i].sprite, obstacles->obs9[i].pos);
}

void renit_obstacles(window_obj_t *window)
{
    int i0 = 0;
    int i1 = 0;
    int i2 = 0;
    int i3 = 0;
    int i4 = 0;
    int i5 = 0;
    int i6 = 0;
    int i7 = 0;
    int i8 = 0;
    int i9 = 0;

    for (int i = 0; window->game.obstacles.tab[i]; ++i)
        for (int j = 0; window->game.obstacles.tab[i][j]; ++j) {
            window->game.obstacles.tab[i][j] == '0' ?
            renit_obs0(&window->game.obstacles, j, i, i0++) : 0;
            window->game.obstacles.tab[i][j] == '1' ?
            renit_obs1(&window->game.obstacles, j, i, i1++) : 0;
            window->game.obstacles.tab[i][j] == '2' ?
            renit_obs2(&window->game.obstacles, j, i, i2++) : 0;
            window->game.obstacles.tab[i][j] == '3' ?
            renit_obs3(&window->game.obstacles, j, i, i3++) : 0;
            window->game.obstacles.tab[i][j] == '4' ?
            renit_obs4(&window->game.obstacles, j, i, i4++) : 0;
            window->game.obstacles.tab[i][j] == '5' ?
            renit_obs5(&window->game.obstacles, j, i, i5++) : 0;
            window->game.obstacles.tab[i][j] == '6' ?
            renit_obs6(&window->game.obstacles, j, i, i6++) : 0;
            window->game.obstacles.tab[i][j] == '7' ?
            renit_obs7(&window->game.obstacles, j, i, i7++) : 0;
            window->game.obstacles.tab[i][j] == '8' ?
            renit_obs8(&window->game.obstacles, j, i, i8++) : 0;
            window->game.obstacles.tab[i][j] == '9' ?
            renit_obs9(&window->game.obstacles, j, i, i9++) : 0;
    }
}

void renit_game(game_obj_t *game, sfClock **clock, window_obj_t *window)
{
    renit_hero(&game->hero.sprite, clock);
    game->hero.is_jumping = 0;
    game->hero.is_falling = 0;
    game->hero.is_dead = 0;
    game->t_0 = sfClock_getElapsedTime(*clock).microseconds / 1000000.0;
    game->background.velocity = 5;
    renit_obstacles(window);
}
