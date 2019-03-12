/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 4 of animations for spells
*/

#include "my_rpg.h"

void 	animation_blue_claw_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[12]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 10) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[63]->spr, NULL);
	if (timer < 0.02)
		return;
	sfSprite_setTextureRect(cor->obj[63]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 256)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[12]);
}

void 	animation_sword_psy_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[13]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 11) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[64]->spr, NULL);
	if (timer < 0.027)
		return;
	sfSprite_setTextureRect(cor->obj[64]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 640)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[13]);
}

void 	animation_fireball_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[14]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 12) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[65]->spr, NULL);
	if (timer < 0.035)
		return;
	sfSprite_setTextureRect(cor->obj[65]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 512 && y >= 256)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[14]);
}

void 	animation_insidious_spell(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->clocks[15]);
	float timer = curr_time.microseconds / 1000000.0;
	static int x = 0;
	static int y = 0;

	if (cor->btl.state.anim_spell != 13) {
		x = 0;
		y = 0;
		return;
	}
	RDW_DRWSPR(cor->window, cor->obj[66]->spr, NULL);
	if (timer < 0.03)
		return;
	sfSprite_setTextureRect(cor->obj[66]->spr,
	(sfIntRect){x, y, 128, 128});
	if (x >= 256 && y >= 512)
		cor->btl.state.anim_spell = 0;
	y += (x == 512) ? 128 : 0;
	x = (x == 512) ? 0 : x + 128;
	sfClock_restart(cor->clocks[15]);
}
