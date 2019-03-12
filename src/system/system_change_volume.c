/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** change volume in settings menu
*/

#include "my_rpg.h"

void 	change_music_volume(core_t *cor)
{
	static float volume = 50;

	volume = (volume == 100) ? 0 : volume + 25;
	sfSound_setVolume(cor->sound[0].obj, volume);
	sfSound_setVolume(cor->sound[3].obj, volume);
}

void 	change_ui_volume(core_t *cor)
{
	static float volume = 50;

	volume = (volume == 100) ? 0 : volume + 25;
	for (int i = 0; i < NB_SOUNDS; i++) {
		if (i == 0 || i == 3)
			continue;
		sfSound_setVolume(cor->sound[i].obj, volume);
	}
	sfSound_play(cor->sound[13].obj);
}