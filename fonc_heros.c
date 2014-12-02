/*
** fonc_heros.c for fonction heros in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 10:54:55 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 13:00:23 2014 ALI MOUIGNI Chamsoudine
*/

#include "heros.h"
#include "outils.h"
#include <stdlib.h>

void	init_hero(char *name_h, t_heros **my_heros)
{
  (*my_heros)->name = name_h;
  (*my_heros)->pv = 100;
  (*my_heros)->pm = 30;
  (*my_heros)->potion = 5;
  (*my_heros)->ether = 5;
}

void    init_monster(t_monster **my_monster)
{
  (*my_monster)->name = "Troll";
  (*my_monster)->pv = 75;
  (*my_monster)->pm = 20;
  (*my_monster)->pm = 1;
}

int	test_won(t_monster *my_monster)
{
  if (my_monster->pv <= 0)
    {
      if (my_monster->number == 1)
	return (0);
      if (my_monster->number > 1)
	return (1);
    }
  return (2);
}

int     test_lost(t_heros *my_heros)
{
  if (my_heros->pv <= 0)
    return (0);
  return (1);
}