/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

struct  conso_fptr conso_list[4] = {
	{0, &life_potion},
	{1, &big_life_potion},
	{2, &cheese},
	{3, &apple}
};

void	select_conso(core_t *cor)
{
	V2F actual_pos = SPR_GETPOS(cor->obj[17]->spr);
	int actual_conso = (actual_pos.x - 1056) / 128;

	for (int i = 0; i < 4; i++)
		if (actual_conso == conso_list[i].balise)
			conso_list[i].function(cor);
}

void	apple(core_t *cor)
{
	if (recup_nbr_item(cor, 61) == 0)
		return;
	sfSound_play(cor->sound[16].obj);
	cor->btl.life[0] += cor->ply.life * 0.1;
	delete_item(cor, 61);
	return;
}

void	cheese(core_t *cor)
{
	if (recup_nbr_item(cor, 60) == 0)
		return;
	sfSound_play(cor->sound[16].obj);
	cor->btl.life[0] += cor->ply.life * 0.05;
	delete_item(cor, 60);
	return;
}

void	life_potion(core_t *cor)
{
	if (recup_nbr_item(cor, 1) == 0)
		return;
	sfSound_play(cor->sound[16].obj);
	cor->btl.life[0] += cor->ply.life * 0.2;
	delete_item(cor, 1);
	return;
}

void	big_life_potion(core_t *cor)
{
	if (recup_nbr_item(cor, 2) == 0)
		return;
	sfSound_play(cor->sound[16].obj);
	cor->btl.life[0] += cor->ply.life * 0.4;
	delete_item(cor, 2);
	return;
}
