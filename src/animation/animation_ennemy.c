/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** animation ennemy
*/

#include "my_rpg.h"

void 	animation_attack_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[9]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 9) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[46]->spr, NULL);
	if (timer < 0.04)
		return;
	sfSprite_setTextureRect(cor->obj[46]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x == 256 && y == 128)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[9]);
}

void 	animation_dead_ennemy(core_t *cor, int id)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[8]);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 0;

	if (cor->btl.state.anim_ennemy != 3 || cor->state.is_dead == 1) {
		frame = 0;
		return;
	}
	if (timer < 0.04)
		return;
	frame += 1;
	sfSprite_setColor(cor->obj[id + 35]->spr,
	(sfColor){255, 255, 255, frame * (-15)});
	if (frame >= 17) {
		cor->state.is_dead = 1;
		cor->btl.state.anim_ennemy = 0;
	}
	sfClock_restart(cor->clocks[8]);
}

void 	animation_hit_ennemy(core_t *cor, int id)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[8]);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 0;
	int 	offset = -10;

	if (cor->btl.state.anim_ennemy != 2) {
		frame = 0;
		return;
	}
	if (timer < 0.02)
		return;
	frame += 1;
	offset *= (frame < 5) ? -1 : 1;
	sfSprite_move(cor->obj[id + 35]->spr, (V2F){offset, 0});
	if (frame >= 8)
		cor->btl.state.anim_ennemy = 0;
	sfClock_restart(cor->clocks[8]);
}

void 	animation_cast_ennemy(core_t *cor, int id)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[8]);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 0;
	int 	offset = 12;

	if (cor->btl.state.anim_ennemy != 1) {
		frame = 0;
		return;
	}
	if (timer < 0.03)
		return;
	frame += 1;
	offset *= (frame < 5) ? -1 : 1;
	sfSprite_move(cor->obj[id + 35]->spr, (V2F){offset, 0});
	if (frame >= 8)
		cor->btl.state.anim_ennemy = 0;
	sfClock_restart(cor->clocks[8]);
}
