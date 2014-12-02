/*
** fonc_quete22.c for fonction quete 2 in /home/alimou_c/Battle_for_midgar/alimou_c/quete2
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Sat Nov  1 12:03:58 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 17:07:44 2014 ALI MOUIGNI Chamsoudine
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

void    my_healAff(t_heros **heros, t_monster **monster)
{
  if((*heros)->pm >= 3)
    {
      my_heal(heros);
      if (test_won(*monster) == 0)
        end_game_msg(*heros, *monster);
      else
        turn_monster(heros, monster);
    }
  if ((*heros)->pm < 3)
    {
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" have insufficient \033[34;01mPM \033[00m \n\n");
      /*game_run(heros, monster);*/
      run_game(heros, monster);
    }
}

void    my_heal(t_heros **heros)
{
  if (((*heros)->pv + 25) >= 100)
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
      (*heros)->pv += 25;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use \033[31m potion\033[00m \n");
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" gain \033[31m 25 PV \033[00m\n");
    }
  (*heros)->pm -= 3;
  my_putstr("Hero lose \033[34;01m 3 PM \033[00m\n\n");
}

void    monster_kill(t_heros **heros, t_monster **monster)
{
  my_putstr("Hero ");
  my_putstr((*heros)->name);
  my_putstr(" killed a Monster \n");
  my_putstr("A new Monster  appear \n\n");
  (*monster)->number -= 1;
  (*monster)->name = "Troll";
  (*monster)->pv = 75;
  (*monster)->pm = 20;
  /* game_run(heros, monster);*/
  run_game(heros, monster);
}

void	my_criticearthquake(t_heros **heros, t_monster **monster)
{
  (*heros)->pv -= 35;
  (*monster)->pv -= 3;
  my_putstr((*monster)->name);
  my_putstr(" use earthquake \n");
  my_putstr("\033[31mCritical Hit ! \033[00m\n");
  my_putstr((*heros)->name);
  my_putstr(" lose\033[31m 35 PV \033[00m\n");
  my_putstr((*monster)->name);
  my_putstr(" lose\033[31m 3 PV\033[00m \n\n");
}

void    my_criticbite(t_heros **heros, t_monster **monster)
{
  if (((*heros)->pv - 26) < 0)
    (*heros)->pv = 0;
  else
    (*heros)->pv -= 26;
  my_putstr((*monster)->name);
  my_putstr(" use bite \n");
  my_putstr("\033[31mCritical Hit ! \033[00m\n");
  my_putstr((*heros)->name);
  my_putstr(" lose\033[31m 26 PV \033[00m\n\n");
}