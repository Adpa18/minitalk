/*
** client.c for client in /home/wery_a/rendu/minitalk/Test/v1/client
** 
** Made by adrien wery
** Login   <wery_a@epitech.net>
** 
** Started on  Tue Feb 24 15:07:42 2015 adrien wery
** Last update Wed Mar 18 15:15:02 2015 adrien wery
*/

#include "minitalk.h"
# define BUFF_SIZE 1024

void    go(int sig)
{
  (void)sig;
  *d() = 1;
}

void	send(int pid, int bit)
{
  int	i;

  i = -1;
  *d() = 0;
  if (bit == 0)
    kill(pid, SIGUSR1);
  else if (bit == 1)
    kill(pid, SIGUSR2);
  if (*b() == 0)
    usleep(20);
  else
    while (*d() == 0)
      if (++i >= 1000000)
	lost_cli(pid);
}

void	send_int(int pid_ser, int pid_cli, int len)
{
  int	i;

  *b() = 0;
  i = -1;
  while (++i < len)
    send(pid_ser, (pid_cli >> i) & 1);
  *b() = 1;
}

void	send_str(char *s, int pid)
{
  int	i;

  i = -1;
  s[my_str(s, 0)] = '\0';
  while (s[++i] != '\0')
    {
      send(pid, (s[i] >> 0) & 1);
      send(pid, (s[i] >> 1) & 1);
      send(pid, (s[i] >> 2) & 1);
      send(pid, (s[i] >> 3) & 1);
      send(pid, (s[i] >> 4) & 1);
      send(pid, (s[i] >> 5) & 1);
      send(pid, (s[i] >> 6) & 1);
      send(pid, (s[i] >> 7) & 1);
    }
}

void    send_file(char *file, int pid)
{
  int   fd;
  char  *s;
  int	i;

  s = malloc(BUFF_SIZE + 1);
  if ((fd = open(file, O_RDONLY)) == -1)
    my_error("Error on opening");
  send_int(pid, 1801, 32);
  while (read(fd, s, BUFF_SIZE) > 0)
    {
      send_str(s, pid);
      i = -1;
      while (++i < BUFF_SIZE)
	s[i] = '\0';
    }
}

int	main(int argc, char **argv)
{
  int	pid;
  int	i;

  if (argc < 3)
    my_error("Need PID and message");
  if ((pid = my_getnbr_base(argv[1], "0123456789")) == -1)
      my_error("PID = -1, I don't like this");
  signal(SIGUSR1, &go);
  signal(SIGUSR2, &test);
  send_int(pid, getpid(), 32);
  if (argv[2][0] == '-' && argv[2][1] == 'f' && argv[3])
    send_file(argv[3], pid);
  else
    {
      send_int(pid, my_str(argv[2], 0), 32);
      i = -1;
      while (argv[++i])
	send_str(argv[i], pid);
    }
  send_int(pid, 0, 8);
  succes_cli(pid);
  return (0);
}
