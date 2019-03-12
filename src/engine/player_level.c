/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** manage player experience
*/

#include "my_rpg.h"

int	*generate_exp_table(void)
{
	int 	*exp_table = malloc(sizeof(int) * 100);
	int 	initial = 500;

	for (int i = 0; i < 100; i++) {
		exp_table[i] = initial + (initial / 100) * 20;
		initial += (initial / 100) * 20;
	}
	return (exp_table);
}

void	level_up(core_t *cor, int value)
{
	static int 	*exp_table = NULL;

	exp_table = (exp_table == NULL) ? generate_exp_table() : exp_table;
	if (cor->ply.level == 80)
		return;
	cor->ply.exp += value;
	if (exp_table[cor->ply.level - 1] < cor->ply.exp) {
		cor->ply.exp -= exp_table[cor->ply.level - 1];
		cor->ply.life += cor->ply.life / 8;
		cor->ply.level += 1;
		sfSound_play(cor->sound[10].obj);
	}
}