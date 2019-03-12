/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** libfunc part 3
*/

#include "my_rpg.h"

char	*my_strdup(char const *str)
{
	char *mal = NULL;
	int i = 0;
	int size = my_strlen(str);

	mal = malloc(sizeof(char) * (size + 1));
	if (mal == NULL)
		return (NULL);
	while (str[i] != '\0') {
		mal[i] = str[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

int	my_pow(int nb, int power)
{
	int res = nb;

	if (power > 0) {
		nb = res * my_pow(nb, power - 1);
		return (nb);
	} else if (power == 0)
		return (1);
	else
		return (0);
}

int	my_intlen(int nb)
{
	int count = 0;

	if (nb == 0)
		return (1);
	for (; nb > 0; count++, nb /= 10);
	return (count);
}

char	*my_itoa(int nb)
{
	int len = my_intlen(nb);
	char *new = malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++) {
		new[i] = nb / my_pow(10, len - i - 1) + '0';
		nb -= my_pow(10, len - i - 1) * (new[i] - '0');
	}
	new[len] = '\0';
	return (new);
}