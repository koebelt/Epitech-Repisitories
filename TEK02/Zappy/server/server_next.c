/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** server_next
*/

#include "./server.h"
#include "./system/new.h"
#include "./objects/command.h"

static int handle_command(ClientClass *client, ServerClass *server, char *buff)
{
    t_command *command = NULL;
    t_commandl *cmdl = NULL;

    if (!(command = Command_getFromBuffer(buff)))
        return (AddPacket("suc"));
    if (command->permission != client->team->permission) {
        free(command);
        return (AddPacket("smg You're not the right user"));
    }
    if (client->player && client->player->incantation)
        return (AddPacket("smg You'r currently in incantation"));
    cmdl = malloc(sizeof(t_commandl));
    cmdl->object = command;
    command->start_time = server->time;
    TAILQ_INSERT_TAIL(&client->chead, cmdl, entries);
    if (command->before)
        command->before(command, client, server);
    return (1);
}

static int handle_client(ClientClass *client, ServerClass *server, char *buff)
{
    TeamClass *ptr = NULL;

    if (!client->team && (ptr = get_team(server, buff))) {
        Team_addClient(ptr, client);
        if (strcmp(buff, GRAPHIC_TEAM))
            Team_packet(server, client, ptr);
        else {
            //TODO : envoyer une liste des players connectés
            command_msz(NULL, client, server);
            command_mct(NULL, client, server);
            command_sgt(NULL, client, server);
            command_tna(NULL, client, server);
        }
        client->team = ptr;
        return (0);
    } else if (!client->team)
        return (AddPacket("smg Must send team first!\n"));
    return (handle_command(client, server, buff));
}

static int listen_clients(ServerClass *this, fd_set *rset, fd_set *wset)
{
    struct listentry *entries = NULL;

    for (t_client *np = this->head.lh_first; np; np = np->entries.le_next) {
        if (FD_ISSET(np->object->socket, wset))
            Client_write(np->object, this);
        EventManager_handle(np->object, this);
        if (!FD_ISSET(np->object->socket, rset))
            continue;
        if (!(entries = Client_read(np->object)))
            break;
        for (t_entry *ep = entries->tqh_first; ep; ep = ep->entries.tqe_next)
            handle_client(np->object, this, ep->object);
        break;
    }
    return (0);
}

static void add_client(ServerClass *this, Object *client)
{
    static int id = 0;
    t_client *nclient = malloc(sizeof(t_client));

    if (!nclient)
        return;
    nclient->object = client;
    nclient->object->id = id++;
    LIST_INSERT_HEAD(&this->head, nclient, entries);
    dprintf(nclient->object->socket, "WELCOME\n");
    printf("New connection accepted\n");
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function server_start: Called when server start
** @param this (ServerClass*): Pointer on class
**
** @return Nothing
**/
void server_start(ServerClass *this)
{
    fd_set sets[2] = {0};
    int ret = 0;
    struct timeval timer = {0};

    for (this->open = true; this->open;) {
        timer = (struct timeval) {.tv_usec = (1000000 / this->time_unit)};
        for (int i = 0; i <= 1; i++)
            FD_ZERO(&sets[i]);
        for (int i = 0; i <= 1; i++)
            FD_SET(this->socket, &sets[i]);
        for (t_client *np = this->head.lh_first; np != NULL; np =
        np->entries.le_next)
            Client_init(np->object, &sets[0], &sets[1]);
        if ((ret = select(FD_SETSIZE, &sets[0], &sets[1], NULL, &timer)) < 0)
            continue;
        if (ret == 0)
            this->time += 1;
        (FD_ISSET(this->socket, &sets[0]) ? add_client(this, new(Client,
        this->socket)) : listen_clients(this, &sets[0], &sets[1]));
    }
}