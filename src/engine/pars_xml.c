/*
** EPITECH PROJECT, 2017
** my_cook
** File description:
** Description
*/

#include "my_rpg.h"

char	*get_name(char *str)
{
	char *final = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 0;

	for (; str[i] != '\0'; i += 1)
		final[i] = str[i];
	final[i] = '\0';
	return (final);
}

void	get_param_first_part(obj_game_t *final, char *str, char *str2)
{
	final->name = get_name(str);
	final->img = sfTexture_createFromFile(str2, NULL);
	final->spr = sfSprite_create();
}

sfIntRect	get_rect(char *str1, char *str2, char *str3, char *str4)
{
	return ((sfIntRect){my_getnbr(str1), my_getnbr(str2),
	my_getnbr(str3), my_getnbr(str4)});
}

sfVector2f	get_v2f(char *str, char *str2)
{
	return ((V2F){my_getnbr(str), my_getnbr(str2)});
}

obj_game_t	**get_struct_from_xml(void)
{
	obj_game_t	**final;
	int fd = open("config/texture_load.jlm", O_RDONLY);
	char	*txt = my_get_next_line(fd);
	char 	**str = my_str_to_word_array(txt, ' ');
	int	nb_text;

	nb_text = my_getnbr(str[1]);
	final = malloc(sizeof(obj_game_t*) * (nb_text + 1));
	for (int i = 0; i < nb_text; i += 1) {
		final[i] = malloc(sizeof(obj_game_t));
		txt = my_get_next_line(fd);
		str = my_str_to_word_array(txt, ',');
		get_param_first_part(final[i], str[1], str[2]);
		create_sprite(final[i]->spr, final[i]->img, get_rect(str[3],
		str[4], str[5], str[6]));
		sfSprite_setPosition(final[i]->spr, get_v2f(str[7], str[8]));
		final[i]->pos = (V2F){my_getnbr(str[7]), my_getnbr(str[8])};
		sfSprite_setScale(final[i]->spr, get_v2f(str[9], str[9]));
	}
	return (final);
}
