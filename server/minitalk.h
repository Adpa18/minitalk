/*
** minitalk.h for minitalk in /home/wery_a/rendu/minitalk/Test/v1
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:26:43 2015 adrien wery
** Last update Fri Mar 20 17:14:07 2015 adrien wery
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

//	server
void	reset_first(int nb, int mode);
void	get_len(int nb, int mode);
char    *gen_name(char *start);
void    zero(int sig);
void    one(int sig);
void	reset(char ch);
void    reset_file();
void	succes();
void	lost();
char	*c();
int	*bit();
int	*len();
int	*pid_cli();
int	*fd();
