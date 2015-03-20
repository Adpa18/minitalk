/*
** my_getnbr_base.c for my_getnbr_base in /home/wery_a/rendu/Allum1/Test
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 10 16:17:36 2015 adrien wery
** Last update Mon Mar 16 18:34:55 2015 adrien wery
*/

#include "minitalk.h"

int	power(int x, unsigned int y)
{
  if ( y == 0)
    return (1);
  else if (y % 2 == 0)
    return (power(x, y / 2) * power(x, y / 2));
  else
    return (x * power(x, y / 2) * power(x, y / 2));
}

int	my_getnbr_base(char *s, char *base)
{
  int  nb;
  short i;
  short n;
  short p;
  short len;

  len = my_str(base, 0);
  i = my_str(s, 0);
  p = 0;
  nb = 0;
  while (--i > -1)
    {
      if (s[i] == '-')
        return (-1 * nb);
      n = -1;
      while (s[i] != base[++n] && base[n] != '\0');
      if (base[n] == '\0' || n > len)
        n = 0;
      nb += n * power(len, p++);
    }
  return (nb);
}
