/*
** Function.c for C:\Users\Julien\Desktop\rendu in C:\Users\Julien\Desktop\rendu\prog_elem_s1\PSU_2015_minitalk
**
** Made by Julien Leleu
** Login   <Julien@epitech.net>
**
** Started on  Mon Feb 01 11:27:45 2016 Julien Leleu
** Last update Sun Feb 07 15:27:18 2016 Julien Leleu
*/

#include <unistd.h>

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	my_getnbr(char *str)
{
  int i;
  int nbr;
  int negatif;

  i = 0;
  nbr = 0;
  negatif = 0;
  while (str[i] != '\0')
    {
      while (str[i] < '0' || str[i] > '9')
	{
	  if (str[i] == '-')
	    negatif++;
	  i++;
	}
      while (str[i] >= '0' && str[i] <= '9')
	{
	  nbr = ((nbr * 10) + (str[i] - 48));
	  i++;
	}
    }
  if (negatif % 2 != 0)
    nbr = -nbr;
  return (nbr);
}
