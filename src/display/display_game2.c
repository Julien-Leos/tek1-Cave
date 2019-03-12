/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 2 of display game
*/

#include "my_rpg.h"

void browse_column_2(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2])
{
	for (tab[2] = 0; tab[2] < cor->map.col; tab[2]++) {
		verif_is_printable_2(cor, obj, tab, tab_pos);
		tab_pos[1].x += 32;
	}

}

void	browse_line_2(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2])
{
	for (tab[1] = 0; tab[1] < cor->map.line; tab[1]++) {
		browse_column_2(cor, obj, tab, tab_pos);
		tab_pos[1].x = tab_pos[0].x;
		tab_pos[1].y += 32;
	}
}

void	browse_layer_2(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2])
{
	for (tab[0] = 0; tab[0] < cor->map.layer; tab[0]++) {
		browse_line_2(cor, obj, tab, tab_pos);
		tab_pos[1].x = tab_pos[0].x;
		tab_pos[1].y = tab_pos[0].y;
	}
}

void 	display_mob_entities(core_t *cor, int i , int j)
{
	if (j == cor->mob[i].pos.y && cor->mob[i].dead == 0)
		RDW_DRWSPR(cor->window, cor->mob[i].spr, NULL);
}

void 	display_entities(core_t *cor)
{
	particle_move(cor);
	particle_event(cor);
	for (int j = 0; j < 1080; j++) {
		particle_draw_move(cor, j);
		particle_draw_event(cor, j);
		for (int i = 0; i < cor->state.nb_ennemy; i++) {
			display_mob_entities(cor, i, j);
		}
		if (j == cor->ply.pos.y)
			RDW_DRWSPR(cor->window, cor->ply.spt, NULL);
	}
}