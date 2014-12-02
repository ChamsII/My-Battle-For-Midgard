/*
** main.c for main in /home/alimou_c/Battle_for_midgar/alimou_c/quete1
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 11:58:41 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 14:22:59 2014 ALI MOUIGNI Chamsoudine
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "outils.h"
#include <ctype.h>
#include "heros.h"
#define my_clear() my_putstr("\033[H\033[2J")

int	main(int argc, char **argv)
{
  my_clear();
  aff_plan_b(argc, argv);
  my_putstr("\n");
  return (0);
}