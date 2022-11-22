/*
** EPITECH PROJECT, 2022
** server
** File description:
** client_next
*/

#include "./server.h"
#include "./system/new.h"
#include "./objects/command.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function client_can_eat: Check if a client can eat so if it's an
** ia and time is correct
** @param this (ClientClass*): Pointer on Client class
** @param server (Object*): Pointer on Server Class
**
** @return bool
**/
bool client_can_eat(ClientClass *this, Object *server)
{
    TeamClass *team = this->team;
    ServerClass *serverp = server;

    if (!team)
        return (false);
    if (!strcmp(team->name, GRAPHIC_TEAM))
        return (false);
    if (serverp->time == 0 || (serverp->time % 126) != 0)
        return (false);
    return (true);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function process_command: Process a command through time
** @param client (ClientClass*): Pointer on Client class
** @param server (ServerClass*): Pointer on Server class
**
** @return int
**/
int process_command(ClientClass *client, Object *server)
{
    t_command *first = NULL;

    if (client->chead.tqh_first)
        first = ((t_command *) client->chead.tqh_first->object);
    if (!first)
        return (0);
    if (first->start_time != ((ServerClass *) server)->time && first->time > 0)
        first->time--;
    if (!first->time) {
        first->after(first, client, server);
        free(first);
        TAILQ_REMOVE(&client->chead, client->chead.tqh_first, entries);
    }
}

/**
** @author : Paul Gazeau-Rousseau & Tristan Courty
**
** @brief Function *client_read: Read the buffer until the command is finished
** by '\n'
** @param this (ClientClass*): Pointer on class
**
** @return Null if the buffer isn't finish or the finished buffer
**/
struct listentry *client_read(ClientClass *this)
{
    char buffer[READ_SIZE] = {0};
    struct listentry *head = malloc(sizeof(struct listentry));
    char *find = NULL;
    char *to_add = NULL;
    int len = 0;

    TAILQ_INIT(head);
    bzero(buffer, READ_SIZE);
    len = read(this->socket, buffer, READ_SIZE);
    buffer[len] = '\0';
    to_add = strdup(buffer);
    if (!(find = strchr(to_add, '\n')))
        this->saved_cmd = my_strcat(this->saved_cmd, to_add);
    else {
        do {
            t_entry *entry = malloc(sizeof(t_entry));
            entry->object = strndup(to_add, find - to_add);
            if (this->saved_cmd) {
                entry->object = my_strcat(this->saved_cmd, entry->object);
                this->saved_cmd = NULL;
            }
            TAILQ_INSERT_TAIL(head, entry, entries);
            to_add = find + 1;
        } while ((find = strchr(to_add, '\n')));
        this->saved_cmd = to_add[0] ? strdup(to_add) : NULL;
    }
    return (head ? head : NULL);
}