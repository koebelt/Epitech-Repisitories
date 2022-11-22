/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** move
*/

#include "../objects/command.h"
#include "../server.h"

/**
** @author : Thomas Koebel & Tristan Courty
**
** @command forward
** @executor IA_USER
**
** @brief Advance the player in his looking direction
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_forward(t_command *this, ClientClass *client,
ServerClass *server)
{
    Object *dire = NULL;
    TileClass *tile = NULL;
    char *message = NULL;
    char *gui_message = NULL;
    VectorClass *mapSize = server->map->size;

    if (this->nb_args != 0)
        return (0);
    if (!(tile = get_tile_at_pos(server->map, PosX, PosY)))
        return (0);
    Tile_removePlayer(tile, client->player);
    dire = Player_getVision(client->player);
    addition(client->player->position, dire);
    printf("mapSize (x : %d - y : %d)\n", mapSize->x, mapSize->y);
    printf("before Pos (x : %d - y : %d)\n", PosX, PosY);
    if (PosX < 0)
        PosX = mapSize->x - 1;
    if (PosY < 0)
        PosY = mapSize->y - 1;
    if (PosX >= mapSize->x)
        PosX = 0;
    if (PosY >= mapSize->y)
        PosY = 0;
    printf("after Pos (x : %d - y : %d)\n", PosX, PosY);
    if (!(tile = get_tile_at_pos(server->map, PosX, PosY)))
        return (0);
    Tile_addPlayer(tile, client->player);
    AddPacket("ok");
    asprintf(&gui_message, "ppo %d %s %d", client->id,
    str(client->player->position), client->player->eye_direction);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau & Tristan Courty
**
** @command right
** @executor IA_USER
**
** @brief Rotate the player on the right
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_right(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *str = NULL;
    char *gui_message = NULL;

    if (this->nb_args != 0)
        return (0);
    if (client->player->eye_direction == 4)
        client->player->eye_direction = 1;
    else
        client->player->eye_direction += 1;
    AddPacket("ok");
    asprintf(&gui_message, "ppo %d %s %d", client->id,
    str(client->player->position), client->player->eye_direction);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau & Tristan Courty
**
** @command left
** @executor IA_USER
**
** @brief Rotate the player on the left
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_left(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *str = NULL;
    char *gui_message = NULL;

    if (this->nb_args != 0)
        return (0);
    if (client->player->eye_direction == 1)
        client->player->eye_direction = 4;
    else
        client->player->eye_direction -= 1;
    AddPacket("ok");
    asprintf(&gui_message, "ppo %d %s %d", client->id,
    str(client->player->position), client->player->eye_direction);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}
