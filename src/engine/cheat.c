/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** comp_char_files
*/

#include "my_rpg.h"

int	comp_char_files(char *files)
{
	int fd = open(files, O_RDONLY);
	char *str = NULL;
	int nb = 0;

	if (fd == -1) {
		my_exit(71);
		return (0);
	}
	for (str = my_get_next_line(fd); str != NULL;
	str = my_get_next_line(fd)) {
		for (int i = 0; str[i] != '\0'; i++)
			nb += str[i];
	}
	return (nb);
}

int	coromp_files_test_2(int nb)
{
	char *test[] = {"config/ode-path-house-top.map.event",
	"config/ode-path-house-top.map.mob", "config/ode-path.map",
	"config/ode-path.map.event", "config/ode-path.map.mob",
	"config/ode-path-sorcery.map", "config/ode-path-sorcery.map.event",
	"config/ode-path-sorcery.map.mob", "config/test.map",
	"config/texture_load.jlm", "config/tunnel-1.map",
	"config/tunnel-1.map.event", "config/tunnel-1.map.mob",
	"config/tunnel-2.map", "config/tunnel-2.map.event",
	"config/tunnel-2.map.mob", "config/tunnel-3.map",
	"config/tunnel-3.map.event", "config/tunnel-3.map.mob",
	"config/tunnel-4.map", "config/tunnel-4.map.event",
	"config/tunnel-4.map.mob", NULL};

	for (int i = 0; test[i] != NULL; i++)
		nb += comp_char_files(test[i]);
	return (coromp_files_test_3(nb));
}

int	coromp_files_test_1(int nb)
{
	char *test[] = {"config/alley-house.map",
	"config/alley-house.map.event", "config/alley-house.map.mob",
	"config/alley-inn.map", "config/alley-inn.map.event",
	"config/alley-inn.map.mob", "config/alley-market.map",
	"config/alley-market.map.event", "config/alley-market.map.mob",
	"config/alley-path.map", "config/alley-path.map.event",
	"config/alley-path.map.mob", "config/arena-house.map",
	"config/arena-house.map.event", "config/arena-house.map.mob",
	"config/arena-main.map", "config/arena-main.map.event",
	"config/arena-main.map.mob", "config/arena-path.map",
	"config/arena-path.map.event", "config/arena-path.map.mob", NULL};

	for (int i = 0; test[i] != NULL; i++)
		nb += comp_char_files(test[i]);
	return (coromp_files_test_2(nb));
}

int	comp_event(int nb)
{
	char *str = NULL;

	for (int i = 1; i < 44; i++) {
		str = concat("event/", concat(my_getchar(i), ".evt"));
		nb += comp_char_files(str);
	}
	for (int i = 50; i < 91; i++) {
		str = concat("event/", concat(my_getchar(i), ".evt"));
		nb += comp_char_files(str);
	}
	nb += comp_char_files("event/200.evt");
	nb += comp_char_files("event/1020.evt");
	nb += comp_char_files("quest/2.qst");
	nb += comp_char_files("quest/3.qst");
	for (int i = 1; i < 53; i++) {
		str = concat("mob/", concat(my_getchar(i), ".mob"));
		nb += comp_char_files(str);
	}
	return (nb);
}

void	coromp_files_test(void)
{
	int nb = 0;

	nb = coromp_files_test_1(nb);
	nb = comp_event(nb);
	nb += comp_char_files("quest/0.qst");
	nb += comp_char_files("quest/1.qst");
}
