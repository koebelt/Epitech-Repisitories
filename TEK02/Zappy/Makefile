##
## EPITECH PROJECT, 2022
## zappie
## File description:
## Makefile
##

all: zappy_ai zappy_gui zappy_server

zappy_ai: FORCE
	make -C IA

zappy_gui: FORCE
	rm -rf ./zappy_gui
	cd GUI ; ./run.sh

zappy_server:
	make -C server

clean:
	make clean -C IA
	make clean -C server
	rm -rf GUI/build

fclean:
	make fclean -C IA
	make fclean -C server
	rm -rf GUI/build
	rm -rf zappy_gui

re: fclean all

FORCE: ;

.PHONY: all clean fclean re FORCE

