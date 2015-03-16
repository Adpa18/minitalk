/*
** server2.c for server2 in /home/wery_a/rendu/minitalk/Test/v5
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Mar 16 21:28:54 2015 adrien wery
** Last update Mon Mar 16 23:44:11 2015 adrien wery
*/

#include "minitalk.h"

void    succes()
{
  my_str("\n\n\n", 1);
  my_str("\e[01;32m---- No Problem during the transmission ", 1);
  my_str("with the client which PID = ", 1);
  my_putnbr(*pid_cli());
  my_str(" END OF CONNECTION ----\e[00;37m\n", 1);
  *bit() = 0;
  *c() = '\0';
  reset_first(0, 1);
  get_len(0, 1);
}

void    lost()
{
  my_str("\n\n\n", 1);
  my_str("\e[01;31m---- Connection is Lost with the client which PID = ", 1);
  my_putnbr(*pid_cli());
  my_str(" END OF CONNECTION ----\e[00;37m\n", 1);
  *bit() = 0;
  *c() = '\0';
  reset_first(0, 1);
  get_len(0, 1);
}

void    reset_first(int nb, int mode)
{
  static int pid = 0;
  static int i = 0;

  if (mode == 1)
    {
      *pid_cli() = -1;
      pid = 0;
      i = 0;
    }
  else
    {
      pid |= nb << i;
      *bit() = 0;
      *c() = '\0';
      if (++i == 32)
	*pid_cli() = pid;
    }
}

void    get_len(int nb, int mode)
{
  static int    l = 0;
  static int    i = 0;

  if (mode == 1)
    {
      *len() = -1;
      l = 0;
      i = 0;
    }
  else
    {
      l |= nb << i;
      *bit() = 0;
      *c() = '\0';
      if (++i == 32)
        *len() = l;
    }
}
