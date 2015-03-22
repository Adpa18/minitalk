/*
** minitalk.h for minitalk in /home/wery_a/rendu/minitalk/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:26:43 2015 adrien wery
** Last update Sun Mar 22 23:13:10 2015 adrien wery
*/

#include <signal.h>
#include <stdlib.h>

void    send_int(int pid_ser, int pid_cli, int len);
void    send_str(char *s, int pid);
void	send(int pid, int bit);
void    my_mem(char *s, char c, int len);
void	go(int sig);
void	test(int sig);
void    succes_cli(int pid);
void    lost_cli(int pid);
char	*b();
char	*d();
