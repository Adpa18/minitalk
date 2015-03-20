/*
** client2.c for client2 in /home/wery_a/rendu/minitalk/Test/v5
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Mar 16 21:36:22 2015 adrien wery
** Last update Tue Mar 17 15:22:54 2015 adrien wery
*/

#include "minitalk.h"

void    test(int sig)
{
  (void)sig;
}

void    succes_cli(int pid)
{
  my_str("\n", 1);
  my_str("\e[01;32m---- No Problem during the transmission ", 1);
  my_str("with the server which PID = ", 1);
  my_putnbr(pid);
  my_str(" END OF CONNECTION ----\e[00;37m\n", 1);
}

void    lost_cli(int pid)
{
  my_str("\n", 1);
  my_str("\e[01;31m ---- Connection can't be etablished", 1);
  my_str(" with the server which PID = ", 1);
  my_putnbr(pid);
  my_str(" END OF CONNECTION ----\e[00;37m\n\n", 1);
  exit(-1);
}
char    *d()
{
  static char   a = 0;

  return (&a);
}

char    *b()
{
  static char   a = 0;

  return (&a);
}
