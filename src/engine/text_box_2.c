/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** text_box
*/

#include "my_rpg.h"

void	add_give_iteam(core_t *cor, int id)
{
	loot_t *node = malloc(sizeof(loot_t));
	loot_t *save = cor->loot;

	node->id = id;
	node->next = NULL;
	if (cor->loot == NULL) {
		cor->loot = node;
		return;
	}
	while (cor->loot->next != NULL)
		cor->loot = cor->loot->next;
	cor->loot->next = node;
	cor->loot = save;
}

void	draw_text_loot(int id, core_t *cor)
{
	SPR_SETSCL(cor->item[id].spt, (V2F){8, 8});
	SPR_SETPOS(cor->item[id].spt, (V2F){680, 482});
	RDW_DRWSPR(cor->window, cor->item[id].spt, NULL);
	TXT_SETSIZ(cor->obj_inv.txt, 40);
	TXT_SETSTR(cor->obj_inv.txt, cor->item[id].name);
	TXT_SETPOS(cor->obj_inv.txt, (V2F){880, 440});
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
	TXT_SETSIZ(cor->obj_inv.txt, 32);
	TXT_SETSTR(cor->obj_inv.txt, cor->item[id].des);
	TXT_SETPOS(cor->obj_inv.txt, (V2F){880, 515});
	RDW_DRWTXT(cor->window, cor->obj_inv.txt, NULL);
}


void	display_scare(core_t *cor)
{
	static sfRectangleShape *bg = NULL;

	bg = (bg == NULL) ? sfRectangleShape_create() : bg;
	sfRectangleShape_setSize(bg, (sfVector2f) {1920, 300});
	sfRectangleShape_setFillColor(bg, (sfColor) {0, 0, 0, 200});
	sfRectangleShape_setPosition(bg, (sfVector2f) {0, 400});
	sfRenderWindow_drawRectangleShape(cor->window, bg, NULL);
}

loot_t	*text_loot_exec(core_t *cor)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) ||
	sfMouse_isButtonPressed(sfMouseLeft)) {
		if (my_cheat(5) == 0) {
			my_cheat(1);
			return (cor->loot->next);
		}
	} else
		my_cheat(0);
	return (cor->loot);
}

loot_t	*text_loot(core_t *cor)
{
	if (cor->loot == NULL || cor->text_box != NULL)
		return (cor->loot);
	display_scare(cor);
	draw_text_loot(cor->loot->id, cor);
	return (text_loot_exec(cor));
}
