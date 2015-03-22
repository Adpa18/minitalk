##
## Makefile for Makefile in /home/wery_a/rendu/minitalk/Test/v1
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Tue Feb 24 15:16:58 2015 adrien wery
## Last update Sun Mar 22 23:10:33 2015 adrien wery
##

SRC_CLI	= ./client/client.c \
	  ./client/client2.c \
	  ./str/my_getnbr_base.c \
	  ./str/str.c

SRC_SER	= ./server/server.c \
	  ./server/server2.c \
	  ./server/cheat.c \
	  ./str/my_getnbr_base.c \
	  ./str/str.c

CC	= gcc

RM	= rm -f

CFLAGS	= ##-W -Wall -Wextra -O2 -march=native

CLIENT 	= ./client/client

SERVER 	= ./server/server

OBJ_CLI	= $(SRC_CLI:.c=.o)

OBJ_SER	= $(SRC_SER:.c=.o)

$(CLIENT): $(OBJ_CLI)
	$(CC) $(OBJ_CLI) -o $(CLIENT)

$(SERVER): $(OBJ_SER)
	$(CC) $(OBJ_SER) -o $(SERVER)

all: $(CLIENT) $(SERVER)

clean:
	$(RM) $(OBJ_SER) $(OBJ_CLI) *~ *#

fclean: clean
	$(RM) $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
