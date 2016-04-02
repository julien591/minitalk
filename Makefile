##
## Makefile for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\prog_elem_s1\PSU_2015_minitalk
##
## Made by Julien Leleu
## Login   <Julien@epitech.net>
##
## Started on  Mon Feb 01 10:43:25 2016 Julien Leleu
## Last update Mon Feb 01 10:43:25 2016 Julien Leleu
##

NAME1	= server

NAME2	= client

SRC1	= server.c \
	  Function.c

SRC2	= client.c \
	  Function.c

all: compil

compil:
	cd ./server && gcc -o $(NAME1) $(SRC1) -I./
	cd ./client && gcc -o $(NAME2) $(SRC2) -I./

clean:
	cd ./server && rm -rf *~
	cd ./client && rm -rf *~

fclean: clean
	cd ./server && rm -rf $(NAME1)
	cd ./client && rm -rf $(NAME2)

re: fclean all
