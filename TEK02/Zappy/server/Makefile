##
## EPITECH PROJECT, 2022
## Zappy
## File description:
## Makefile
##

SRC		=	server.c \
			server_next.c \
			server_packet.c \
			client.c \
			client_next.c \
			system/new.c \
			system/list.c \
			utils/itoa.c \
			utils/concat_words.c \
			utils/my_strcat.c \
			objects/inventory.c \
			objects/vector.c \
			objects/vector_next.c \
			objects/zappy_map.c \
			objects/tile.c \
			objects/tile_next.c \
			objects/player.c \
			objects/team.c \
			objects/command.c \
			objects/event.c \
			objects/logger.c \
			commands/map.c \
			commands/look.c \
			commands/ia.c \
			commands/player.c \
			commands/invocation.c \
			commands/environment.c \
			commands/move.c \
			commands/time.c \
			packets/packet.c \
			algorithms/sound.c \
			algorithms/sound_next.c \
			algorithms/generation.c \
			main.c

OBJ		=	$(SRC:.c=.o)

NAME	=	zappy_server

RM		=	rm -rf

CC		=	gcc

FLAGS	=	-Wall \
			-Werror \
			-lm

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -g -o $(NAME) $(OBJ) $(FLAGS)
		cp $(NAME) ../$(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re