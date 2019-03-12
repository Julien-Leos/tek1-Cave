/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** colider_tilset
*/

#include "my_rpg.h"

obj_t **get_colider_line(char **tab, obj_t **obj)
{
	static int i = 0;

	for (int nb = 0; nb < 15; nb += 1) {
		obj[i]->hit_box = my_getnbr(tab[nb]);
		i += 1;
	}
	return (obj);
}

obj_t **set_colider_tiles_set(char *path, obj_t **obj)
{
	char **tab;
	int fd = open(path, O_RDONLY);
	char *str;

	if (fd == -1) {
		my_exit(84);
	}
	for (int i = 0; i != 20; i += 1) {
		str = my_get_next_line(fd);
		tab = my_str_to_word_array(str, ',');
		obj = get_colider_line(tab, obj);
	}
	return (obj);
}
