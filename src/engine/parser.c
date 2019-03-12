/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** parser
*/

#include "my_rpg.h"

int	create_sprite(sfSprite	*obj, sfTexture	*img, sfIntRect rect)
{
	sfSprite_setTexture(obj, img, sfTrue);
	sfSprite_setTextureRect(obj, rect);
	sfSprite_setPosition(obj, (V2F){0, 0});
	return (0);
}

obj_t	**parse_map_tileset(char *path, int nb_case_line, int nb_line)
{
	obj_t	**parse_jlm = malloc(sizeof(obj_t*) *
	(nb_case_line * nb_line));
	sfTexture	*img = sfTexture_createFromFile(path, NULL);
	int	block = 0;
	int	line = 0;
	int	i = 0;

	for (i = 0; i < (nb_case_line * nb_line); i += 1) {
		parse_jlm[i] = malloc(sizeof(obj_t));
		parse_jlm[i]->obj = sfSprite_create();
		create_sprite(parse_jlm[i]->obj, img,
		(sfIntRect){block, line, 32, 32});
		block += 32;
		if (block >= (nb_case_line * 32)) {
			block = 0;
			line += 32;
		}
	}
	parse_jlm = set_colider_tiles_set("config/collide_tileset", parse_jlm);
	return (parse_jlm);
}

int	get_size_tab(char **tab)
{
	int	nb = 0;

	for (; tab[nb] != NULL; nb += 1);
	return (nb);
}

int	**get_layer_map(int **tab, sfVector2i param, int fd)
{
	char **str;
	char *plop;
	int nb = 0;
	int i = 0;

	for (i = 0; i < param.y; i += 1) {
		plop = my_get_next_line(fd);
		str = my_str_to_word_array(plop, ',');
		if (get_size_tab(str) != param.x || str[0][0] == '/')
			my_exit(4);
		for (nb = 0; str[nb] != NULL; nb += 1) {
			tab[i][nb] = my_getnbr(str[nb]);
		}
		tab[i][nb] = -1;
	}
	tab[i - 1][nb] = -42;
	plop = my_get_next_line(fd);
	if (plop && plop[0] != '/')
		my_exit(3);
	return (tab);
}

void	get_map_tab_int(int fd, map_t *map)
{
	char	**str = my_str_to_word_array(my_get_next_line(fd), ' ');
	int	line = my_getnbr(str[0]);
	int	col = my_getnbr(str[1]);
	int	layer = my_getnbr(str[2]);

	map->info = malloc(sizeof(int**) * (layer + 1));
	map->line = line;
	map->col = col;
	map->layer = layer;
	map->id = my_getnbr(str[3]);
	for (int i = 0; i < layer; i += 1) {
		map->info[i] = malloc(sizeof(int*) * (line + 1));
		for (int act_line = 0; act_line < line; act_line += 1)
			map->info[i][act_line] = malloc(sizeof(int) *
			(col + 1));
	}
	for (int i = 0; i < layer; i += 1)
		map->info[i] = get_layer_map(map->info[i],
		(sfVector2i){col, line}, fd);
}
