/*
** fonc_critical.c for fonc_critical in /home/alimou_c/Battle_for_midgar/alimou_c/quete2
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Sat Nov  1 15:12:12 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 16:05:53 2014 ALI MOUIGNI Chamsoudine
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

void    my_criticfire(t_heros **heros, t_monster **monster)
{
  (*monster)->pv -= 30;
  (*heros)->pm -= 3;
  my_putstr("Hero ");
  my_putstr((*heros)->name);
  my_putstr(" use fire \n");
  my_putstr("\033[31mCritical Hit !\033[00m \n");
  my_putstr((*monster)->name);
  my_putstr(" lose\033[31m 30 PV \033[00m\n");
  my_putstr("hero lose \033[34;01m3 PM\033[00m \n\n");
  if (test_won(*monster) == 0)
    end_game_msg(*heros, *monster);
  else if (test_won(*monster) == 1)
    monster_kill(heros, monster);
  else
    turn_monster(heros, monster);
}

void    my_criticthunder(t_heros **heros, t_monster **monster)
{
  (*monster)->pv -= 35;
  (*heros)->pm -= 5;
  my_putstr("Hero ");
  my_putstr((*heros)->name);
  my_putstr(" use thunder \n");
  my_putstr("\033[31mCritical Hit !\033[00m \n");
  my_putstr((*monster)->name);
  my_putstr(" lose\033[31m 35 PV \033[00m\n");
  my_putstr("hero lose\033[31m 5 PM \033[00m\n\n");
  if (test_won(*monster) == 0)
    end_game_msg(*heros, *monster);
  else if (test_won(*monster) == 1)
    monster_kill(heros, monster);
  else
    turn_monster(heros, monster);
}

void	my_criticattack(t_heros **heros, t_monster **monster)
{
  (*monster)->pv -= 27;
  my_putstr("Hero ");
  my_putstr((*heros)->name);
  my_putstr("use attack \n");
  my_putstr("\033[31mCrticial Hit !\033[00m\n");
  my_putstr((*monster)->name);
  my_putstr(" lose \033[31m 27 PV\033[00m \n\n");
  if (test_won(*monster) == 0)
    end_game_msg(*heros, *monster);
  else if (test_won(*monster) == 1)
    monster_kill(heros, monster);
  else
    turn_monster(heros, monster);
}

void    my_criticslash(t_heros **heros, t_monster **monster)
{
  (*monster)->pv -= 30;
  (*heros)->pv -= 2;
  my_putstr("Hero ");
  my_putstr((*heros)->name);
  my_putstr(" use slash \n");
  my_putstr("\033[31mCritical Hit !\033[00m\n");
  my_putstr((*monster)->name);
  my_putstr(" lose\033[31m 30 PV \033[00m\n");
  my_putstr("hero lose\033[31m 2 PV \033[00m\n\n");
  if (test_won(*monster) == 0)
    end_game_msg(*heros, *monster);
  else if (test_won(*monster) == 1)
    monster_kill(heros, monster);
  else
    turn_monster(heros, monster);
}

void	my_criticdoom(t_heros **heros, t_monster **monster)
{
  (*heros)->pv -= 31;
  (*monster)->pm -= 5;
  my_putstr((*monster)->name);
  my_putstr(" use doom \n");
  my_putstr("\033[31mCritical Hit ! \033[00m\n");
  my_putstr((*heros)->name);
  my_putstr(" lose\033[31m 31 PV \033[00m\n");
  my_putstr((*monster)->name);
  my_putstr(" lose \033[34;01m5 PM\033[00m \n\n");
}