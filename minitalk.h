/*
** minitalk.h for minitalk in /home/wery_a/rendu/minitalk/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:26:43 2015 adrien wery
** Last update Tue Mar 17 00:12:43 2015 adrien wery
*/

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

//	str
void	my_putchar(char c);
int     my_str(char *s, int mode);
int     my_strcmp(char *s1, char *s2);
void    my_putnbr(int nb);
void    my_error(char *s);
int     my_getnbr_base(char *s, char *base);

//	server
void	reset_first(int nb, int mode);
void	get_len(int nb, int mode);
void    zero(int sig);
void    one(int sig);
void	reset();
void	succes();
void	lost();
char	*c();
int	*bit();
int	*len();
int	*pid_cli();

//	client
void    send_int(int pid_ser, int pid_cli, int len);
void    send_str(char *s, int pid);
void	send(int pid, int bit);
void	go(int sig);
void	test(int sig);
void    reset();
void    succes_cli(int pid);
void    lost_cli(int pid);
char	*b();
char	*d();
