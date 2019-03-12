/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** parser_btn
*/

#include "my_rpg.h"

button_t *parser_btn(char *path, core_t *cor)
{
	int fd = open(path, O_RDONLY);
	char **tab = my_str_to_word_array(my_get_next_line(fd), ' ');
	int size = my_getnbr(tab[0]);
	int i = 0;
	button_t *button = malloc(sizeof(button_t) * size);

	while (size > 0) {
		tab = my_str_to_word_array(my_get_next_line(fd), ' ');
		button[i].spr = sfSprite_copy(cor->obj[3]->spr);
		sfSprite_setPosition(button[i].spr,
		(V2F){my_getnbr(tab[2]), my_getnbr(tab[3])});
		button[i].belong_menu = my_getnbr(tab[4]);
		button[i].state = my_getnbr(tab[5]);
		button[i].top = my_getnbr(tab[6]);
		i += 1;
		size -= 1;
	}
	return (button);
}