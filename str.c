/*
** str.c for str in /home/wery_a/rendu/minitalk/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:26:23 2015 adrien wery
** Last update Mon Mar 16 18:37:21 2015 adrien wery
*/

#include "minitalk.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_str(char *s, int mode)
{
  int	i;

  i = 0;
  while (s[i])
    {
      if (mode == 1)
	my_putchar(s[i]);
      i += 1;
    }
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
    }
  if (s1[i] == '\0' && s2[i] == '\0')
    return (0);
  else
    return (-1);
}

void    my_putnbr(int nb)
{
  if (nb / 10 > 0)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + 48);
}

void     my_error(char *s)
{
  my_str(s, 1);
  write(1, "\n", 1);
  exit(EXIT_FAILURE);
}
