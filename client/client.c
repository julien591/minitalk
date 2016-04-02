/*
** client.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\prog_elem_s1\PSU_2015_minitalk
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 01 14:10:14 2016 Julien Leleu
** Last update Tue Feb 16 11:37:25 2016 Julien Leleu
*/

#include "my.h"
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void	send(int pid, char *str)
{
  int letter[7];
  char c;
  int i;
  int j;

  j = 0;
  while (j != my_strlen(str))
    {
      i = 0;
      c = str[j];
      while (i < 8)
	{
	  letter[i] = (c >> i) & 1;
	  if (letter[i] == 0)
	    kill(pid, SIGUSR1);
	  if (letter[i] == 1)
	    kill(pid, SIGUSR2);
	  i++;
	  usleep(1000);
	}
      j++;
    }
}

int	main(int ac, char **av)
{
  int	pid;

  if (ac != 3)
    {
      write(2, "Usage: ./client [PID] [str]\n", 28);
      return (0);
    }
  pid = my_getnbr(av[1]);
  send(pid, av[2]);
  return (0);
}
