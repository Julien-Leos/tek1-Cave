/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** get_map
*/

#include "my_rpg.h"

void	get_charc(core_t *cor, int i, char **tab)
{
	cor->mob[i].chrc[0] = my_getnbr(tab[0]);
	cor->mob[i].chrc[1] = my_getnbr(tab[1]);
	cor->mob[i].chrc[2] = my_getnbr(tab[2]);
	cor->mob[i].chrc[3] = my_getnbr(tab[3]);
	cor->mob[i].chrc[4] = my_getnbr(tab[4]);
	cor->mob[i].chrc[5] = my_getnbr(tab[5]);
	cor->mob[i].dir.x = 0;
	cor->mob[i].dir.y = 0;
}

void	get_sprite_mob(core_t *cor, V2I pos, int i, char **tab)
{
	V2F temp = center_map(cor->map);

	cor->mob[i].rect = (INTRCT){0, 0, 48, 48};
	cor->mob[i].spr = sfSprite_copy(cor->obj[my_getnbr(tab[7])]->spr);
	sfSprite_setOrigin(cor->mob[i].spr, (V2F){12, 35});
	cor->mob[i].pos.x = pos.x * 32 + temp.x;
	cor->mob[i].pos.y = pos.y * 32 + temp.y;
	cor->mob[i].dead = 0;
}

int	creat_mod(core_t *cor, V2I pos, int i)
{
	int mob = 0;
	char **tab = NULL;
	int fd = 0;

	if (cor->map.mob[pos.y][pos.x] != 0) {
		fd = open(concat(concat("mob/",
		my_getchar(cor->map.mob[pos.y][pos.x])), ".mob"), O_RDONLY);
		tab = my_str_to_word_array(my_get_next_line(fd), ' ');
		get_sprite_mob(cor, pos, i, tab);
		cor->mob[i].life = my_getnbr(tab[1]);
		cor->mob[i].ia = my_getnbr(tab[2]);
		cor->mob[i].power = my_getnbr(tab[4]);
		cor->mob[i].is_static = my_getnbr(tab[5]);
		cor->mob[i].enn_id = my_getnbr(tab[6]);
		cor->mob[i].event = cor->map.mob[pos.y][pos.x];
		tab = my_str_to_word_array(tab[3], ',');
		get_charc(cor, i, tab);
		mob = 1;
	}
	return (mob);
}

void	get_mod_struc(core_t *cor)
{
	int	mob_nb = 0;

	for (int i = 0; i < cor->map.line; i++) {
		for (int nb = 0; nb < cor->map.col; nb++)
			mob_nb += creat_mod(cor, (V2I){nb, i}, mob_nb);
	}
	cor->state.nb_ennemy = mob_nb;
}

void	get_map(core_t *cor, char *path)
{
	int fd = open(path, O_RDONLY);
	int fdevent = open(concat(path, ".event"), O_RDONLY);
	int fdmob = open(concat(path, ".mob"), O_RDONLY);

	if (my_exit(0) != 0)
		return;
	if (fd == -1 || fdevent == -1 || fdmob == -1) {
		my_exit(84);
		return;
	}
	get_map_tab_int(fd, &cor->map);
	cor->map.map_name = my_strdup(path);
	get_map_event(fdevent, &cor->map);
	get_map_mob(fdmob, &cor->map);
	get_mod_struc(cor);
}
