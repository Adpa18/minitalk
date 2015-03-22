/*
** cheat.c for cheat in /home/wery_a/rendu/minitalk/Test/v5
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Mon Mar 16 21:26:24 2015 adrien wery
** Last update Sun Mar 22 13:02:47 2015 adrien wery
*/

char    *c()
{
  static char   a = 0;

  return (&a);
}

int     *bit()
{
  static int	 a = 0;

  return (&a);
}

int     *pid_cli()
{
  static int	a = 0;

  return (&a);
}

int     *len()
{
  static int	a = 0;

  return (&a);
}
