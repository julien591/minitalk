/*
** server.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\prog_elem_s1\PSU_2015_minitalk
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 01 11:12:32 2016 Julien Leleu
** Last update Tue Feb 16 12:16:45 2016 Julien Leleu
*/

#include <signal.h>
#include <unistd.h>
#include "my.h"

void	display(int bin)
{
  int decimal_num;
  int base;
  int rem;

  decimal_num = 0;
  base = 1;
  while (bin > 0)
    {
      rem = bin % 10;
      decimal_num = decimal_num + rem * base;
      bin = bin / 10;
      base = base * 2;
    }
  my_putchar(decimal_num);
}

void	convert(int *letter)
{
  int	i;
  int	j;
  int	temp;

  i = 0;
  j = 7;
 while (i < j)
    {
      temp = letter[i];
      letter[i] = letter[j];
      letter[j] = temp;
      i++;
      j--;
    }
  i = 0;
  j = 0;
  while (i < 8)
    {
      j = 10 * j + letter[i];
      i++;
    }
  display(j);
}

void		handle_usr(int sig)
{
  static int	letter[7];
  static int	i = 7;

  if (sig == SIGUSR1)
    letter[i] = 0;
  if (sig == SIGUSR2)
    letter[i] = 1;
  i--;
  if (i > 0)
    {
      convert(letter);
      i = 7;
    }
}

int	main()
{
  int	pid;

  pid = getpid();
  my_put_nbr(pid);
  signal(SIGUSR1, handle_usr);
  signal(SIGUSR2, handle_usr);
  while (42)
    pause();
  return (0);
}
