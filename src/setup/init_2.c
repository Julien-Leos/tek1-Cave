/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** main
*/

#include "my_rpg.h"

player_t	init_player(core_t cor)
{
	player_t ply;

	ply.spt = sfSprite_create();
	ply.spt = SPR_COPY(cor.obj[18]->spr);
	sfSprite_setTextureRect(ply.spt, ply.rect);
	sfSprite_setOrigin(ply.spt, (V2F){12, 35});
	ply.clk = sfClock_create();
	ply.rect = (sfIntRect){320, 0, 48, 48};
	ply.speed = 3;
	ply.life = 500;
	ply.level = 1;
	ply.exp = 0;
	ply.skin_move = 0;
	ply.spell[0] = 0;
	ply.spell[1] = 1;
	ply.spell[2] = 2;
	ply.spell[3] = 5;
	for (int i = 0; i < 12; i++)
		ply.chrc[i] = 0;
	return (ply);
}

obj_inv_t	init_obj_inventory(core_t cor)
{
	obj_inv_t obj_inv;
	sfFont *font = FNT_CRTFRF("img/font.ttf");

	obj_inv.txt = TXT_CREATE();
	TXT_SETFNT(obj_inv.txt, font);
	obj_inv.actual = RCT_CREATE();
	RCT_SETCLR(obj_inv.actual, CLR_FRRGBA(200, 200, 200, 75));
	RCT_SETSIZ(obj_inv.actual, (V2F){64, 64});
	obj_inv.background = SPR_COPY(cor.obj[15]->spr);
	obj_inv.select = SPR_COPY(cor.obj[16]->spr);
	obj_inv.select_big = SPR_COPY(cor.obj[17]->spr);
	SPR_SETSCL(obj_inv.select_big, (V2F){0.5, 0.5});
	obj_inv.which_select = 0;
	obj_inv.is_drag = 0;
	obj_inv.pannel = 0;
	return (obj_inv);
}

void	init_obj_battle_sub(obj_btl_t *obj_btl, core_t cor)
{
	obj_btl->color_txt[0] = CLR_FRRGBA(0, 0, 0, 255);
	obj_btl->color_txt[1] = CLR_FRRGBA(0, 0, 0, 255);
	obj_btl->dmg_txt[0] = NULL;
	obj_btl->dmg_txt[1] = NULL;
	obj_btl->which_menu = 0;
	for (int i = 0; i < 6; i++) {
		obj_btl->dice[i] = SPR_COPY(cor.obj[22]->spr);
		obj_btl->last_dice[i] = -1;
		obj_btl->dice_cycle[i] = 0;
	}
}

obj_btl_t	init_obj_battle(core_t cor)
{
	obj_btl_t obj_btl;
	sfFont *font = FNT_CRTFRF("img/font.ttf");

	obj_btl.txt = TXT_CREATE();
	TXT_SETFNT(obj_btl.txt, font);
	SPR_SETSCL(cor.obj[19]->spr, (V2F){3.32, 3.32});
	SPR_SETPOS(cor.obj[19]->spr, (V2F){0, -220});
	obj_btl.life = RCT_CREATE();
	RCT_SETCLR(obj_btl.life, sfColor_fromRGBA(0, 150, 0, 255));
	obj_btl.out_life = RCT_CREATE();
	RCT_SETSIZ(obj_btl.out_life, (V2F){350, 50});
	RCT_SETOUT(obj_btl.out_life, 4);
	RCT_SETCLR(obj_btl.out_life, sfColor_fromRGBA(0, 0, 0, 0));
	RCT_SETOCL(obj_btl.out_life, sfColor_fromRGBA(150, 150, 150, 255));
	obj_btl.actual = RCT_CREATE();
	RCT_SETSIZ(obj_btl.actual, (V2F){256, 256});
	RCT_SETCLR(obj_btl.actual, sfColor_fromRGBA(200, 200, 200, 75));
	init_obj_battle_sub(&obj_btl, cor);
	return (obj_btl);
}

btl_t	init_battle(core_t cor)
{
	btl_t btl;

	(void)cor;
	for (int i = 0; i < 6; i++)
		btl.total_elem[i] = 100;
	for (int i = 0; i < 5; i++)
		btl.special[i] = 0;
	btl.dmg[0] = -1;
	btl.dmg[1] = -1;
	btl.dmg_cycle[0] = 0;
	btl.dmg_cycle[1] = 0;
	btl.msg_cycle = 0;
	btl.state.anim_main = 0;
	btl.state.anim_spell = 0;
	btl.state.anim_ennemy = 0;
	btl.turn_state = -2;
	btl.enn_id = 0;
	return (btl);
}
