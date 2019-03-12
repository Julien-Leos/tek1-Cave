/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** lib_fonc
*/

#include "my_rpg.h"

void	exec_rand_speak(core_t *cor, char *str)
{
	int random = 0;
	char **tab = my_str_to_word_array(str, '*');

	random = rand() % get_size_tab(tab);
	if (!tab[random]) {
		my_exit(84);
		return;
	}
	exec_speak(tab[random], cor);
	for (int i = 0; tab[i] != NULL; i++)
		free(tab[i]);
}

void	exec_fight(core_t *cor, char **tab, int mob)
{
	if (get_size_tab(tab) != 2) {
		my_exit(84);
		return;
	}
	if (my_getnbr(tab[1]) == 1) {
		start_fight(1, mob, cor);
		adding_text("*!FIGHT!*", cor);
	}
}

int	delete_mob_item(core_t *cor, int item)
{
	for (int i = 0; i < 112; i += 1)
		if (cor->inv[i] == item) {
			cor->inv[i] = 0;
			return (1);
		}
	return (0);
}

void	start_fight(int i, int give_mob, core_t *cor)
{
	static int fight = 0;
	static int mob = 0;

	if (fight == 1 && my_strcmp(cor->text_box->str, "*!FIGHT!*")) {
		if (cor->mob[mob].enn_id < 0 && cor->mob[mob].enn_id > 10) {
			my_exit(84);
			return;
		}
		sfSound_play(cor->sound[22].obj);
		sfSound_stop(cor->sound[3].obj);
		init_new_battle(cor, mob);
		cor->btl.enn_id = cor->mob[mob].enn_id;
		cor->text_box = cor->text_box->next;
		cor->state.in_menu = 8;
		cor->actual_scene = 3;
		fight = 0;
	}
	fight = (i != -1 && give_mob != -1) ? i : fight;
	mob = (i != -1 && give_mob != -1) ? give_mob : mob;
}

void 	exec_tuto_continue(core_t *cor)
{
	adding_text("Tu peux sauvegarder grace a la statue grise.", cor);
	adding_text("Certaines touches ouvre des menus.", cor);
	adding_text("La touche ESC ouvre le menu pause.", cor);
	adding_text("La touche K ouvre le menu des quetes.", cor);
	adding_text("La touche O ouvre le menu des sorts.", cor);
	adding_text("Au cas ou tu preferes la souris :", cor);
	adding_text("Tu peux te deplacer en maintenant le clic.", cor);
	adding_text("Les menus sont accessibles avec la souris aussi.", cor);
	adding_text("Va vite prendre a manger tu dois avoir faim!", cor);
}