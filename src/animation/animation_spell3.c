/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 3 of animation spell
*/

#include "my_rpg.h"

void 	animation_curse_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[2]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 3) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[26]->spr, NULL);
	if (timer < 0.04)
		return;
	sfSprite_setTextureRect(cor->obj[26]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 256)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[2]);
}

void 	animation_dark_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[3]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 4) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[27]->spr, NULL);
	if (timer < 0.04)
		return;
	sfSprite_setTextureRect(cor->obj[27]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 128)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[3]);
}

void 	animation_heal_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[4]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 5) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[28]->spr, NULL);
	if (timer < 0.04)
		return;
	sfSprite_setTextureRect(cor->obj[28]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 256 && y >= 256)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[4]);
}

void 	animation_light_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[5]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 6) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[29]->spr, NULL);
	if (timer < 0.02)
		return;
	sfSprite_setTextureRect(cor->obj[29]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 256 && y >= 640)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[5]);
}

void 	animation_wind_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[7]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 8) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[32]->spr, NULL);
	if (timer < 0.04)
		return;
	sfSprite_setTextureRect(cor->obj[32]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 256)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[7]);
}
