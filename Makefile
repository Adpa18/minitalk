##
## Makefile for Makefile in /home/wery_a/rendu/minitalk/Test/v1
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Tue Feb 24 15:16:58 2015 adrien wery
## Last update Mon Mar 16 21:53:47 2015 adrien wery
##

SRC_CLI	= client.c \
	  client2.c \
	  str.c \
	  my_getnbr_base.c \

SRC_SER	= server.c \
	  server2.c \
	  cheat.c \
	  str.c \
	  my_getnbr_base.c \

CC	= gcc -g

RM	= rm -f

CFLAGS	= -W -Wall -Wextra

CLIENT 	= client

SERVER 	= server

OBJ_CLI	= $(SRC_CLI:.c=.o)

OBJ_SER	= $(SRC_SER:.c=.o)

$(CLIENT): $(OBJ_CLI)
	$(CC) $(OBJ_CLI) -o $(CLIENT) -lm

$(SERVER): $(OBJ_SER)
	$(CC) $(OBJ_SER) -o $(SERVER) -lm

all: $(CLIENT) $(SERVER)

clean:
	$(RM) $(OBJ_SER) $(OBJ_CLI) *~ *#

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
