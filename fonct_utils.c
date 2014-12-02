/*
** fonct_utils.c for fonct_utils in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 19:02:31 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 16:17:32 2014 ALI MOUIGNI Chamsoudine
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "outils.h"
#include <ctype.h>
#include <time.h>
#include "heros.h"

void    turn_monster(t_heros **heros, t_monster **monster)
{
  int   nb_alea;

  srand(time(NULL));
  nb_alea = (rand() % 3);
  if (nb_alea == 0)
    my_bite(heros, monster);
  if (nb_alea == 1)
    my_earthquake(heros, monster);
  if (nb_alea == 2)
    my_doom(heros, monster);
}

void    my_bite(t_heros **heros, t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 10) + 1;
  if (nb_alea ==1)
    my_criticbite(heros, monster);
  else
    {
      if (((*heros)->pv - 6) < 0)
	(*heros)->pv = 0;
      else
	(*heros)->pv -= 6;
      my_putstr((*monster)->name);
      my_putstr(" use bite \n");
      my_putstr((*heros)->name);
      my_putstr(" lose\033[31m 6 PV \033[00m\n\n");
    }
}

void    my_earthquake(t_heros **heros, t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 10) + 1;
  if (nb_alea ==1)
    my_criticearthquake(heros, monster);
  else
    {
      (*heros)->pv -= 15;
      (*monster)->pv -= 3;
      my_putstr((*monster)->name);
      my_putstr(" use earthquake \n");
      my_putstr((*heros)->name);
      my_putstr(" lose\033[31m 15 PV \033[00m\n");
      my_putstr((*monster)->name);
      my_putstr(" lose\033[31m 3 PV\033[00m \n\n");
    }
}

void    my_doom(t_heros **heros, t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 10) + 1;
  if (nb_alea ==1)
    my_criticdoom(heros, monster);
  else
    {
      (*heros)->pv -= 11;
      (*monster)->pm -= 5;
      my_putstr((*monster)->name);
      my_putstr(" use doom \n");
      my_putstr((*heros)->name);
      my_putstr(" lose\033[31m 11 PV \033[00m\n");
      my_putstr((*monster)->name);
      my_putstr(" lose \033[34;01m5 PM\033[00m \n\n");
    }
}

int     end_game(t_heros *heros, t_monster *monster)
{
  if (heros->pv <= 0 || 
      (monster->pv <= 0 && monster->number == 1))
    return (1);
  return (0);
}