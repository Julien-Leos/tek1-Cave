/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** get_event_map
*/

#include "my_rpg.h"

void	get_map_event(int fd, map_t *map)
{
	char	**str = my_str_to_word_array(my_get_next_line(fd), ' ');
	int	line = my_getnbr(str[0]);
	int	col = my_getnbr(str[1]);

	if (my_exit(0) != 0)
		return;
	map->event = malloc(sizeof(int**) * (line + 1));
	for (int i = 0; i < line; i += 1) {
		map->event[i] = malloc(sizeof(int*) * (col + 1));
		str = my_str_to_word_array(my_get_next_line(fd), ',');
		for (int nb = 0; nb < col; nb += 1) {
			map->event[i][nb] = my_getnbr(str[nb]);
		}
	}
}

void	get_map_mob(int fd, map_t *map)
{
	char	**str = my_str_to_word_array(my_get_next_line(fd), ' ');
	int	line = my_getnbr(str[0]);
	int	col = my_getnbr(str[1]);

	if (my_exit(0) != 0)
		return;
	map->mob = malloc(sizeof(int**) * (line + 1));
	for (int i = 0; i < line; i += 1) {
		map->mob[i] = malloc(sizeof(int*) * (col + 1));
		str = my_str_to_word_array(my_get_next_line(fd), ',');
		for (int nb = 0; nb < col; nb += 1) {
			map->mob[i][nb] = my_getnbr(str[nb]);
		}
	}
}