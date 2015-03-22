/*
** server.c for server in /home/wery_a/rendu/minitalk/Test/v1/server
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:13:20 2015 adrien wery
** Last update Sun Mar 22 13:01:49 2015 adrien wery
*/

#include "minitalk.h"

void	reset(char ch)
{
  if (ch == 0)
    succes();
  else
    write(1, &ch, 1);
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
    {
      reset(*c());
      *c() = '\0';
      *bit() = 0;
      if (*pid_cli() > 0)
	kill(*pid_cli(), SIGUSR1);
    }
  else if (*pid_cli() > 0 && kill(*pid_cli(), SIGUSR1) == -1)
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
    {
      reset(*c());
      *c() = '\0';
      *bit() = 0;
      if (*pid_cli() > 0)
	kill(*pid_cli(), SIGUSR1);
    }
  else if (*pid_cli() > 0 && kill(*pid_cli(), SIGUSR1) == -1)
    lost();
}

int     main()
{
  unsigned int	i;

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
      i = -1;
      while (++i < 1000000);
      if (*pid_cli() != -1 && kill(*pid_cli(), SIGUSR2) == -1)
	lost();
    }
  return (0);
}
