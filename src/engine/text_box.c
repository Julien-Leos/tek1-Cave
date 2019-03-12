/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** text_box
*/

#include "my_rpg.h"

void	adding_text(char *str, core_t *cor)
{
	text_t *node = malloc(sizeof(text_t));
	text_t *save = cor->text_box;

	node->str = my_strdup(str);
	node->next = NULL;
	if (cor->text_box == NULL) {
		cor->text_box = node;
		return;
	}
	while (cor->text_box->next != NULL)
		cor->text_box = cor->text_box->next;
	cor->text_box->next = node;
	cor->text_box = save;
}

void	draw_text(char *str, core_t *cor, V2F pos, int i)
{
	static sfFont 	*font = NULL;
	sfText 		*txt;

	font = (font == NULL) ? sfFont_createFromFile("img/font.ttf") : font;
	txt = sfText_create();
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setColor(txt, (sfColor){255, 255, 255, 255});
	sfText_setString(txt, str);
	sfText_setPosition(txt, pos);
	if (i == 1)
		sfText_setColor(txt, (sfColor){255, 255, 255, 255});
	sfRenderWindow_drawText(cor->window, txt, NULL);
}

void	draw_text_speak(char *str, core_t *cor, V2F pos)
{
	static sfFont 	*font = NULL;
	sfText 		*txt;

	font = (font == NULL) ? sfFont_createFromFile("img/font.ttf") : font;
	txt = sfText_create();
	sfText_setCharacterSize(txt, 45);
	sfText_setFont(txt, font);
	sfText_setColor(txt, (sfColor) {255, 255, 255, 255});
	sfText_setString(txt, str);
	sfText_setPosition(txt, pos);
	sfRenderWindow_drawText(cor->window, txt, NULL);
}

text_t	*text_exec(core_t *cor)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) ||
	sfMouse_isButtonPressed(sfMouseLeft)) {
		if (my_cheat(5) == 0) {
			my_cheat(1);
			return (cor->text_box->next);
		}
	} else
		my_cheat(0);
	return (cor->text_box);
}

text_t	*text_box(core_t *cor)
{
	if (cor->quest[0] == 22 && cor->text_box == NULL)
		cor->actual_scene = 42;
	if (cor->text_box == NULL)
		return (cor->text_box);
	display_scare(cor);
	if (!my_strcmp(cor->text_box->str, "*!FIGHT!*"))
		draw_text_speak(cor->text_box->str, cor, (V2F){25, 425});
	return (text_exec(cor));
}
