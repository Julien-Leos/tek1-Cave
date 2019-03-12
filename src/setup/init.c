/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	*init_int_tab(int len)
{
	int *inv = malloc(sizeof(int) * len);

	for (int i = 0; i < len; i++)
		inv[i] = 0;
	return (inv);
}

sfVector2f	*init_armor_pos(core_t cor)
{
	sfVector2f *armor_pos = malloc(sizeof(sfVector2f) * NB_ARMOR_CASE);

	(void)cor;
	armor_pos[0] = (V2F){298, 110};
	armor_pos[1] = (V2F){298, 279};
	armor_pos[2] = (V2F){469, 279};
	armor_pos[3] = (V2F){298, 448};
	armor_pos[4] = (V2F){41, 620};
	armor_pos[5] = (V2F){210, 620};
	armor_pos[6] = (V2F){379, 620};
	armor_pos[7] = (V2F){548, 620};
	armor_pos[8] = (V2F){210, 771};
	armor_pos[9] = (V2F){379, 771};
	return (armor_pos);
}

obj_spell_t	init_obj_spell(core_t cor)
{
	obj_spell_t obj_spell;
	sfFont *font = FNT_CRTFRF("img/font.ttf");

	(void)cor;
	obj_spell.txt = TXT_CREATE();
	TXT_SETFNT(obj_spell.txt, font);
	TXT_SETPOS(obj_spell.txt, (V2F){1300, 256});
	TXT_SETSIZ(obj_spell.txt, 38);
	obj_spell.actual = RCT_CREATE();
	RCT_SETSIZ(obj_spell.actual, (V2F){256, 256});
	RCT_SETCLR(obj_spell.actual, sfColor_fromRGBA(200, 200, 200, 75));
	obj_spell.nbr_spell = 4;
	return (obj_spell);
}

void	init_characteristics_name(core_t *cor)
{
	cor->chrc_name[0] = my_strdup("Eau: ");
	cor->chrc_name[1] = my_strdup("Terre: ");
	cor->chrc_name[2] = my_strdup("Feu: ");
	cor->chrc_name[3] = my_strdup("Air: ");
	cor->chrc_name[4] = my_strdup("Lumiere: ");
	cor->chrc_name[5] = my_strdup("Tenebre: ");
	cor->chrc_name[6] = my_strdup("ARM: ");
	cor->chrc_name[7] = my_strdup("END: ");
	cor->chrc_name[8] = my_strdup("FOR: ");
	cor->chrc_name[9] = my_strdup("INT: ");
	cor->chrc_name[10] = my_strdup("AGI: ");
	cor->chrc_name[11] = my_strdup("CHA: ");
	cor->chrc_name[12] = my_strdup("REG: ");
}

armor_t	*init_armor(core_t cor)
{
	armor_t	*armor = malloc(sizeof(armor_t) * NB_ARMOR_CASE);
	sfVector2f *armor_pos = init_armor_pos(cor);

	for (int i = 0; i < NB_ARMOR_CASE; i++) {
		armor[i].id = 0;
		armor[i].armor_pos = armor_pos[i];
	}
	armor[0].type = HELMET;
	armor[1].type = CHESTPLATE;
	armor[2].type = GLOVES;
	armor[3].type = BOOTS;
	armor[4].type = DICE;
	armor[5].type = DICE;
	armor[6].type = DICE;
	armor[7].type = DICE;
	armor[8].type = DICE;
	armor[9].type = DICE;
	return (armor);
}
