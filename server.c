/*
** server.c for server in /home/wery_a/rendu/minitalk/Test/v1/server
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:13:20 2015 adrien wery
** Last update Mon Mar 16 23:44:39 2015 adrien wery
*/

#include "minitalk.h"

void	reset()
{
  if (*c() == 4)
    succes();
  else
    {
      write(1, &(*c()), 1);
      *bit() = 0;
      *c() = '\0';
      kill(*pid_cli(), SIGUSR1);
    }
}

void	zero(int sig)
{
  (void)sig;
  *bit() += 1;
  if (*pid_cli() == -1)
    reset_first(0, 0);
  else if (*len() == -1)
    get_len(0, 0);
  else if (*bit() == 8)
    reset();
  else if (kill(*pid_cli(), SIGUSR1) == -1)
    lost();
}

void	one(int sig)
{
  (void)sig;
  *c() |= 1 << *bit();
  *bit() += 1;
  if (*pid_cli() == -1)
    reset_first(1, 0);
  else if (*len() == -1)
    get_len(1, 0);
  else if (*bit() == 8)
    reset();
  else if (kill(*pid_cli(), SIGUSR1) == -1)
    lost();
}

int     main()
{
  *c() = '\0';
  *bit() = 0;
  *pid_cli() = -1;
  *len() = -1;
  my_str("PID = ", 1);
  my_putnbr(getpid());
  my_putchar('\n');
  signal(SIGUSR1, &zero);
  signal(SIGUSR2, &one);
  while (42)
    {
      if (*pid_cli() != -1 && kill(*pid_cli(), SIGUSR2) == -1)
	lost();
      usleep(1);
    }
  return (0);
}
