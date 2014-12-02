/*
** fonc_quete2.c for fonction quete2 in /home/alimou_c/Battle_for_midgar/alimou_c/quete2
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Sat Nov  1 09:42:49 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 17:07:00 2014 ALI MOUIGNI Chamsoudine
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

void	my_potionAff(t_heros **heros, t_monster **monster)
{
  if((*heros)->potion > 0)
    {
      my_potion(heros);
      if (test_won(*monster) == 0)
	end_game_msg(*heros, *monster);
      else
	turn_monster(heros, monster);
    }
  if ((*heros)->potion == 0)
    {
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" doesn't have any \033[31m potion\033[00m \n\n");
      /*      game_run(heros, monster);*/
      run_game(heros, monster);
    }
}

void    my_etherAff(t_heros **heros, t_monster **monster)
{
  if((*heros)->ether > 0)
    {
      my_ether(heros);
      if (test_won(*monster) == 0)
        end_game_msg(*heros, *monster);
      else
        turn_monster(heros, monster);
    }
  if ((*heros)->ether == 0)
    {
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" doesn't have any \033[31m ether\033[00m \n\n");
      /* game_run(heros, monster);*/
      run_game(heros, monster);
    }
}


void	my_potion(t_heros **heros)
{
  if (((*heros)->pv + 30) >= 100)
    {
      (*heros)->pv = 100;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use \033[31m potion\033[00m \n");
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" gain \033[31m ");
      my_put_nbr(100 - (*heros)->pv);
      my_putstr(" PV \033[00m\n");
    }
  else
    {
      (*heros)->pv += 30;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use \033[31m potion\033[00m \n");
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" gain \033[31m 30 PV \033[00m\n");
    }
  (*heros)->potion -= 1;
  my_putstr("Hero lose \033[31m 1 potion \033[00m\n\n");
}

void    my_ether(t_heros **heros)
{
  if (((*heros)->pm + 12) >= 30)
    {
      (*heros)->pv = 30;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use \033[31m ether\033[00m \n");
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" gain \033[34;01m ");
      my_put_nbr(30 - (*heros)->pm);
      my_putstr(" PM \033[00m\n");
    }
  else
    {
      (*heros)->pm += 12;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use \033[31m ether\033[00m \n");
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" gain \033[34;01m 12 PM \033[00m\n");
    }
  (*heros)->ether -= 1;
  my_putstr("Hero lose \033[34;01m 1 Ether\033[00m\n\n");
}

void	my_nb_monster(t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 3);
  if (nb_alea == 0)
    (*monster)->number = 1;
  if (nb_alea == 1)
    (*monster)->number = 2;
  if (nb_alea == 2)
    (*monster)->number = 3;
}