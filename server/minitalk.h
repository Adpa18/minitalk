/*
** minitalk.h for minitalk in /home/wery_a/rendu/minitalk/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:26:43 2015 adrien wery
** Last update Sun Mar 22 23:13:23 2015 adrien wery
*/

#include <signal.h>
#include <stdlib.h>

void	reset_first(int nb, int mode);
void	get_len(int nb, int mode);
void    zero(int sig);
void    one(int sig);
void	reset(char ch);
void	succes();
void	lost();
char	*c();
int	*bit();
int	*len();
int	*pid_cli();
