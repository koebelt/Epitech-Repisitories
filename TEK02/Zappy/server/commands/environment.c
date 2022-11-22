/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** environment
*/

#include "../objects/command.h"
#include "../server.h"
#include "../algorithms/sound.h"

static int command_broadcast_next(PlayerClass *me, ClientClass *target,
VectorClass *size, char *message)
{
    char *ia_message = NULL;

    t_node *node = find_sound_direction(me->position, target->player->position,
    size->x, size->y);
    if (!node)
        return (0);
    asprintf(&ia_message, "message %d, %s",\
    get_direction_number(Player_getVision(me),\
    subtraction(target->player->position, node->object->position)), message);
    AddPacketC(target, ia_message);
    return (1);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command Broadcast text - where text is the text to broadcast
** @executor IA_USER
**
** @brief Run when ia want to broadcast a message to other
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_broadcast(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *str = NULL;
    char *gui_message = NULL;

    if (this->nb_args != 1)
        return (0);
    for (t_client *np = server->head.lh_first; np != NULL;
    np = np->entries.le_next) {
        if (np->object->id == client->id)
            continue;
        command_broadcast_next(client->player, np->object, server->map->size,
        this->args[0]);
    }
    AddPacket("ok");
    asprintf(&gui_message, "pbc %d %s", client->id, this->args[0]);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    return (1);
}

static int command_eject_next(ServerClass *server, PlayerClass *other,
PlayerClass *me)
{
    char *gui_message = NULL;
    char *ia_message = NULL;
    ClientClass *otherC = other->client;

    addition(other->position, Player_getVision(me));
    asprintf(&gui_message, "pex %d", otherC->id);
    Team_Broadcast(get_team(server, GRAPHIC_TEAM), gui_message);
    asprintf(&ia_message, "eject: %d", me->eye_direction);
    AddPacketC(otherC, ia_message);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @command Eject
** @executor IA_USER
**
** @brief Run when ia want to eject some players
** @param this (t_command*): The command that been executed
** @param client (ClientClass*): Client that has execute command
** @param server (ServerClass*): Pointer on server
**
** @return int
**/
int command_eject(t_command *this, ClientClass *client,
ServerClass *server)
{
    char *player_id = NULL;
    int count = 0;
    VectorClass *pos = client->player->position;
    TileClass *tile = Map_getTile(server->map, pos->x, pos->y);

    if (!tile || this->nb_args != 0)
        return (0);
    for (t_tplayer *np = tile->tphead.tqh_first; np != NULL;
    np = np->entries.tqe_next) {
        if (np->object == client->player)
            continue;
        command_eject_next(server, np->object, client->player);
        count++;
    }
    AddPacket(count > 0 ? "ok" : "ko");
    return (1);
}