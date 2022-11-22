/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** command
*/

#include "./command.h"

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Check if entry is a valid command
** @param string (entry) : Desired entry to check into
**
** @return Pointer on command that match or null
**/
const static t_command *entry_match_command(char *entry)
{
    t_command *command = NULL;

    if (!entry)
        return (NULL);
    for (int i = 0; i < NB_CMD; i++) {
        if (!strcmp(_commands[i].name, entry)) {
            command = malloc(sizeof(t_command));
            *command = _commands[i];
            return (command);
        }
    }
    return (NULL);
}

/**
** @author : Paul Gazeau-Rousseau
**
** @brief Function *command_get_from_buffer: Get command from entry
** @param entry (char*): Desired entry to check into
**
** @return Pointer on command that match filled with args or null
**/
t_command *command_get_from_buffer(char *entry)
{
    t_command *cmd = NULL;
    char **args = NULL;
    int len = 0;

    if (!entry || entry[0] == '\0')
        return (NULL);
    if (!(args = concat_words(entry, " \t\v\r\n\f")))
        return (NULL);
    len = number_of_words(entry, " \t\v\r\n\f");
    if (!(cmd = entry_match_command(args[0])))
        return (NULL);
    args += 1;
    cmd->args = args;
    cmd->nb_args = (len - 1);
    return (cmd);
}