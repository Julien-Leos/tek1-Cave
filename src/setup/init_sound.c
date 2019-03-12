/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** sound setup functions
*/

#include "my_rpg.h"

void 	snd_setup(core_t *cor, char *path, int i, int volume)
{
	cor->sound[i].buffer = sfSoundBuffer_createFromFile(path);
	cor->sound[i].obj = sfSound_create();
	sfSound_setBuffer(cor->sound[i].obj, cor->sound[i].buffer);
	sfSound_setVolume(cor->sound[i].obj, volume);
}

void 	init_ui_sound(core_t *cor)
{
	snd_setup(cor, "snd/cursor.ogg", 1, 50);
	snd_setup(cor, "snd/confirm.wav", 2, 50);
	snd_setup(cor, "snd/save.ogg", 12, 50);
	snd_setup(cor, "snd/quest.wav", 13 , 50);
	snd_setup(cor, "snd/close.wav", 14, 50);
	snd_setup(cor, "snd/impossible.ogg", 15, 50);
	snd_setup(cor, "snd/consume.ogg", 16, 50);
	snd_setup(cor, "snd/dice.ogg", 17, 50);
	snd_setup(cor, "snd/end_dice.ogg", 18, 50);
	snd_setup(cor, "snd/win.ogg", 20, 50);
	snd_setup(cor, "snd/lose.ogg", 21, 50);
	snd_setup(cor, "snd/enter_battle.ogg", 22, 50);
	snd_setup(cor, "snd/text.wav", 23, 50);
}

void 	init_spell_sound(core_t *cor)
{
	snd_setup(cor, "snd/fire.ogg", 4, 50);
	snd_setup(cor, "snd/bramble.ogg", 5, 50);
	snd_setup(cor, "snd/curse.ogg", 6, 50);
	snd_setup(cor, "snd/dark.ogg", 7, 50);
	snd_setup(cor, "snd/heal.ogg", 8, 50);
	snd_setup(cor, "snd/light.ogg", 9, 50);
	snd_setup(cor, "snd/special.ogg", 10, 50);
	snd_setup(cor, "snd/wind.ogg", 11, 50);
	snd_setup(cor, "snd/attack.ogg", 19, 50);
	snd_setup(cor, "snd/claw.ogg", 24, 50);
	snd_setup(cor, "snd/psy.ogg", 25, 50);
	snd_setup(cor, "snd/fiire.ogg", 26, 50);
	snd_setup(cor, "snd/crow.ogg", 27, 50);
	snd_setup(cor, "snd/kaleid.ogg", 28, 50);
	snd_setup(cor, "snd/wind1.ogg", 29, 50);
	snd_setup(cor, "snd/heal2.ogg", 30, 50);
	snd_setup(cor, "snd/eyes.ogg", 31, 50);
	snd_setup(cor, "snd/monkas.wav", 32, 50);
}

void 	init_ambiance_sound(core_t *cor)
{
	snd_setup(cor, "snd/main.ogg", 0, 50);
	snd_setup(cor, "snd/ambiance.ogg", 3, 50);
	sfSound_setLoop(cor->sound[3].obj, sfTrue);
}

void 	init_sound(core_t *cor)
{
	cor->sound = malloc(sizeof(sound_t) * NB_SOUNDS);
	init_ui_sound(cor);
	init_spell_sound(cor);
	init_ambiance_sound(cor);
	sfSound_play(cor->sound[0].obj);
}
