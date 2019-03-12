/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** part 4 of lib functions
*/

#include "my_rpg.h"

float	my_percent(double nb, double max)
{
	double res = nb / max;

	return (res * 100);
}

sfIntRect	my_recup_item_rect(int id)
{
	int col = id % 8;
	int line = id / 8;
	sfIntRect rect = {col * 16, line * 16, 16, 16};

	return (rect);
}

char	*my_strcat(char *dest, char *src)
{
	int len = my_strlen(dest);
	int slen = my_strlen(src);
	char *res = malloc(sizeof(char) * (len + slen + 1));
	int i = 0;

	while (i < len) {
		res[i] = dest[i];
		i++;
	}
	i = 0;
	while (i < slen) {
		res[len + i] = src[i];
		i++;
	}
	res[len + i] = '\0';
	return (res);
}

char *copy_str(char *str)
{
	char *final = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 0;

	if (str == NULL)
		return (NULL);
	for (; str[i] != '\0'; i += 1) {
		if (str[i] != '_')
			final[i] = str[i];
		else
			final[i] = ' ';
	}
	final[i] = '\0';
	return (final);
}

char	*line_return(char *str)
{
	char *final = malloc(sizeof(char) * (my_strlen(str) + 1));
	int i = 0;

	if (str == NULL)
		return (NULL);
	for (; str[i] != '\0'; i += 1) {
		if (str[i] != '@')
			final[i] = str[i];
		else
			final[i] = '\n';
	}
	final[i] = '\0';
	return (final);
}
