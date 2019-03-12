/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** animation of the main character
*/

#include "my_rpg.h"

void 	animation_win_main_character(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->ply.clk);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 0;

	if (cor->btl.state.anim_main != 6) {
		frame = 0;
		return;
	}
	if (timer < 0.14)
		return;
	sfSprite_setTextureRect(cor->obj[14]->spr,
	(sfIntRect){frame, 64, 64, 64});
	frame = (frame == 128) ? 0 : frame + 64;
	sfClock_restart(cor->ply.clk);
}

void 	animation_dead_main_character(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->ply.clk);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 0;

	if (cor->btl.state.anim_main != 5) {
		frame = 0;
		return;
	}
	if (timer < 0.24)
		return;
	sfSprite_setTextureRect(cor->obj[14]->spr,
	(sfIntRect){frame, 320, 64, 64});
	frame = (frame == 128) ? 0 : frame + 64;
	sfClock_restart(cor->ply.clk);
}

void 	animation_dodge_main_character(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->ply.clk);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 384;

	if (cor->btl.state.anim_main != 4) {
		frame = 384;
		return;
	}
	if (timer < 0.24)
		return;
	sfSprite_setTextureRect(cor->obj[14]->spr,
	(sfIntRect){frame, 320, 64, 64});
	if (frame == 512)
		cor->btl.state.anim_main = 0;
	frame = (frame == 512) ? 384 : frame + 64;
	sfClock_restart(cor->ply.clk);
}

void	animation_bcast_main_character(core_t *cor)
{
	sfTime curr_time = sfClock_getElapsedTime(cor->ply.clk);
	float timer = curr_time.microseconds / 1000000.0;
	static int frame = 192;

	if (cor->btl.state.anim_main != 3) {
		frame = 192;
		return;
	}
	if (timer < 0.24)
		return;
	sfSprite_setTextureRect(cor->obj[14]->spr,
	(sfIntRect){frame, 192, 64, 64});
	if (frame == 256)
		cor->btl.state.anim_main = 0;
	frame = (frame == 256) ? 192 : frame + 64;
	sfClock_restart(cor->ply.clk);
}
