/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 5 of animation spell
*/

#include "my_rpg.h"

void 	animation_kaleid_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[16]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 14) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[67]->spr, NULL);
	if (timer < 0.03)
		return;
	sfSprite_setTextureRect(cor->obj[67]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 384 && y >= 256)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[16]);
}

void 	animation_tornado_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[17]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 15) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[68]->spr, NULL);
	if (timer < 0.06)
		return;
	sfSprite_setTextureRect(cor->obj[68]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 0)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[17]);
}

void 	animation_heal2_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[18]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 16) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[69]->spr, NULL);
	if (timer < 0.03)
		return;
	sfSprite_setTextureRect(cor->obj[69]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 640)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[18]);
}

void 	animation_eyes_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[19]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 17) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[70]->spr, NULL);
	if (timer < 0.03)
		return;
	sfSprite_setTextureRect(cor->obj[70]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 256)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[19]);
}

void 	animation_blow_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[20]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 18) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[71]->spr, NULL);
	if (timer < 0.03)
		return;
	sfSprite_setTextureRect(cor->obj[71]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 128 && y >= 128)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[20]);
}
