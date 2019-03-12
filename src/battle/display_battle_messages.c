/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

int	change_start_msg_cycle(core_t *cor)
{
	if (cor->btl.msg_cycle == 30) {
		cor->btl.msg_cycle = 0;
		cor->btl.turn_state = -1;
		display_battle_dice_face(cor);
		sfSound_play(cor->sound[17].obj);
		return (1);
	} else
		cor->btl.msg_cycle++;
	return (0);
}

int	change_end_msg_cycle(core_t *cor, int is_dead, int scene, int in_menu)
{
	if (cor->btl.msg_cycle == 100) {
		sfSound_play(cor->sound[3].obj);
		cor->actual_scene = scene;
		cor->state.in_menu = in_menu;
		cor->btl.msg_cycle++;
		cor->mob[cor->btl.mob_id].dead = is_dead;
		cor->state.is_dead = is_dead * (-1) + 1;
		return (1);
	} else if (cor->btl.msg_cycle > 100) {
		return (1);
	} else
		cor->btl.msg_cycle++;
	return (0);
}

void	display_start_screen(core_t *cor)
{
	V2F pos = {0, 0};
	int alpha = 0;

	if (change_start_msg_cycle(cor) == 1)
		return;
	pos.x = 760 - cor->btl.msg_cycle * 3.33;
	pos.y = 450 - cor->btl.msg_cycle * 3.33;
	alpha = 255 - cor->btl.msg_cycle * 8.5;
	TXT_SETCLR(cor->obj_btl.txt, CLR_FRRGBA(180, 0, 0, alpha));
	TXT_SETSIZ(cor->obj_btl.txt, 100 + cor->btl.msg_cycle * 3.33);
	TXT_SETSTR(cor->obj_btl.txt, "FIGHT !");
	TXT_SETPOS(cor->obj_btl.txt, pos);
	RDW_DRWTXT(cor->window, cor->obj_btl.txt, NULL);
}

void	display_loose_screen(core_t *cor)
{
	V2F pos = {0, 0};
	int alpha = 0;

	if (change_end_msg_cycle(cor, 0, 4, 10) == 1)
		return;
	pos.x = 700 - cor->btl.msg_cycle * 1.3;
	pos.y = 450 - cor->btl.msg_cycle;
	alpha = 255 - cor->btl.msg_cycle * 2.55;
	TXT_SETCLR(cor->obj_btl.txt, CLR_FRRGBA(180, 0, 0, alpha));
	TXT_SETSIZ(cor->obj_btl.txt, 100 + cor->btl.msg_cycle);
	TXT_SETSTR(cor->obj_btl.txt, "YOU LOOSE !");
	TXT_SETPOS(cor->obj_btl.txt, pos);
	RDW_DRWTXT(cor->window, cor->obj_btl.txt, NULL);
}

void	display_win_screen(core_t *cor)
{
	V2F pos = {0, 0};
	int alpha = 0;

	if (change_end_msg_cycle(cor, 1, 2, 3) == 1)
		return;
	pos.x = 730 - cor->btl.msg_cycle;
	pos.y = 450 - cor->btl.msg_cycle;
	alpha = 255 - cor->btl.msg_cycle * 2.55;
	TXT_SETCLR(cor->obj_btl.txt, CLR_FRRGBA(0, 180, 0, alpha));
	TXT_SETSIZ(cor->obj_btl.txt, 100 + cor->btl.msg_cycle);
	TXT_SETSTR(cor->obj_btl.txt, "YOU WIN !");
	TXT_SETPOS(cor->obj_btl.txt, pos);
	RDW_DRWTXT(cor->window, cor->obj_btl.txt, NULL);
}
