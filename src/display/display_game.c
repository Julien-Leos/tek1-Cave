/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	browse_column(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2])
{
	for (tab[2] = 0; tab[2] < cor->map.col; tab[2]++) {
		verif_is_printable(cor, obj, tab, tab_pos);
		tab_pos[1].x += 32;
	}

}

void	browse_line(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2])
{
	for (tab[1] = 0; tab[1] < cor->map.line; tab[1]++) {
		browse_column(cor, obj, tab, tab_pos);
		tab_pos[1].x = tab_pos[0].x;
		tab_pos[1].y += 32;
	}
}

void	browse_layer(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2])
{
	for (tab[0] = 0; tab[0] < cor->map.layer; tab[0]++) {
		browse_line(cor, obj, tab, tab_pos);
		tab_pos[1].x = tab_pos[0].x;
		tab_pos[1].y = tab_pos[0].y;
	}
}

void	display_map(core_t *cor, obj_t **obj)
{
	int tab[3];
	V2F tab_pos[2];
	tab_pos[0] = center_map(cor->map);
	tab_pos[1] = (V2F){tab_pos[0].x, tab_pos[0].y};

	browse_layer(cor, obj, tab, tab_pos);
	move_mob(cor, obj);
	display_entities(cor);
	browse_layer_2(cor, obj, tab, tab_pos);
}

void	display_game(core_t *cor, obj_t **obj)
{
	display_map(cor, obj);
	if (cor->state.in_menu == 4)
		display_inventory(cor);
	if (cor->state.in_menu == 5)
		display_pause(cor);
	if (cor->state.in_menu == 6)
		display_spell_menu(cor);
	if (cor->state.in_menu == 7)
		display_quest_menu(cor);
}
