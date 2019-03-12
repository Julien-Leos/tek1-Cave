/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** envent_map
*/

#include "my_rpg.h"

void	exec_command_4(core_t *cor, char **tab)
{
	if (my_strcmp(tab[0], "DOOR"))
		exec_door(cor, tab);
	else if (my_strcmp(tab[0], "SAVE"))
		exec_save(cor);
	else
		return;
}

void	exec_command_3(core_t *cor, char **tab, char *str)
{
	if (my_strcmp(tab[0], "SPEAK"))
		exec_speak(str + 6, cor);
	if (my_strcmp(tab[0], "QUETE"))
		exec_add_quete(cor, tab);
	else
		exec_command_4(cor, tab);
}

void	exec_command_2(core_t *cor, char **tab, int fd, char *str)
{
	if (my_strcmp(tab[0], "JUMP"))
		exec_jump(cor, fd, tab);
	else if (my_strcmp(tab[0], "GIVE"))
		exec_give(cor, tab);
	else
		exec_command_3(cor, tab, str);
}

int	exec_command(core_t *cor, int fd)
{
	char	*str = my_get_next_line(fd);
	int	chek = 0;
	char	**tab = my_str_to_word_array(str, ' ');

	if (my_strcmp(tab[0], "MAX"))
		return (exec_max(cor, tab));
	else if (my_strcmp(tab[0], "MULTI"))
		for (int i = 0; i < my_getnbr(tab[1]) && chek == 0; i++)
			chek = exec_command(cor, fd);
	else
		exec_command_2(cor, tab, fd, str);
	return (0);
}

void	event_map(core_t *cor)
{
	V2I	test = get_pos_player(cor);
	static	int key = 0;
	int	fd;

	if (cor->new_game == 1)
		exec_tuto(cor);
	if (sfKeyboard_isKeyPressed(sfKeySpace)) {
		if (cor->map.event[test.y][test.x] == 0 || key == 1)
			return;
		key = 1;
		fd = open(concat("event/",
		concat(my_getchar(cor->map.event[test.y][test.x]),
		".evt")), O_RDONLY);
		exec_command(cor, fd);
		close(fd);
	} else
		key = 0;
}
