/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** move mob into diff directions
*/

#include "my_rpg.h"

void 	move_mob_right(core_t *cor, obj_t **obj, int i, float s_perso)
{
	int pos_x = cor->mob[i].pos.x + 4;
	int pos_y = cor->mob[i].pos.y;

	if (is_collide(cor, obj, (V2F){pos_x + 24, pos_y}) == 1 ||
	is_collide(cor, obj, (V2F){pos_x + 24, pos_y + 12}) == 1) {
		cor->mob[i].rect.left = 48;
		cor->mob[i].dir = (V2F){0, 0};
		sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
		return;
	}
	cor->mob[i].pos.x += 4;
	sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
	cor->mob[i].rect.top = 96;
	if (s_perso > 0.1) {
		cor->mob[i].rect.left += 48;
		if (cor->mob[i].rect.left >= (48 * 3))
			cor->mob[i].rect.left = 0;
	}
}

void 	move_mob_left(core_t *cor, obj_t **obj, int i, float s_perso)
{
	int pos_x = cor->mob[i].pos.x - 4;
	int pos_y = cor->mob[i].pos.y;

	if (is_collide(cor, obj, (V2F){pos_x, pos_y}) == 1 ||
	is_collide(cor, obj, (V2F){pos_x, pos_y + 12}) == 1) {
		cor->mob[i].rect.left = 48;
		cor->mob[i].dir = (V2F){0, 0};
		sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
		return;
	}
	cor->mob[i].pos.x -= 4;
	sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
	cor->mob[i].rect.top = 48;
	if (s_perso > 0.1) {
		cor->mob[i].rect.left += 48;
		if (cor->mob[i].rect.left >= (48 * 3))
			cor->mob[i].rect.left = 0;
	}
}

void 	move_mob_up(core_t *cor, obj_t **obj, int i, float s_perso)
{
	int pos_x = cor->mob[i].pos.x;
	int pos_y = cor->mob[i].pos.y - 4;

	if (is_collide(cor, obj, (V2F){pos_x, pos_y}) == 1 ||
	is_collide(cor, obj, (V2F){pos_x + 24, pos_y}) == 1) {
		cor->mob[i].rect.left = 48;
		cor->mob[i].dir = (V2F){0, 0};
		sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
		return;
	}
	cor->mob[i].pos.y -= 4;
	sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
	cor->mob[i].rect.top = 48 * 3;
	if (s_perso > 0.1) {
		cor->mob[i].rect.left += 48;
		if (cor->mob[i].rect.left >= (48 * 3))
			cor->mob[i].rect.left = 0;
	}
}

void 	move_mob_down(core_t *cor, obj_t **obj, int i, float s_perso)
{
	int pos_x = cor->mob[i].pos.x;
	int pos_y = cor->mob[i].pos.y + 4;

	if (is_collide(cor, obj, (V2F){pos_x, pos_y + 12}) == 1 ||
	is_collide(cor, obj, (V2F){pos_x + 24, pos_y + 12}) == 1) {
		cor->mob[i].rect.left = 48;
		cor->mob[i].dir = (V2F){0, 0};
		sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
		return;
	}
	cor->mob[i].pos.y += 4;
	sfSprite_setTextureRect(cor->mob[i].spr, cor->mob[i].rect);
	cor->mob[i].rect.top = 0;
	if (s_perso > 0.1) {
		cor->mob[i].rect.left += 48;
		if (cor->mob[i].rect.left >= (48 * 3))
			cor->mob[i].rect.left = 0;
	}
}