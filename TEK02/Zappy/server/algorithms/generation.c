/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** generation
*/

#include "../server.h"
#include "../objects/ressource.h"

static TileClass *get_valid_tile(ServerClass *server)
{
    TileClass *tile = NULL;

    do {
        tile = Map_getTile(server->map, rand() % server->map->size->x,
        rand() % server->map->size->y);
    } while (!tile);
    return (tile);
}

/**
** @author : Tristan Courty && Paul Gazeau-Rousseau
**
** @brief Function generation_ressources: Generate ressources randomly on
** the whole map
** @param server (ServerClass*): pointer on the server 
**
** @return Nothing
**/
void generation_ressources(ServerClass *server)
{
    memcpy(&server->max_ressources, _ressources, sizeof(Ressource) * 7);
    for (int i = 0; i != 7; i++)
        server->max_ressources[i].quantity = server->map->size->x *
        server->map->size->y * _ressources[i].den;
    for (int i = 0; i != 7; i++) {
        for (int qty = 0; qty != server->max_ressources[i].quantity; qty++)
            Tile_addRessource(get_valid_tile(server),
            server->max_ressources[i].type);
    }
}