/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** command
*/

#ifndef COMMAND_H_
    #define COMMAND_H_
    
    #define _GNU_SOURCE
    
    #include <sys/queue.h>
    #include "../system/new.h"
    #include "../server.h"
    #include "../includes/common.h"
    #include <stdio.h>
    
    #define NB_CMD 21

typedef struct s_command {
    const char *name;
    int (*before)(struct s_command *, ClientClass *, ServerClass *);
    int (*after)(struct s_command *, ClientClass *, ServerClass *);
    int nb_args;
    Permission permission;
    int start_time;
    int time;
    char **args;
} t_command;

void command_ctor(t_command *this, va_list *args);
void command_dtor(t_command *this);

int command_msz(t_command *, ClientClass *, ServerClass *);
int command_bct(t_command *, ClientClass *, ServerClass *);
int command_mct(t_command *, ClientClass *, ServerClass *);
int command_tna(t_command *, ClientClass *, ServerClass *);
int command_ppo(t_command *, ClientClass *, ServerClass *);
int command_plv(t_command *, ClientClass *, ServerClass *);
int command_pin(t_command *, ClientClass *, ServerClass *);
int command_sgt(t_command *, ClientClass *, ServerClass *);
int command_sst(t_command *, ClientClass *, ServerClass *);
int command_forward(t_command *, ClientClass *, ServerClass *);
int command_right(t_command *, ClientClass *, ServerClass *);
int command_left(t_command *, ClientClass *, ServerClass *);
int command_look(t_command *, ClientClass *, ServerClass *);
int command_inventory(t_command *, ClientClass *, ServerClass *);
int command_broadcast(t_command *, ClientClass *, ServerClass *);
int command_connectnbr(t_command *, ClientClass *, ServerClass *);
int command_fork_before(t_command *, ClientClass *, ServerClass *);
int command_fork_after(t_command *, ClientClass *, ServerClass *);
int command_eject(t_command *, ClientClass *, ServerClass *);
int command_take(t_command *, ClientClass *, ServerClass *);
int command_set(t_command *, ClientClass *, ServerClass *);
int command_invocation_before(t_command *, ClientClass *, ServerClass *);
int command_invocation_after(t_command *, ClientClass *, ServerClass *);

t_command *command_get_from_buffer(char *buffer);

    #define Command_getFromBuffer(b) command_get_from_buffer(b)

static const t_command _commands[] = {
    {"msz", command_msz, NULL, 0, GUI_USER, 0},
    {"bct", command_bct, NULL, 2, GUI_USER, 0},
    {"mct", command_mct, NULL, 0, GUI_USER, 0},
    {"tna", command_tna, NULL, 0, GUI_USER, 0},
    {"ppo", command_ppo, NULL, 1, GUI_USER, 0},
    {"plv", command_plv, NULL, 1, GUI_USER, 0},
    {"pin", command_pin, NULL, 1, GUI_USER, 0},
    {"sgt", command_sgt, NULL, 0, GUI_USER, 0},
    {"sst", command_sst, NULL, 1, GUI_USER, 0},
    {"Forward", NULL, command_forward, 0, IA_USER, 7},
    {"Right", NULL, command_right, 0, IA_USER, 7},
    {"Left", NULL, command_left, 0, IA_USER, 7},
    {"Look", NULL, command_look, 0, IA_USER, 7},
    {"Inventory", NULL, command_inventory, 0, IA_USER, 1},
    {"Broadcast", NULL, command_broadcast, 1, IA_USER, 7},
    {"Connect_nbr", NULL, command_connectnbr, 0, IA_USER, 0},
    {"Fork", command_fork_before, command_fork_after, 0, IA_USER, 42},
    {"Eject", NULL, command_eject, 0, IA_USER, 7},
    {"Take", NULL, command_take, 1, IA_USER, 7},
    {"Set", NULL, command_set, 1, IA_USER, 7},
    {"Incantation", command_invocation_before, command_invocation_after, 0,\
    IA_USER, 300}
};

#endif /* !COMMAND_H_ */
