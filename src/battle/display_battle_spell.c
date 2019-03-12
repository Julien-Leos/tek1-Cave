/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

void	display_battle_spell_spr(core_t *cor)
{
	IRC int_rect = {0, 0, 256, 256};
	V2F pos = {0, 790};

	for (int i = 0; i < 4; i++) {
		if (cor->ply.spell[i] == -1)
			continue;
		int_rect.left = cor->ply.spell[i] * 256;
		pos.x = 800 + i * 256;
		SPR_STXTRE(cor->obj[31]->spr, int_rect);
		SPR_SETPOS(cor->obj[31]->spr, pos);
		RDW_DRWSPR(cor->window, cor->obj[31]->spr, NULL);
	}
}

void	set_battle_spell_select(core_t *cor, V2F pos_case)
{
	if (sfMouse_isButtonPressed(sfMouseLeft)) {
		SPR_SETPOS(cor->obj[17]->spr, pos_case);
		if (is_all_anim_ended(cor) == 1)
			select_spell(cor);
	}
}

void	display_battle_spell_select(core_t *cor, V2I pos_mouse, V2F pos_case)
{
	if (2 < pos_mouse.x && pos_mouse.x < 7 &&
	2 < pos_mouse.y && pos_mouse.y < 4) {
		set_battle_spell_select(cor, pos_case);
		RCT_SETSIZ(cor->obj_btl.actual, (V2F){256, 256});
		RCT_SETPOS(cor->obj_btl.actual, pos_case);
		RDW_DRWRCT(cor->window, cor->obj_btl.actual, NULL);
	}
	SPR_SETSCL(cor->obj[17]->spr, (V2F){1, 1});
	RDW_DRWSPR(cor->window, cor->obj[17]->spr, NULL);
}

void	display_battle_spell(core_t *cor)
{
	int pos_mouse_x = (cor->pos_mouse.x - 32) / 256;
	int pos_mouse_y = (cor->pos_mouse.y - 22) / 256;
	V2I pos_mouse = {pos_mouse_x, pos_mouse_y};
	V2F pos_case = {pos_mouse.x * 256 + 32, pos_mouse.y * 256 + 22};

	if (cor->obj_btl.which_menu == 1)
		SPR_SETPOS(cor->obj[17]->spr, (V2F){800, 790});
	cor->obj_btl.which_menu = 0;
	display_battle_spell_spr(cor);
	display_battle_spell_select(cor, pos_mouse, pos_case);
}
