/*
** readline.c for readline in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 11:54:41 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 17:28:26 2014 ALI MOUIGNI Chamsoudine
*/
#include <unistd.h>
#include "outils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "heros.h"

char    *readLine()
{
  ssize_t       ret;
  char  *buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}

void    end_game_msg(t_heros *heros, t_monster *monster)
{
  if (heros->pv <= 0 && monster->pv > 0)
    {
      my_putstr("Monster ");
      my_putstr(monster->name);
      my_putstr(" has defected the hero \n");
      my_putstr("Damage, You Lost !!");
    }
  if (heros->pv > 0 && monster->pv <= 0)
    {
      my_putstr("Herro ");
      my_putstr(heros->name);
      my_putstr(" has defected the monsters \n");
      my_putstr("Congratulation, You Won !!");
    }
  if (heros->pv <= 0 && monster->pv <= 0)
    {
      my_putstr(" match nul \n");
      my_putstr("Congratulation,  !!");
    }
}

void    run_game(t_heros **heros, t_monster **monster)
{
  char	*buffer;

  my_putstr("Your turn > ");
  buffer = readLine();
  if (my_strcmp(buffer, "quit") == 0)
    {
      my_putstr("Vous quitter le jeu \n");
      exit(EXIT_SUCCESS);
    }
  if (my_strcmp(buffer, "help") == 0)
    aff_help();
  else
    {
      select_cmd(buffer, heros, monster);
      if (test_lost(*heros) == 0)
	end_game_msg(*heros, *monster);
    }
}