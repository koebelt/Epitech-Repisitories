/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** server_packet
*/

#include "./server.h"
#include "./system/new.h"
#include "./objects/player.h"

static Object *add_player_in_team(ClientClass *client, TeamClass *team,
VectorClass *map_size, ServerClass *server)
{
    int x = rand() % map_size->x;
    int y = rand() % map_size->y;
    PlayerClass *new_player = new(Player, client, x, y);
    TileClass *tile = Map_getTile(server->map, x, y);

    if (!tile)
        return (NULL);
    Tile_addPlayer(tile, new_player);
    return (new_player);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function team_packet: Called when an ia want to be in a specific team
** @param this (ServerClass*): Pointer on Server class
** @param client (ClientClass*): Pointer on Client class
** @param self (TeamClass*): Pointer on Team class
**
** @return Nothing
**/
void team_packet(ServerClass *this, ClientClass *client, TeamClass *self)
{
    char *nb_players = NULL;
    char *new_player = NULL;

    asprintf(&nb_players, "%d", this->max_players_team - self->nb_players);
    AddPacket(nb_players);
    AddPacket(str(this->map->size));
    client->player = add_player_in_team(client, self, this->map->size, this);
    asprintf(&new_player, "pnw %d %s %d %d %s", client->id, str(client->\
    player->position), client->player->eye_direction, client->player->level,
    self->name);
    Team_Broadcast(get_team(this, GRAPHIC_TEAM), new_player);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function get_team: Called when we want to get a specific team
** @param this (ServerClass*): Pointer on Server class
** @param name (char *): Name of the team to collect
**
** @return Nothing
**/
TeamClass *get_team(ServerClass *this, const char *name)
{
    for (t_team *np = this->thead.tqh_first; np != NULL;
    np = np->entries.tqe_next) {
        if (!strcmp(np->object->name, name))
            return (np->object);
    }
    return (NULL);
}

/**
** @author : Paul Gazeau-Rousseau & Tristan Courty
**
** @brief Function get_client: Called when we want to get a specific client
** @param this (ServerClass*): Pointer on Server class
** @param id (int): Id of the client to collect
**
** @return Pointer on client class that was found
**/
ClientClass *get_client(ServerClass *this, int id)
{
    ClientClass *current = NULL;
    
    for (t_client *np = this->head.lh_first; np != NULL;
    np = np->entries.le_next) {
        if (np->object->id == id)
            return (np->object);
    }
    return (NULL);
}

int check_team_victory(TeamClass *team, ServerClass *server)
{
    char *gui_message = NULL;

    if (!team)
        return (0);
    server->open = false;
    asprintf(&gui_message, "seg %s\n", team->name);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}