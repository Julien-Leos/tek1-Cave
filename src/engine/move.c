/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** move
*/

#include "my_rpg.h"

void	move_down(core_t *cor, obj_t **obj, int player_nb)
{
	sfTime time = sfClock_getElapsedTime(cor->ply.clk);
	float s_perso = time.microseconds / 1000000.0;
	int pos_x = cor->ply.pos.x;
	int pos_y = cor->ply.pos.y + cor->ply.speed;

	particle_pregeneration_move(cor);
	if (is_collide(cor, obj, (V2F){pos_x, pos_y + 12}) == 0 &&
	is_collide(cor, obj, (V2F){pos_x + 24, pos_y + 12}) == 0)
		cor->ply.pos.y += cor->ply.speed;
	SPR_SETPOS(cor->ply.spt, cor->ply.pos);
	sfSprite_setTextureRect(cor->ply.spt, cor->ply.rect);
	cor->ply.rect.top = (player_nb / 4 * (48 * 4)) + (0 * 48);
	if (s_perso > 0.1) {
		cor->ply.rect.left += 48;
		if (cor->ply.rect.left >= (player_nb % 4 + 1) * (48 * 3))
			cor->ply.rect.left = (player_nb % 4) * (48 * 3);
		sfClock_restart(cor->ply.clk);
	}
}

void	move_right(core_t *cor, obj_t **obj, int player_nb)
{
	sfTime time = sfClock_getElapsedTime(cor->ply.clk);
	float s_perso = time.microseconds / 1000000.0;
	int pos_x = cor->ply.pos.x + cor->ply.speed;
	int pos_y = cor->ply.pos.y;

	particle_pregeneration_move(cor);
	if (is_collide(cor, obj, (V2F){pos_x + 24, pos_y}) == 0 &&
	is_collide(cor, obj, (V2F){pos_x + 24, pos_y + 12}) == 0)
		cor->ply.pos.x += cor->ply.speed;
	SPR_SETPOS(cor->ply.spt, (V2F){cor->ply.pos.x + 3, cor->ply.pos.y});
	sfSprite_setTextureRect(cor->ply.spt, cor->ply.rect);
	cor->ply.rect.top = (player_nb / 4 * (48 * 4)) + (2 * 48);
	if (s_perso > 0.1) {
		cor->ply.rect.left += 48;
		if (cor->ply.rect.left >= (player_nb % 4 + 1) * (48 * 3))
			cor->ply.rect.left = (player_nb % 4) * (48 * 3);
		sfClock_restart(cor->ply.clk);
	}
}

void	move_left(core_t *cor, obj_t **obj, int player_nb)
{
	sfTime time = sfClock_getElapsedTime(cor->ply.clk);
	float s_perso = time.microseconds / 1000000.0;
	int pos_x = cor->ply.pos.x - cor->ply.speed;
	int pos_y = cor->ply.pos.y;

	particle_pregeneration_move(cor);
	if (is_collide(cor, obj, (V2F){pos_x, pos_y}) == 0 &&
	is_collide(cor, obj, (V2F){pos_x, pos_y + 12}) == 0)
		cor->ply.pos.x -= cor->ply.speed;
	SPR_SETPOS(cor->ply.spt, (V2F){cor->ply.pos.x - 3, cor->ply.pos.y});
	sfSprite_setTextureRect(cor->ply.spt, cor->ply.rect);
	cor->ply.rect.top = (player_nb / 4 * (48 * 4)) + (1 * 48);
	if (s_perso > 0.1) {
		cor->ply.rect.left += 48;
		if (cor->ply.rect.left >= (player_nb % 4 + 1) * (48 * 3))
			cor->ply.rect.left = (player_nb % 4) * (48 * 3);
		sfClock_restart(cor->ply.clk);
	}
}

void 	move_player_mouse(core_t *cor, obj_t **obj, int player_nb)
{
	V2F vect = (V2F){cor->ply.pos.x - cor->pos_mouse.x,
	cor->ply.pos.y - cor->pos_mouse.y};

	if (cor->state.in_menu != 3 || !sfMouse_isButtonPressed(sfMouseLeft))
		return;
	vect.x = (vect.x < 20 && vect.x > -20) ? 0 : vect.x;
	vect.y = (vect.y < 20 && vect.y > -20) ? 0 : vect.y;
	if (vect.x < 0)
		move_right(cor, obj, player_nb);
	move_player_mous_b(cor, obj, player_nb, vect);

}

void	move_player(core_t *cor, obj_t **obj, int player_nb)
{
	if (sfKeyboard_isKeyPressed(sfKeyD))
		move_right(cor, obj, player_nb);
	move_player_continue(cor, obj, player_nb);
	move_player_mouse(cor, obj, player_nb);
}
