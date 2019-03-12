/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib_fonc
*/

#include "my_rpg.h"

void	exec_jump(core_t *cor, int fd, char **tab)
{
	char *str = NULL;

	if (get_size_tab(tab) != 4) {
		my_exit(84);
	}
	if (cor->quest[my_getnbr(tab[1])] == my_getnbr(tab[2])) {
		for (int i = 0; i < my_getnbr(tab[3]); i++) {
			str = my_get_next_line(fd);
			free (str);
			str = NULL;
		}
	}
	exec_command(cor, fd);
}

int	exec_png(void)
{
	if (!sfKeyboard_isKeyPressed(sfKeySpace))
		return (84);
	return (0);
}

void	exec_jump_mob(core_t *cor, V2I param, char **tab, V2I pos)
{
	if (get_size_tab(tab) != 4) {
		my_exit(84);
		return;
	}
	if (cor->quest[my_getnbr(tab[1])] == my_getnbr(tab[2])) {
		for (int i = 0; i < my_getnbr(tab[3]); i++)
			my_get_next_line(param.x);
	exec_mob(cor, param.x, pos, param.y);
	}
}

void	exec_add_quete(core_t *cor, char **tab)
{
	if (get_size_tab(tab) != 3) {
		my_exit(84);
		return;
	}
	sfSound_play(cor->sound[13].obj);
	cor->quest[my_getnbr(tab[1])] += my_getnbr(tab[2]);
}

void	exec_tuto(core_t *cor)
{
	cor->new_game = 0;
	adding_text("Utilise la touche ENTER pour passer les dialogues.", cor);
	adding_text("Tu peux aussi utiliser le clic-gauche.", cor);
	adding_text("Bienvenue dans CAVE!", cor);
	adding_text("Je serais ton guide pour tes premiers pas dans le jeu.",
	cor);
	adding_text("Utilise les touches Z,S,Q,D pour te deplacer.", cor);
	adding_text("Utilise la touche SPACE pour interagir avec les objets.",
	cor);
	adding_text("En general, ils scintillent.", cor);
	adding_text("Tu peux aussi utiliser cette touche pour changer de map.",
	cor);
}