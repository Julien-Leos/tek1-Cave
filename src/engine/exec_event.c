/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib_fonc
*/

#include "my_rpg.h"

void	write_nb_quest(core_t *cor, int fd)
{
	char	c = ' ';

	for (int i = 0; i < NB_QUEST; i += 1) {
		write(fd, my_getchar(cor->quest[i]),
		my_strlen(my_getchar(cor->quest[i])));
		write(fd, &c, 1);
	}
	for (int i = 0; i < 112; i++) {
		write(fd, my_getchar(cor->inv[i]),
		my_strlen(my_getchar(cor->inv[i])));
		write(fd, &c, 1);
	}
}

void	write_nb_quest_2(core_t *cor, int fd)
{
	char	c = ' ';

	for (int i = 0; i < 10; i++) {
		write(fd, my_getchar(cor->armor[i].id),
		my_strlen(my_getchar(cor->armor[i].id)));
		write(fd, &c, 1);
	}
	for (int i = 0; i < 4; i++) {
		write(fd, my_getchar(cor->ply.spell[i]),
		my_strlen(my_getchar(cor->ply.spell[i])));
		write(fd, &c, 1);
	}
}

void	write_first_param(core_t *cor, int fd)
{
	char	c = ' ';

	write(fd, cor->map.map_name, my_strlen(cor->map.map_name));
	write(fd, &c, 1);
	write(fd, my_getchar(cor->ply.pos.x),
	my_strlen(my_getchar(cor->ply.pos.x)));
	write(fd, &c, 1);
	write(fd, my_getchar(cor->ply.pos.y),
	my_strlen(my_getchar(cor->ply.pos.y)));
	write(fd, &c, 1);
}

void	write_end(core_t *cor, int fd)
{
	char	c = ' ';

	write(fd, my_getchar(cor->ply.level),
	my_strlen(my_getchar(cor->ply.level)));
	write(fd, &c, 1);
	write(fd, my_getchar(cor->ply.exp),
	my_strlen(my_getchar(cor->ply.exp)));
	write(fd, &c, 1);
	write(fd, my_getchar(cor->ply.life),
	my_strlen(my_getchar(cor->ply.life)));
	write(fd, &c, 1);
	c = '\n';
	write(fd, &c, 1);
	c = '\0';
	for (int i = 0; i < 100; i++)
		write(fd, &c, 1);
	close(fd);
	sfSound_play(cor->sound[12].obj);
	adding_text("Tout est save !", cor);
}

void	exec_save(core_t *cor)
{
	int	fd = open(concat("save/",
	concat(my_getchar(cor->save_actual), "_save.save")), O_WRONLY);

	if (my_exit(0) != 0)
		return;
	if (fd == -1) {
		my_exit(3);
		return;
	}
	write_first_param(cor, fd);
	write_nb_quest(cor, fd);
	write_nb_quest_2(cor, fd);
	write_end(cor, fd);
}
