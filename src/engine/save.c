/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** save_fonction
*/

#include "my_rpg.h"

void	no_save(core_t *cor)
{
	get_map(cor, "config/home-room.map");
	cor->ply.pos = (V2F){944, 503};
}

void	load_save(core_t *cor, char *path)
{
	int fd = open(path, O_RDONLY);
	char **tab = my_str_to_word_array(my_get_next_line(fd), ' ');

	for (int i = 0; i < NB_QUEST; i += 1)
		cor->quest[i] = 0;
	if (my_strcmp(tab[0], "NULL")) {
		no_save(cor);
		cor->new_game = 1;
		return;
	}
	get_map(cor, tab[0]);
	if (my_exit(0) != 0)
		return;
	load_inv(cor, tab);
	if (my_exit(0) != 0)
		return;
	actualise_player_stat(cor);
	close(fd);
}

int	save_exist(char *path)
{
	int fd = open(path, O_RDONLY);
	char	*str = my_get_next_line(fd);
	char **tab = my_str_to_word_array(str, ' ');

	if (my_strcmp(tab[0], "NULL"))
		return (1);
	close(fd);
	return (0);
}

int	is_save_use(char *path)
{
	int fd = open(path, O_RDONLY);
	char *line;

	my_get_next_line(-42);
	line = my_get_next_line(fd);
	close(fd);
	if (line == NULL)
		return (0);
	return (1);
}
