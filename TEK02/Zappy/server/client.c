/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** client
*/

#include "./server.h"
#include "./system/new.h"
#include "./includes/prerequisite.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Client Class
** @param this (ClientClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void client_ctor(ClientClass *this, va_list *args)
{
    int len = sizeof(struct sockaddr_in);
    struct sockaddr_in in = {0};

    TAILQ_INIT(&this->chead);
    TAILQ_INIT(&this->phead);
    this->ssocket = va_arg(*args, int);
    this->saved_cmd = NULL;
    if ((this->socket = accept(this->ssocket, (struct sockaddr *) &in,
    (socklen_t *) &len)) < 0)
        raise("Cannot accept client!");
    this->address = in;
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for Client Class
** @param this (ClientClass*): Pointer on class
**
** @return Nothing
**/
void client_dtor(ClientClass *this)
{
    if (strcmp(this->saved_cmd, ""))
        free(this->saved_cmd);
    if (this->player)
        delete(this->player);
    this->player = NULL;
    while (this->phead.tqh_first != NULL) {
        delete(this->phead.tqh_first->object);
        TAILQ_REMOVE(&this->phead, this->phead.tqh_first, entries);
    }
    this->socket = 0;
    this->ssocket = 0;
    this->address = (struct sockaddr_in) {0};
    this->phead = (struct listpacket) {0};
    this->team = NULL;
    this->id = 0;
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function client_init: Called when we want to reset the socket of a
** specific client
** @param this (ClientClass*): Pointer on class
** @param set (fd_set*): Pointer on read set
** @param wset (fd_set*): Pointer on write set
**
** @return Nothing
**/
void client_init(ClientClass *this, fd_set *set, fd_set *wset)
{
    FD_SET(this->socket, set);
    FD_SET(this->socket, wset);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function client_write: Called when a packet must be write on the
** linked client socket
** @param this (ClientClass*): Pointer on class
** @param server (ServerClass*): Pointer on server class
**
** @return Nothing
**/
void client_write(ClientClass *this, Object *server)
{
    ServerClass *serverp = server;

    if (!this->phead.tqh_first)
        return;
    Packet_write(this->phead.tqh_first->object, serverp->logs[0]->fd);
    if (this->team && this->team->permission == serverp->logs[1]->permission)
        Packet_write(this->phead.tqh_first->object, serverp->logs[1]->fd);
    if (this->team && this->team->permission == serverp->logs[2]->permission)
        Packet_write(this->phead.tqh_first->object, serverp->logs[2]->fd);
    Packet_write(this->phead.tqh_first->object, this->socket);
    TAILQ_REMOVE(&this->phead, this->phead.tqh_first, entries);
}