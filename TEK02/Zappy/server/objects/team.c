/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team
*/

#include "./team.h"
#include "../system/new.h"
#include "../server.h"
#include "../packets/packet.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Constructor for Team Class
** @param this (TeamClass*): Pointer on class
** @param args (va_list*): list of argument given by new
**
** @return Nothing
**/
void team_ctor(TeamClass *this, va_list *args)
{
    TAILQ_INIT(&this->clhead);
    this->name = (char *) va_arg(*args, char *);
    this->permission = va_arg(*args, int);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Destructor for Team Class
** @param this (TeamClass*): Pointer on class
**
** @return Nothing
**/
void team_dtor(TeamClass *this)
{
    while (this->clhead.tqh_first != NULL)
        TAILQ_REMOVE(&this->clhead, this->clhead.tqh_first, entries);
    this->clhead = (struct listtclient) {0};
    this->permission = 0;
    this->name = NULL;
    this->nb_players = 0;
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function team_add_client: Called when add a new client to team
** @param this (TeamClass*): Pointer on team class
** @param client (Object*): Pointer on client class
**
** @return Nothing
**/
void team_add_client(TeamClass *this, Object *client)
{
    t_tclient *tclient = (t_tclient *) malloc(sizeof(t_tclient));

    tclient->object = client;
    TAILQ_INSERT_TAIL(&this->clhead, tclient, entries);
    this->nb_players++;
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Broadcast a message to all member in a team
** @param this (TeamClass*): Pointer on class
** @param string (data): Data to send to all member
**
** @return Desired Team has string
**/
void team_broadcast(TeamClass *this, char *data)
{
    if (!this)
        return;
    for (t_tclient *np = this->clhead.tqh_first; np != NULL; np =
    np->entries.tqe_next)
        AddPacketC(((ClientClass *)np->object), data);
}

/**
** @author : Tristan Courty
**
** @brief Function team_victory: Check if team is victory and if it is send
** the good response
** @param this (TeamClass*): Pointer on class
**
** @return int
**/
int team_victory(TeamClass *this)
{
    int count = 0;

    /* 
    if (!this)
        return (0);
    for (t_tclient *np = this->clhead.tqh_first; np != NULL;
    np = np->entries.tqe_next) {
        if (((ClientClass *)np->object)->player->level == 8)
            count++;
    }
    if (count >= 6)
        return (1); */
    return (0);
}