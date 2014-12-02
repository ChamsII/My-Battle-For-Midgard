/*
** heros.h for heros in /home/alimou_c/Battle_for_midgar/alimou_c
** 
** Made by ALI MOUIGNI Chamsoudine
** Login   <alimou_c@etna-alternance.net>
** 
** Started on  Fri Oct 31 09:52:33 2014 ALI MOUIGNI Chamsoudine
** Last update Sat Nov  1 17:08:13 2014 ALI MOUIGNI Chamsoudine
*/
#ifndef ____heros__
#define ____heros__

typedef	struct	s_heros
{
  char		*name;
  int		pv;
  int		pm;
  int		potion;
  int		ether;
}		t_heros;


typedef	struct	s_monster
{
  char	*name;
  int	pv;
  int	pm;
  int	number;
}	t_monster;


char	**tab_cmd_hero;
char	**tab_cmd_monster;

/* Fonction initialisation heros */
void	init_hero(char *name_h, t_heros	**my_heros);

/* Fonction initialisation tableau de commande */
void	init_cmd_heros(char **tab);

/* programme pour le jeu */
void    game_run(t_heros **heros, t_monster **monster);

/* afficger l'arbre du help */
void    aff_help();

/* entreer dans le jeu */
void    aff_plan_b(int argc, char **argv);

void    my_libra(t_heros **heros, t_monster **monster);

void    select_cmd(char *buffer, t_heros **heros, t_monster **monster);

void	my_attack(t_heros **heros, t_monster **monster);
void	my_slash(t_heros **heros, t_monster **monster);
void	my_fire(t_heros **heros, t_monster **monster);
void	my_thunder(t_heros **heros, t_monster **monster);
void	my_stat(t_heros **heros);
void	my_libra(t_heros **heros, t_monster **monster);
void    my_potion(t_heros **heros);
void    my_ether(t_heros **heros);
void    my_heal(t_heros **heros);
void    my_potionAff(t_heros **heros, t_monster **monster);
void    my_etherAff(t_heros **heros, t_monster **monster);
void    my_healAff(t_heros **heros, t_monster **monster);
void    run_game(t_heros **heros, t_monster **monster);

void    aff_hero_used(t_heros *heros, char *buffer);
/**-------------------------  monster ----------------------------------**/
void    init_monster(t_monster **my_monster);

void    init_cmd_monster(char **tab);

void    turn_monster(t_heros **heros, t_monster **monster);
void    my_bite(t_heros **heros, t_monster **monster);
void    my_earthquake(t_heros **heros, t_monster **monster);
void    my_doom(t_heros **heros, t_monster **monster);

int	end_game(t_heros *heros, t_monster *monster);
void	end_game_msg(t_heros *heros, t_monster *monster);
int	test_won(t_monster *my_monster);
int     test_lost(t_heros *my_heros);
void	my_nb_monster(t_monster **monster);
void	monster_kill(t_heros **heros, t_monster **monster);


/*********************************** critical ***********************************/
void    my_criticfire(t_heros **heros, t_monster **monster);
void    my_criticthunder(t_heros **heros, t_monster **monster);
void    my_criticattack(t_heros **heros, t_monster **monster);
void    my_criticslash(t_heros **heros, t_monster **monster);
void    my_criticbite(t_heros **heros, t_monster **monster);
void    my_criticearthquake(t_heros **heros, t_monster **monster);
void    my_criticdoom(t_heros **heros, t_monster **monster);


#endif /* defined(____heros__) */