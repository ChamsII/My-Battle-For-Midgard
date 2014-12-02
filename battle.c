/*
** battle.c for battle in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 12:01:27 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 17:26:04 2014 ALI MOUIGNI Chamsoudine
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

void	aff_plan_b(int argc, char **argv)
{
  t_heros	*heros;
  t_monster	*monster;

  if (argc < 2)
    my_putstr("USAGE: <-n> <Player name> \n");
  else 
    {
      if (my_strcmp("-n", argv[1]) != 0)
	init_hero("(null)", &heros);
      heros = malloc(sizeof(*heros));
      if (heros != 0)
          init_hero(argv[2], &heros);
      monster = malloc(sizeof(*monster));
      if (monster != 0)
	init_monster(&monster);
      if (heros != 0 && monster != 0)
	{
	  my_nb_monster(&monster);
	  game_run(&heros, &monster);
	}
      else
	my_putstr(" \033[31mERROR Allocation memoir ! \033[00m\n ");
    }
}

void	game_run(t_heros **heros, t_monster **monster)
{
  do
    {
      run_game(heros, monster);
    }while (end_game(*heros, *monster) == 0);
}

void	select_cmd(char *buffer, t_heros **heros, t_monster **monster)
{
  if (my_strcmp("attack", buffer) == 0)
    my_attack(heros, monster);
  if (my_strcmp("slash", buffer) == 0)
    my_slash(heros, monster);
  if (my_strcmp("fire", buffer) == 0)
    my_fire(heros, monster);
  if (my_strcmp("thunder", buffer) == 0)
    my_thunder(heros, monster);
  if (my_strcmp("stat", buffer) == 0)
    my_stat(heros);
  if (my_strcmp("libra", buffer) == 0)
    my_libra(heros, monster);
  if (my_strcmp("potion", buffer) == 0)
    my_potionAff(heros, monster);
  if (my_strcmp("ether", buffer) == 0)
    my_etherAff(heros, monster);
  if (my_strcmp("heal", buffer) == 0)
    my_healAff(heros, monster);
}
void	aff_help()
{
  my_putstr("|-- attack \n");
  my_putstr("|-- slash \n");
  my_putstr("|-- fire \n");
  my_putstr("|-- thunder \n");
  my_putstr("|-- stat \n");
  my_putstr("|-- libra \n");
  my_putstr("|-- potion \n");
  my_putstr("|-- ether \n");
  my_putstr("|-- heal \n");
  my_putstr("|-----------| \n");
  my_putstr("  |-- help \n");
  my_putstr("  |-- quit \n");
}

void	my_attack(t_heros **heros, t_monster **monster)
{
  int	nb_alea;
  srand(time(NULL));
  nb_alea = (rand() % 10) + 1;
  if (nb_alea ==1) 
    my_criticattack(heros, monster);
  else
    {
      (*monster)->pv -= 7;
      my_putstr("Hero ");
      my_putstr((*heros)->name);
      my_putstr("use attack \n");
      my_putstr((*monster)->name);
      my_putstr(" lose \033[31m 7 PV\033[00m \n\n");
      if (test_won(*monster) == 0)
	end_game_msg(*heros, *monster);
      else if (test_won(*monster) == 1)
	monster_kill(heros, monster);
      else
	turn_monster(heros, monster);
    }
}