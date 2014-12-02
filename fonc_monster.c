/*
** fonc_monster.c for fonct_monster in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 18:53:14 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 15:31:04 2014 ALI MOUIGNI Chamsoudine
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

void    my_slash(t_heros **heros, t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 10) + 1;
  if (nb_alea ==1) 
    my_criticslash(heros, monster);
  else
    {
      (*monster)->pv -= 10;
      (*heros)->pv -= 2;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use slash \n");
      my_putstr((*monster)->name);
      my_putstr(" lose\033[31m 10 PV \033[00m\n");
      my_putstr("hero lose\033[31m 2 PV \033[00m\n\n");
      if (test_won(*monster) == 0)
	end_game_msg(*heros, *monster);
      else if (test_won(*monster) == 1)
	monster_kill(heros, monster);
      else
	turn_monster(heros, monster);
    }
}

void    my_fire(t_heros **heros, t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 10) + 1;
  if (nb_alea ==1) 
    my_criticfire(heros, monster);
  else
    {
      (*monster)->pv -= 10;
      (*heros)->pm -= 3;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use fire \n");
      my_putstr((*monster)->name);
      my_putstr(" lose\033[31m 10 PV \033[00m\n");
      my_putstr("hero lose \033[34;01m3 PM\033[00m \n\n");
      if (test_won(*monster) == 0)
	end_game_msg(*heros, *monster);
      else if (test_won(*monster) == 1)
	monster_kill(heros, monster);
      else
	turn_monster(heros, monster);
    }
}

void    my_thunder(t_heros **heros, t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 10) + 1;
  if (nb_alea ==1) 
    my_criticthunder(heros, monster);
  else
    {
      (*monster)->pv -= 15;
      (*heros)->pm -= 5;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr(" use thunder \n");
      my_putstr((*monster)->name);
      my_putstr(" lose\033[31m 15 PV\033[00m \n");
      my_putstr("hero lose \033[34;01m5 PM\033[00m\n\n");
      if (test_won(*monster) == 0)
	end_game_msg(*heros, *monster);
      else if (test_won(*monster) == 1)
	monster_kill(heros, monster);
      else
	turn_monster(heros, monster);
    }
}

void    my_stat(t_heros **heros)
{
  my_putstr("Hero : ");
  my_putstr((*heros)->name);
  my_putstr("\n\033[32m|--PV : ");
  my_put_nbr((*heros)->pv);
  my_putstr("\033[00m\n\033[34;01m|--PM : ");
  my_put_nbr((*heros)->pm);
  my_putstr("\033[00m\n\033[31m|--Postion : ");
  my_put_nbr((*heros)->potion);
  my_putstr("\033[00m\n\033[0;33m|--Ether : ");
  my_put_nbr((*heros)->ether);
  my_putstr("\033[00m\n\n");
}


void    my_libra(t_heros **heros, t_monster **monster)
{
  (*heros)->pm -= 1;
  my_putstr((*monster)->name);
  my_putstr("\n\033[0;33m|--Number : ");
  my_put_nbr((*monster)->number);
  my_putstr("\033[00m\n\033[31m|--PV : ");
  my_put_nbr((*monster)->pv);
  my_putstr("\033[00m\n\033[34;01m|--PM : ");
  my_put_nbr((*monster)->pm);
  my_putstr("\033[00m\n\n");
  turn_monster(heros, monster);
}