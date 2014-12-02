/*
** outils.c for outils in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 11:36:49 2014 ALI MOUIGNI Chamsoudine
** Last update Fri Oct 31 11:56:14 2014 ALI MOUIGNI Chamsoudine
*/
#include <unistd.h>
#include "outils.h"
#include <stdlib.h>
#include "heros.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  for (i = 0; src[i] != '\0'; i++)
    dest[i] = src[i];
  dest[i] = '\0';
  return (dest);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i += 1;
    }
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0')
    {
      i += 1;
    }
  if (s1[i] == '\0')
    return (0);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] > s2[i])
	return (1);
      if (s1[i] < s2[i])
	return (-1);
      else
	i += 1;
    }
  return (s1[i] == '\0' ? -1 : 1);
}

void	my_put_nbr(int n)
{
  if (n == -2147483648)
    my_putstr("-2147483648");
  else
    {
      if (n < 0)
	{
	  my_putchar(45);
	  n = n * (-1);
	}
      if (n < 10)
	{
	  my_putchar(n + '0');
	}
      if (n >= 10)
	{
	  my_put_nbr(n / 10);
	  my_putchar(n % 10 + '0');
	}
    }
}