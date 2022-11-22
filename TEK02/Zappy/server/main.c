/*
** EPITECH PROJECT, 2022
** Zappy
** File description:
** main
*/

#include "./server.h"
#include "./system/new.h"
#include "./includes/common.h"

#include <unistd.h>

static int print_usage(char *suppl)
{
    printf("%s\n", suppl);
    printf("USAGE: ./zappy_server -p port -x width -y height -n name1 name2");
    printf("... -c clientsNb -f freq\n\tport\tis the port number\n\twidth\t");
    printf("is the width of the world\n\theight\tis the height of the world");
    printf("\n\tnameX\tis the name of the team X\n\tclientsNb\tis the numbe");
    printf("r of authorized clients per team\n\tfreq\tis the reciprocal of ");
    printf("time unit for execution of actions\n");
    return (0);
}

static int read_options_next(int elem[127], ServerClass **server)
{
    Server_addTeam(*server, GRAPHIC_TEAM, GUI_USER);
    if ((elem['x'] < 10 || elem['x'] > 30) || (elem['y'] < 10 || elem['y'] >
    30))
        return (print_usage("-x/-y option only accepts integer values between"\
        " 10 and 30\n"));
    Server_createMap(*server, elem['x'], elem['y']);
    if (elem['c'] < 0)
        return (print_usage("Invalid number of player per team must be >"\
        " 0\n"));
    (*server)->max_players_team = elem['c'];
    if (elem['f'] >= 2 && elem['f'] <= 10000)
        Server_setTimeUnit(*server, elem['f']);
    else if (elem['f'] != 0)
        return (print_usage("-f option only accepts integer values between 2"\
        " and 10000\n"));
    return (1);
}

static int read_options(int ac, char **av, ServerClass **server)
{
    int elem[127] = {0};

    for (int opt = 0; (opt = getopt(ac, av, ":p:x:y:n:c:f:")) != -1;) {
        switch (opt) {
            case 'n':
                for(optind--; optind < ac && *av[optind] != '-'; optind++)
                    Server_addTeam(*server, av[optind], IA_USER);
                break;
            case 'p':
                *server = new(Server, atoi(optarg));
                break;
            default:
                if (!(opt == 'x' || opt == 'y' || opt == 'c' || opt == 'f'))
                    raise("Invalid arguments !");
                elem[opt] = atoi(optarg);
        };
    }
    return (read_options_next(elem, server));
}

static void create_loggers(ServerClass *server)
{
    server->logs[0] = new(Logger, "logs/logger.log", ALL);
    server->logs[1] = new(Logger, "logs/IAlogger.log", IA_USER);
    server->logs[2] = new(Logger, "logs/GUIlogger.log", GUI_USER);
}

int main(int ac, char **av)
{
    ServerClass *server = NULL;
    int port = 0;

    if (ac < 11)
        return (84);
    if (!read_options(ac, av, &server)) {
        if (server)
            delete(server);
        return (84);
    }
    return (0);
    srand(time(NULL));
    create_loggers(server);
    Generation_start(server);
    Server_start(server);
    delete(server);
}