/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	*transform_nbr_faces_to_dice(core_t *cor, int id)
{
	int *dice = malloc(sizeof(int) * 6);
	int max_elem = 0;

	for (int i = 0; i < 6; i++)
		dice[i] = -1;
	for (int i = 0, f = 0; i < 6; i++) {
		max_elem = cor->item[cor->armor[id].id].chrc[i];
		for (int e = 0; e < max_elem; e++, f++)
			dice[f] = i;
	}
	return (dice);
}

void	add_elements(core_t *cor, int i, int *dice, int res)
{
	if (cor->obj_btl.dice_cycle[i - 4] == 50) {
		cor->btl.total_elem[dice[res]] += 2;
		sfSound_play(cor->sound[18].obj);
	}
}

void	randomise_dice_launch(core_t *cor)
{
	int res = 0;
	int *dice;

	for (int i = 4; i < 10; i++) {
		res = rand() % 6;
		dice = transform_nbr_faces_to_dice(cor, i);
		if (dice[0] != -1) {
			add_elements(cor, i, dice, res);
			cor->obj_btl.last_dice[i - 4] = dice[res];
		}
	}
}
