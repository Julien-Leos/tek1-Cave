/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Description.
*/

#include "my_rpg.h"

char	*my_charcat(char *res, char src)
{
	int len = my_strlen(res);
	char *dest = malloc(sizeof(char) * (len + 2));

	for (int i = 0; i < len; i++)
		dest[i] = res[i];
	dest[len] = src;
	dest[len + 1] = '\0';
	if (res && res[0] != '\0')
		free (res);
	return (dest);
}

char *check_backslash_first(char *res, char *buf, int *save, int *is_return)
{
	for (int i = 0; buf[*save + i] != '\0'; i++) {
		if (buf[*save + i] == '\n') {
			*save = *save + i + 1;
			*is_return = 1;
			return (res);
		}
		res = my_charcat(res, buf[*save + i]);
	}
	res = my_charcat(res, '\0');
	return (res);
}

char	*check_backslash(char *res, char *buf, int *save, int *is_return)
{
	for (int i = 0; buf[i] != '\0'; i++) {
		if (buf[i] == '\n') {
			*save = i + 1;
			*is_return = 1;
			return (res);
		}
		res = my_charcat(res, buf[i]);
	}
	res = my_charcat(res, '\0');
	return (res);
}

char	*my_get_next_line(int fd)
{
	int readed = 0;
	int is_return = 0;
	static int save = 0;
	static char buf[READ_SIZE + 1] = "\0";
	char *res = "\0";

	res = check_backslash_first(res, buf, &save, &is_return);
	if (is_return == 1)
		return (res);
	for (int i = 0; i < READ_SIZE + 1; i++)
		buf[i] = '\0';
	while ((readed = read(fd, buf, READ_SIZE)) > 0) {
		buf[readed] = '\0';
		res = check_backslash(res, buf, &save, &is_return);
		if (is_return == 1)
			return (res);
	}
	return (NULL);
}
