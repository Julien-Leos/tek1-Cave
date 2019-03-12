/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

struct  ai_mob_fptr ai_mob_list[11] = {
	{0, &ai_torus},
	{1, &ai_tiki},
	{2, &ai_warlords},
	{3, &ai_yeti},
	{4, &ai_zarboid},
	{5, &ai_centaur},
	{6, &ai_dragon},
	{7, &ai_gnomes},
	{8, &ai_lyon},
	{9, &ai_mermaid},
	{10, &ai_skeleton}
};

struct  spell_mob_fptr spell_mob_list[10] = {
	{9, &mob_spell_basic},
	{10, &mob_spell_cold_glaw},
	{11, &mob_spell_sword_psy},
	{12, &mob_spell_fire},
	{13, &mob_spell_insidious_stroke},
	{14, &mob_spell_kaleidoscope},
	{15, &mob_spell_tornado},
	{16, &mob_spell_heal},
	{17, &mob_spell_bindly},
	{18, &mob_spell_mandale}
};

void	select_mob_spell(core_t *cor, int id)
{
	for (int i = 0; i < 10; i++) {
		if (id == spell_mob_list[i].balise) {
			spell_mob_list[i].function(cor);
			reset_special_sword_psy(cor);
		}
	}
}

int	select_mob_ia(core_t *cor)
{
	for (int i = 0; i < 11; i++)
		if (cor->btl.enn_id == ai_mob_list[i].balise)
			return(ai_mob_list[i].function(cor));
	return (9);
}

void	ai_ennemy(core_t *cor)
{
	static int is_attack = 0;

	if (is_attack == 1) {
		cor->btl.turn_state = -1;
		reset_special_frog(cor);
		sfSound_play(cor->sound[17].obj);
		display_battle_dice_face(cor);
		is_attack = 0;
	} else {
		select_mob_spell(cor, select_mob_ia(cor));
		is_attack++;
	}
}
