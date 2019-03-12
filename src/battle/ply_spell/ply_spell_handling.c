/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

struct  spell_fptr spell_list[8] = {
	{0, &spell_meteor},
	{1, &spell_bramble},
	{2, &spell_wind},
	{3, &spell_light},
	{4, &spell_frog},
	{5, &spell_heal},
	{6, &spell_steal},
	{7, &spell_special}
};

void	select_spell(core_t *cor)
{
	V2F actual_pos = SPR_GETPOS(cor->obj[17]->spr);
	int actual_spell = (actual_pos.x - 800) / 256;

	if (cor->ply.spell[actual_spell] != -1)
		spell_list[cor->ply.spell[actual_spell]].function(cor);
}

int	critical_ply_handling(core_t *cor, float critical, int coeff)
{
	if (get_critical(critical) == 1) {
		cor->btl.dmg[0] *= coeff;
		cor->obj_btl.color_txt[1] = CLR_FRRGBA(255, 215, 0, 255);
		return (1);
	}
	return (0);
}

int	miss_ply_handling(core_t *cor, float esquive)
{
	if (get_miss(esquive) == 1) {
		cor->btl.dmg[0] = 0;
		cor->obj_btl.dmg_txt[1] = "MISS";
		return (1);
	}
	return (0);
}

int	defense_ply_handling(core_t *cor, float armor, float defense)
{
	if ((cor->btl.dmg[0] -= get_defense(armor, defense)) < 0) {
		cor->btl.dmg[0] = 0;
		return (1);
	}
	return (0);
}

void	txt_state_ply_handling(core_t *cor, int txt_state)
{
	if (txt_state == 0)
		cor->obj_btl.color_txt[0] = CLR_FRRGBA(0, 180, 0, 255);
	else if (txt_state == 1)
		cor->obj_btl.color_txt[1] = CLR_FRRGBA(180, 0, 0, 255);
	else {
		cor->obj_btl.color_txt[0] = CLR_FRRGBA(0, 180, 0, 255);
		cor->obj_btl.color_txt[1] = CLR_FRRGBA(180, 0, 0, 255);
	}
}
