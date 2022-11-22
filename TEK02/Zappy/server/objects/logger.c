/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** logger
*/

#include "logger.h"

void logger_ctor(LoggerClass *this, va_list *args)
{
    if ((this->fd = open(va_arg(*args, char *), O_WRONLY | O_CREAT, 0666)) < 0)
        raise("Cannot open file !");
    this->permission = va_arg(*args, int);
}

void logger_dtor(LoggerClass *this)
{
    close(this->fd);
}