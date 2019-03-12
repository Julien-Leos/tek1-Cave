/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** get_map
*/

#include "my_rpg.h"

int	is_mod(core_t *cor)
{
	for (int i = 0; i < cor->state.nb_ennemy; i++)
		if (sqrt(pow(cor->mob[i].pos.x - cor->ply.pos.x, 2)
		+ pow(cor->ply.pos.y - cor->mob[i].pos.y, 2)) <= 64)
			return (i);
	return (-1);
}

void	event_mob(core_t *cor)
{
	V2I	test = get_pos_player(cor);
	static	int key = 0;
	int	mob = is_mod(cor);
	int	fd;

	if (key == 0 && mob != -1 && cor->mob[mob].dead == 0) {
		key = 1;
		fd = open(concat("mob/",
		concat(my_getchar(cor->mob[mob].event), ".mob")), O_RDONLY);
		if (fd == -1) {
			my_exit(84);
			close(fd);
			return;
		}
		my_get_next_line(fd);
		exec_mob(cor, fd, test, mob);
		close(fd);
	} else
		key = 0;
}

int	exec_mob_2(core_t *cor, char **tab)
{
	if (my_strcmp(tab[0], "QUETE"))
		exec_add_quete(cor, tab);
	if (my_strcmp(tab[0], "GIVE"))
		exec_give(cor, tab);
	if (my_strcmp(tab[0], "PNJ") && my_getnbr(tab[1]) == 1)
		return (exec_png());
	return (0);
}
