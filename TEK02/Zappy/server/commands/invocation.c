/*
** EPITECH PROJECT, 2022
** server
** File description:
** invocation
*/

#include "../objects/command.h"
#include "../server.h"
#include "../includes/prerequisite.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @command Incantation
** @executor IA_USER
**
** @brief Run when an incatation was just started
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_invocation_before(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *gui_message = NULL;
    TileClass *tile = NULL;
    VectorClass *pPos = client->player->position;
    ClientClass *cliento = NULL;

    asprintf(&gui_message, "pic %s %d", str(pPos), client->player->level);
    if (!(tile = Map_getTile(server->map, pPos->x, pPos->y)))
        return (0);
    for (t_tplayer *np = tile->tphead.tqh_first; np != NULL;
    np = np->entries.tqe_next) {
        cliento = np->object->client;
        AddPacketC(cliento, "Elevation underway");
        cliento->player->incantation = true;
        gui_message = my_strcat(gui_message, " ");
        gui_message = my_strcat(gui_message, itoa(cliento->id));
    }
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command Incantation
** @executor IA_USER
**
** @brief Run when an incatation is finished
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_invocation_after(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *ia_message = NULL;
    char *gui_message = NULL;
    TileClass *tile = NULL;
    VectorClass *pPos = client->player->position;
    ClientClass *cliento = NULL;

    if (!(tile = Map_getTile(server->map, pPos->x, pPos->y)))
        return (0);
    for (t_tplayer *np = tile->tphead.tqh_first; np != NULL;
    np = np->entries.tqe_next) {
        cliento = np->object->client;
        cliento->player->incantation = false;
        np->object->level++;
        asprintf(&ia_message, "Current level: %d", np->object->level);
        AddPacketC(cliento, ia_message);
    }
    asprintf(&gui_message, "pie %s %d", str(client->player->position),
    client->player->level);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}