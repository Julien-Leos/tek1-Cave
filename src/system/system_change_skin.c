/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** change skin of the player in settings
*/

#include "my_rpg.h"

sfTexture **init_skins(core_t *cor)
{
	sfTexture **txt = malloc(sizeof(sfTexture*) * 4);
	sfIntRect rect = (sfIntRect){0, 0, 576, 384};

	(void)cor;
	txt[0] = sfTexture_createFromFile("img/angel_fight.png", &rect);
	txt[1] = sfTexture_createFromFile("img/angel4_fight.png", &rect);
	txt[2] = sfTexture_createFromFile("img/angel3_fight.png", &rect);
	txt[3] = sfTexture_createFromFile("img/angel2_fight.png", &rect);
	return (txt);
}

void 	change_hero_skin(core_t *cor)
{
	static int i = 0;
	static sfTexture **txt = NULL;

	i = (i == 3) ? 0 : i + 1;
	txt = (txt == NULL) ? init_skins(cor) : txt;
	sfSprite_setTexture(cor->obj[14]->spr, txt[i], sfFalse);
	cor->ply.skin_move = i;
	cor->ply.rect.left = (i % 4) * (48 * 3);
	sfSprite_setTextureRect(cor->ply.spt, cor->ply.rect);
}