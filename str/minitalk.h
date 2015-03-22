/*
** minitalk.h for minitalk in /home/wery_a/rendu/minitalk/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:26:43 2015 adrien wery
** Last update Sun Mar 22 23:11:42 2015 adrien wery
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

void	my_putchar(char c);
int     my_str(char *s, int mode);
void    my_putnbr(int nb);
void    my_error(char *s);
int     my_getnbr_base(char *s, char *base);
