/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	spell_frog(core_t *cor)
{
	if (cor->btl.total_elem[2] < 1 || cor->btl.total_elem[1] < 2)
		return;
	cor->btl.total_elem[2] -= 1;
	cor->btl.total_elem[1] -= 2;
	anim_ply_handling(cor, 3, 3, 6);
	txt_state_ply_handling(cor, 1);
	cor->btl.special[0] += 1;
	cor->mob[cor->btl.mob_id].chrc[0] *= 0.9;
	cor->ply.chrc[6] *= 1.1;
}
