/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** game_h
*/

#ifndef __GAME_RPG_H__
#define __GAME_RPG_H__

#include "my_rpg.h"
#include "game.h"
#include "parser.h"

typedef struct map_s {
	int	***info;
	int	**event;
	int	**mob;
	char	*map_name;
	int	line;
	int	col;
	int	layer;
	int	id;
} map_t;

typedef struct player_s {
	sfSprite *spt;
	sfVector2f pos;
	sfClock *clk;
	sfIntRect rect;
	int speed;
	int chrc[12];
	int spell[4];
	int life;
	int level;
	int exp;
	int skin_move;
} player_t;

typedef struct mob_s {
	int life;
	sfSprite *spr;
	sfVector2f pos;
	sfVector2f dir;
	sfIntRect rect;
	int ia;
	int event;
	int dead;
	int enn_id;
	int power;
	int chrc[6];
	int is_static;
} mob_t;

enum item_type {
	HELMET,
	CHESTPLATE,
	GLOVES,
	BOOTS,
	DICE,
	POTION,
	ITEM,
	QUEST,
	EMPTY
};

typedef struct armor_s {
	int id;
	sfVector2f armor_pos;
	enum item_type type;
} armor_t;

typedef struct item_s {
	sfSprite *spt;
	char *name;
	char *des;
	enum item_type type;
	int chrc[13];
} item_t;

typedef struct core_s {
	sfClock 		**clocks;
	sfVector2i		pos_mouse;
	int			new_game;
	int			actual_scene;
	int			save_actual;
	int			quest[NB_QUEST];
	sfRenderWindow 		*window;
	sfEvent 		event;
	char 			*chrc_name[13];
	struct map_s 		map;
	struct obj_game_s 	**obj;
	struct player_s ply;
	struct obj_inv_s obj_inv;
	struct obj_btl_s obj_btl;
	struct obj_spell_s obj_spell;
	struct btl_s btl;
	struct armor_s *armor;
	struct text_s *text_box;
	struct loot_s *loot;
	int *inv;
	struct item_s *item;
	struct state_s 	state;
	struct button_s *button;
	struct sound_s 		*sound;
	struct mob_s mob[20];
	struct particle_s *part;
	sfView			*view;
} core_t;

struct spell_fptr {
	int balise;
	void (*function)(struct core_s *);
};

struct spell_mob_fptr {
	int balise;
	void (*function)(struct core_s *);
};

struct conso_fptr {
	int balise;
	void (*function)(struct core_s *);
};

struct ai_mob_fptr {
	int balise;
	int (*function)(struct core_s *);
};

#endif
