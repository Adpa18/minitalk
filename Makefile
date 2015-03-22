##
## Makefile for Makefile in /home/wery_a/rendu/minitalk/Test/v1
## 
## Made by adrien wery
## Login   <wery_a@epitech.net>
## 
## Started on  Tue Feb 24 15:16:58 2015 adrien wery
## Last update Fri Mar 20 17:12:25 2015 adrien wery
##

SRC_CLI	= $(wildcard ./client/*.c)

SRC_SER	= $(wildcard ./server/*.c)

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
