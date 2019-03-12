/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** get_map
*/

#include "my_rpg.h"

int	exec_mob_3(core_t *cor, char **tab)
{
	if (my_strcmp(tab[0], "MAX"))
		return (exec_max(cor, tab));
	else if (my_strcmp(tab[0], "MIN"))
		return (exec_min(cor, tab));
	else
		return (0);
}

void	exec_mob_4(core_t *cor, int fd, char **tab)
{
	int i = 0;

	if (my_strcmp(tab[0], "RETURN_OBJ")) {
		if (get_size_tab(tab) != 3) {
			my_exit (84);
			return;
		}
		i = delete_mob_item(cor, my_getnbr(tab[1]));
		if (my_getnbr(tab[2]) == 1 && i == 1)
			my_get_next_line(fd);
	}
	if (my_strcmp(tab[0], "DOOR"))
		exec_door(cor, tab);
}

void	exec_mob_5(core_t *cor, V2I pass, char **tab, V2I pos)
{
	if (my_strcmp(tab[0], "JUMP"))
		exec_jump_mob(cor, pass, tab, pos);
	if (my_strcmp(tab[0], "FIGHT") && my_getnbr(tab[1]) == 1)
		exec_fight(cor, tab, pass.y);
	if (my_strcmp(tab[0], "INIT"))
		exec_mob(cor, pass.x, pos, pass.y);
}

void	exec_mob_6(core_t *cor, char *str, char **tab)
{
	if (my_strcmp(tab[0], "RAND_SPEAK"))
		exec_rand_speak(cor, str + 11);
	if (my_strcmp(tab[0], "SPEAK"))
		exec_speak(str + 6, cor);
}

int	exec_mob(core_t *cor, int fd, V2I pos, int mob)
{
	char	*str = my_get_next_line(fd);
	int	chek = 0;
	int	nb = 0;
	char	**tab = my_str_to_word_array(str, ' ');

	nb += exec_mob_2(cor, tab);
	nb += exec_mob_3(cor, tab);
	if (nb != 0)
		return (nb);
	exec_mob_4(cor, fd, tab);
	exec_mob_5(cor, (V2I){fd, mob}, tab, pos);
	exec_mob_6(cor, str, tab);
	if (my_strcmp(tab[0], "MULTI"))
		for (int i = 0; i < my_getnbr(tab[1]) && chek == 0; i++)
			chek = exec_mob(cor, fd, pos, mob);
	else
		return (0);
	return (0);
}
