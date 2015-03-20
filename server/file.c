/*
** file.c for file in /home/wery_a/rendu/minitalk/Test/v6
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Mar 17 14:03:44 2015 adrien wery
** Last update Tue Mar 17 14:41:02 2015 adrien wery
*/

#include "minitalk.h"

char    *gen_name(char *start)
{
  static int    nb = 0;
  char          *s;
  int           i;

  i = -1;
  s = malloc(my_str(start, 0) + 2);
  while (start[++i])
    s[i] = start[i];
  s[i] = ++nb + 48;
  s[++i] = '\0';
  return (s);
}

void    reset_file()
{
  static char   *name;

  if (*c() == 0)
    {
      my_str("\e[01;34m\nFile is copy as ", 1);
      if (name == NULL)
        my_str("out0", 1);
      else
        my_str(name, 1);
      my_str("\e[00;37m", 1);
      succes();
      close (*fd());
      name = gen_name("out");
      if  ((*fd() = open(name, O_RDWR | O_TRUNC | O_CREAT, 0666)) == -1)
        my_error("Creat File Error");
    }
  else
    {
      write(*fd(), &(*c()), 1);
      *bit() = 0;
      *c() = '\0';
      kill(*pid_cli(), SIGUSR1);
    }
}
