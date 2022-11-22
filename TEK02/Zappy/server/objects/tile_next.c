/*
** EPITECH PROJECT, 2022
** server
** File description:
** tile_next
*/

#include "./zappy_map.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function tile_add_player: Add a player from tile
** @param this (TileClass*): Pointer on tile
** @param player (PlayerClass*): Pointer on player
**
** @return Nothing
**/
void tile_add_player(TileClass *this, PlayerClass *player)
{
    t_tplayer *new_player = malloc(sizeof(t_tplayer));
    new_player->object = player;
    TAILQ_INSERT_TAIL(&this->tphead, new_player, entries);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function tile_remove_player: Remove a player from tile
** @param this (TileClass*): Pointer on tile
** @param player (PlayerClass*): Pointer on player
**
** @return Nothing
**/
void tile_remove_player(TileClass *this, PlayerClass *player)
{
    for (t_tplayer *np = this->tphead.tqh_first; np != NULL; np =
    np->entries.tqe_next) {
        if (np->object == player)
            np->object = NULL;
    }
}