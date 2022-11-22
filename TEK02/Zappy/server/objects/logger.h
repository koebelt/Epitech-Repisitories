/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace) [WSL : Ubuntu]
** File description:
** logger
*/

#ifndef LOGGER_H_
    #define LOGGER_H_

    #include "../system/object.h"
    #include "../includes/common.h"
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

    typedef struct {
        Class base;
        int fd;
        Permission permission;
    } LoggerClass;

    void logger_ctor(LoggerClass *this, va_list *args);
    void logger_dtor(LoggerClass *this);

    static const LoggerClass _loggerdescription = {
        {
             .__size__ = sizeof(LoggerClass),
            .__name__ = "Client",
            .__ctor__ = (ctor_t)&logger_ctor,
            .__dtor__ = (dtor_t)&logger_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
            .__functions__ = NULL
        },
        .fd = 0,
        .permission = ALL
    };

    static const Class *Logger = (const Class *)&_loggerdescription;

#endif /* !LOGGER_H_ */
