NAME = game

SOURCE = src/*.c

INC = inc/header.h

FLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic -D_REENTRANT -I/usr/include/SDL2 -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

all: install clean
install:
	@cp $(SOURCE) .
	@cp $(INC) .
	@clang $(FLAGS) -o $(NAME) *.c
clean:
	@rm -rf *.h
	@rm -rf *.c
uninstall: clean
	@rm -rf $(NAME)
reinstall: uninstall clean all
