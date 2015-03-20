/*
** minitalk.h for minitalk in /home/wery_a/rendu/minitalk/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:26:43 2015 adrien wery
** Last update Fri Mar 20 17:13:52 2015 adrien wery
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

//	str
void	my_putchar(char c);
int     my_str(char *s, int mode);
void    my_putnbr(int nb);
void    my_error(char *s);
int     my_getnbr_base(char *s, char *base);

//	client
void    send_int(int pid_ser, int pid_cli, int len);
void    send_str(char *s, int pid);
void    send_file(char *file, int pid);
void	send(int pid, int bit);
void    my_mem(char *s, char c, int len);
void	go(int sig);
void	test(int sig);
void    succes_cli(int pid);
void    lost_cli(int pid);
char	*b();
char	*d();
