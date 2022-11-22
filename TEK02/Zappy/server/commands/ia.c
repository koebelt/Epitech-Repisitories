/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** ia
*/

#include "../objects/command.h"
#include "../server.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @command Connect_nbr
** @executor IA_USER
**
** @brief Give the current info about all the teams
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_connectnbr(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *player_nbr = NULL;

    asprintf(&player_nbr, "%d",
    (server->max_players_team - client->team->nb_players));
    AddPacket(player_nbr);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command Fork
** @executor IA_USER
**
** @brief Run when a fork was called on ia
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_fork_before(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *gui_message = NULL;

    AddPacket("ok");
    asprintf(&gui_message, "pfk %d", client->id);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    memset(gui_message, 0, strlen(gui_message));
    asprintf(&gui_message, "enw %d %d %s", client->player->egg_id, client->id,
    str(client->player->position));
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command Fork
** @executor IA_USER
**
** @brief Run at end of a fork that have been called by ia
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_fork_after(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *gui_message = NULL;

    asprintf(&gui_message, "eht %d", client->player->egg_id);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    client->player->egg_id++;
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command Take
** @executor IA_USER
**
** @brief Run when ia collect ressource(s)
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_take(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *gui_message = NULL;
    VectorClass *pos = client->player->position;
    TileClass *tile = Map_getTile(server->map, pos->x, pos->y);

    if (!tile || this->nb_args != 1)
        return (0);
    for (int i = 0; i != 7; i++) {
        if (strcmp(tile->ressource[i].name, this->args[0]))
            continue;
        if (tile->ressource[i].quantity == 0)
            break;
        tile->ressource[i].quantity--;
        ((InventoryClass *)client->player->inventory)->ressource[i].quantity++;
        AddPacket("ok");
        asprintf(&gui_message, "pgt %d %d", client->id, 1);
        Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
        asprintf(&gui_message, "bct %s", str(tile));
        Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
        return (1);
    }
    AddPacket("ko");
    return (0);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command Set
** @executor IA_USER
**
** @brief Run when dropping ressource(s)
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_set(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *gui_message = NULL;
    InventoryClass *inv = client->player->inventory;
    VectorClass *pos = client->player->position;
    TileClass *tile = Map_getTile(server->map, pos->x, pos->y);

    if (!tile || this->nb_args != 1)
        return (0);
    for (int i = 0; i != 7; i++) {
        if (strcmp(tile->ressource[i].name, this->args[0]))
            continue;
        if (inv->ressource[i].quantity == 0)
            break;
        tile->ressource[i].quantity++;
        inv->ressource[i].quantity--;
        AddPacket("ok");
        asprintf(&gui_message, "pdr %d %d", client->id, 1);
        Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
        return (1);
    }
    AddPacket("ko");
    return (0);
}
