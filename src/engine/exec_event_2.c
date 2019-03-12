/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib_fonc
*/

#include "my_rpg.h"

void	exec_door(core_t *cor, char **tab)
{
	if (get_size_tab(tab) != 6 || my_exit(0) != 0) {
		my_exit(84);
		return;
	}
	if (cor->quest[my_getnbr(tab[4])] < my_getnbr(tab[5]))
		return;
	get_map(cor, tab[1]);
	cor->ply.pos.x = my_getnbr(tab[2]);
	cor->ply.pos.y = my_getnbr(tab[3]);
	SPR_SETPOS(cor->ply.spt, cor->ply.pos);
	sfSound_play(cor->sound[14].obj);
}

void	exec_give(core_t *cor, char **tab)
{
	char	**item = NULL;
	int	size = 0;
	int	choise = 0;

	if (!tab[1] || !tab[2] || my_exit(0) != 0) {
		my_exit(84);
		return;
	}
	item = my_str_to_word_array(tab[1], ',');
	size = get_size_tab(item);
	choise = rand() % size;
	add_item(cor, my_getnbr(item[choise]));
	add_give_iteam(cor, my_getnbr(item[choise]));
	level_up(cor, my_getnbr(tab[2]));
}

int	exec_max(core_t *cor, char **tab)
{
	if (get_size_tab(tab) != 3) {
		my_exit(84);
		return (84);
	}
	if (cor->quest[my_getnbr(tab[1])] > my_getnbr(tab[2]))
		return (84);
	return (0);
}

int	exec_min(core_t *cor, char **tab)
{
	if (get_size_tab(tab) != 3 || my_exit(0) != 0) {
		my_exit(84);
		return (84);
	}
	if (cor->quest[my_getnbr(tab[1])] < my_getnbr(tab[2]))
		return (84);
	return (0);
}

void	exec_speak(char *str, core_t *cor)
{
	char **tab = my_str_to_word_array(str, '/');

	sfSound_play(cor->sound[23].obj);
	for (int i = 0; tab[i] != NULL; i += 1) {
		adding_text(line_return(tab[i]), cor);
		free (tab[i]);
	}
}
