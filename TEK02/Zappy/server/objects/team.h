/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** team
*/

#ifndef TEAM_H_
    #define TEAM_H_

    #include <sys/queue.h>
    #include "../system/object.h"
    #include "../includes/list.h"
    #include "../includes/prerequisite.h"
    #include "../includes/common.h"

TAIL_HEAD_OF(listtclient, s_tclient);

typedef struct {
    Class   base;
    char *name;
    int nb_players;
    Permission permission;
    struct listtclient clhead;
    TAIL_OF(s_tclient, Object, clients);
} TeamClass;

typedef struct s_tclient t_tclient;

void team_ctor(TeamClass *this, va_list *args);
void team_dtor(TeamClass *this);
void team_broadcast(TeamClass *this, char *data);
int team_victory(TeamClass *this);
void team_add_client(TeamClass *this, Object *client);

static const TeamClass _teamdescription = {
    (Class) {
        .__size__ = sizeof(TeamClass),
        .__name__ = "Team",
        .__ctor__ = (ctor_t)&team_ctor,
        .__dtor__ = (dtor_t)&team_dtor,
        .__str__ = NULL,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL,
        .__functions__ = {
            team_broadcast,
            team_victory,
            team_add_client
        }
    },
    .name = NULL,
    .nb_players = 0,
    .permission = 0,
    .clhead = {0},
    .clients = NULL
};

    #define Team_Broadcast(o, data) ((void (*)(TeamClass *, char *))\
    find(o, 0))(o, data)
    #define Team_victory(o) ((int (*)(TeamClass *)) find(o, 1))(o)
    #define Team_addClient(o, cl) ((void (*)(TeamClass *, Object *))\
    find(o, 2))(o, cl)

static const Class *Team = (const Class *)&_teamdescription;

#endif /* !TEAM_H_ */
