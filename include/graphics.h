/*
** EPITECH PROJECT, 2018
** my_cook
** File description:
** graphic header with animations prototype and objects
*/

#ifndef __GRAPHICS_H__
#define __GRAPHICS_H__

#define TXT_FIREBALL	"Inflige des degats.\n"	\
			"(Base sur INT)\n\n"	\
			"Cout: 4 Feu"

#define TXT_BRAMBLE	"Inflige des degats plus\n"	\
			"des degats sur les PV Max\n"	\
			"ennemi. (8%)\n"		\
			"(Base sur FOR)\n\n"		\
			"Cout: 2 Terre\t1 Eau"

#define TXT_WIND1 	"Inflige des degats plus\n"	\
			"un bonus base sur les\n"	\
			"elements EAU actuel. (4%)\n"	\
			"(Base sur AGI)\n\n"		\
			"Cout: 3 Air"

#define TXT_LIGHT	"Inflige des degats.\n"		\
			"Soigne l'heros.\n"		\
			"Saute le tour adverse.\n"	\
			"(Base sur FOR)\n\n"		\
			"Cout: 4 Lumiere\t2 Air"

#define TXT_FROG	"Reduit de 10% l'armure\n"	\
			"ennemi et augmente de 10%\n"	\
			"l'armure du heros jusqu'au\n"	\
			"prochain tour.\n\n"		\
			"Cout: 2 Terre\t1 Feu"

#define TXT_HEAL	"Soigne l'heros.\n"	\
			"(Base sur CHA)\n\n"	\
			"Cout: 3 Eau"

#define TXT_DARK 	"Inflige des degats puis\n"	\
			"soigne l'heros a hauteur\n"	\
			"de 50% des degats infliges.\n"	\
			"(Base sur CHA)\n\n"		\
			"Cout: 2 Eau\t2 Tenebre"

#define TXT_CRIT 	"Inflige des degats. Degats x4\n"	\
			"en cas de critique.\n"			\
			"(Base sur INT)\n\n"			\
			"Cout: 2 Air\t2 Feu"

typedef struct obj_game_s {
	char *name;
	sfSprite	*spr;
	sfTexture	*img;
	sfVector2f	pos;
} obj_game_t;

typedef struct sound_s {
	sfSoundBuffer	*buffer;
	sfSound 	*obj;
} sound_t;

typedef struct text_s {
	char	*str;
	struct text_s *next;
} text_t;

typedef struct loot_s {
	int	id;
	struct loot_s *next;
} loot_t;

typedef struct button_s {
	sfSprite *spr;
	int 	belong_menu;
	int 	state;
	int 	top;
} button_t;

typedef struct obj_s {
	sfSprite	*obj;
	int		hit_box;
} obj_t;

typedef struct particle_s {
	sfCircleShape *obj;
	sfVector2f dir;
	sfVector2f pos;
	int opacity;
} particle_t;

#endif
