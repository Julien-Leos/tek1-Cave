/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** save_fonction
*/

#include "my_rpg.h"

void	check(core_t *cor)
{
	for (int i = 0; i < 112; i++)
		if (!(cor->inv[i] >= 0 && cor->inv[i] <= 101)) {
			my_exit(1);
			return;
		}
	for (int i = 0; i < 10; i++)
		if (!(cor->armor[i].id >= 0 && cor->armor[i].id <= 101)) {
			my_exit(2);
			return;
		}
}

void	load_inv(core_t *cor, char **tab)
{
	cor->new_game = 0;
	cor->ply.pos.x = my_getnbr(tab[1]);
	cor->ply.pos.y = my_getnbr(tab[2]);
	cor->loot = NULL;
	cor->text_box = NULL;
	for (int i = 0; i < NB_QUEST; i += 1)
		cor->quest[i] = my_getnbr(tab[i + 3]);
	for (int i = 0; i < 112; i++)
		cor->inv[i] = my_getnbr(tab[i + 3 + NB_QUEST]);
	for (int i = 0; i < 10; i++)
		cor->armor[i].id = my_getnbr(tab[i + 3 + NB_QUEST + 112]);
	for (int i = 0; i < 4; i++)
		cor->ply.spell[i] = my_getnbr(tab[i + 3 + NB_QUEST + 122]);
	cor->ply.level = my_getnbr(tab[3 + NB_QUEST + 122 + 4]);
	cor->ply.exp = my_getnbr(tab[3 + NB_QUEST + 122 + 5]);
	cor->ply.life = my_getnbr(tab[3 + NB_QUEST + 122 + 6]);
	check(cor);
}
