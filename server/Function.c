/*
** Function.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\prog_elem_s1\PSU_2015_minitalk
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 01 11:27:45 2016 Julien Leleu
** Last update Sun Feb 07 15:29:19 2016 Julien Leleu
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_put_nbr(int nb)
{
  int result;
  int diviseur;

  if (nb < 0)
    {
      write(1, "-", 1);
      nb = -nb;
    }
  diviseur = 1;
  while ((nb/diviseur) >= 10)
    diviseur = diviseur * 10;
  while (diviseur > 0)
    {
      result = (nb/diviseur) % 10;
      my_putchar(48 + result);
      diviseur = diviseur / 10;
    }
  my_putchar('\n');
}
