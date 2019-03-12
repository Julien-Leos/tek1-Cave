/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** csfml includes
*/

#ifndef __RPG_H__
#define __RPG_H__

#ifndef  READ_SIZE
#define  READ_SIZE (1)
#endif

#define NB_QUEST		1

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Network.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <fcntl.h>
#include <math.h>
#include <time.h>
#include "parser.h"
#include "graphics.h"
#include "engine.h"
#include "game.h"

#define LENGHT_WIN	1920
#define HEIGHT_WIN	1080

#define NB_BUTTONS		25
#define NB_INVENTORY_CASE	112
#define NB_ARMOR_CASE		10
#define NB_ITEMS		9
#define NB_CLOCKS 		23
#define NB_SOUNDS		33

#define PERCENT			3000
#define MULT			10

#define SPR_CREATE	sfSprite_create
#define SPR_SETPOS	sfSprite_setPosition
#define SPR_GETPOS	sfSprite_getPosition
#define SPR_SETTXT	sfSprite_setTexture
#define SPR_STXTRE	sfSprite_setTextureRect
#define SPR_SETSCL	sfSprite_setScale
#define SPR_COPY	sfSprite_copy

#define FNT_CRTFRF	sfFont_createFromFile

#define TXT_CREATE	sfText_create
#define TXT_SETFNT	sfText_setFont
#define TXT_SETSTR	sfText_setString
#define TXT_SETSIZ	sfText_setCharacterSize
#define TXT_SETPOS	sfText_setPosition
#define TXT_SETCLR	sfText_setColor

#define TXR_CRTFRF	sfTexture_createFromFile

#define RCT_CREATE	sfRectangleShape_create
#define RCT_SETPOS	sfRectangleShape_setPosition
#define RCT_GETPOS	sfRectangleShape_getPosition
#define RCT_SETCLR	sfRectangleShape_setFillColor
#define RCT_SETSIZ	sfRectangleShape_setSize
#define RCT_SETOUT	sfRectangleShape_setOutlineThickness
#define RCT_SETOCL	sfRectangleShape_setOutlineColor

#define RDW_DRWRCT	sfRenderWindow_drawRectangleShape
#define RDW_DRWSPR	sfRenderWindow_drawSprite
#define RDW_DRWTXT	sfRenderWindow_drawText

#define CLR_FRRGBA	sfColor_fromRGBA
#define INTRCT		sfIntRect
#define KEY_PRSD	sfKeyboard_isKeyPressed

typedef sfVector2f V2F;
typedef sfVector2i V2I;
typedef sfIntRect IRC;

/* ------------- INVENTORY --------------- */
void	display_inventory(core_t *cor);
int	recup_select_item_id(core_t *cor);
int	recup_actual_item_id(core_t *cor);
int	recup_select_armor_id(core_t *cor);
int	recup_actual_armor_id(core_t *cor);
/* --- DISPLAY OBJ --- */
void	display_obj(core_t *cor);
void	display_obj_inventory(core_t *cor, V2I pos_mouse, V2F pos_case);
void	display_obj_armor(core_t *cor, V2I pos_mouse, V2F pos_case);
int	verif_is_on_inventory_cases(V2I pos_mouse);
int	verif_is_good_armor_type(core_t *cor, int id);
int	verif_is_on_armor_cases(core_t *cor, V2F *pos_case);
void	set_item_draged(core_t *cor, int id);
/* --- DISPLAY ITEM --- */
void	display_item(core_t *cor);
/* --- DISPLAY INFO --- */
void	display_infobar(core_t *cor);
/* --- DISPLAY STAT --- */
void	display_static(core_t *cor);
void	actualise_player_stat(core_t *cor);
/* --- EVENT --- */
void	event_inventory(core_t *cor, int *status);
/* --- MOVE --- */
void	move_inventory(core_t *cor, int *status);
void	move_select_item(core_t *cor, int off_x, int off_y, int *status);
void	move_select_armor(core_t *cor, int off, int *status);
/* --- TOOLS --- */
int	recup_nbr_item(core_t *cor, int id);
void	delete_item(core_t *cor, int id);
void	add_item(core_t *cor, int id);

/* --------------- BATTLE ------------- */
void	display_battle(core_t *cor);
void	display_battle_obj(core_t *cor);
void	display_battle_top_stripe(core_t *cor);

void	display_battle_background(core_t *cor);
void	display_battle_nbr_elements(core_t *cor);
void 	display_battle_characters(core_t *cor);

void	player_turn(core_t *cor);
void	ennemy_turn(core_t *cor);

void	randomise_dice_launch(core_t *cor);
void	display_battle_dice_face(core_t *cor);

void	display_battle_life(core_t *cor);

void	init_new_battle(core_t *cor, int mob);

void	display_battle_object(core_t *cor);
void	display_battle_spell(core_t *cor);

void	display_damage_player(core_t *cor, sfColor color);
void	display_damage_ennemi(core_t *cor, sfColor color);

void	display_start_screen(core_t *cor);
void	display_win_screen(core_t *cor);
void	display_loose_screen(core_t *cor);

void	is_ennemy_dead(core_t *cor);
void	is_player_dead(core_t *cor);
int	is_enm_dmg_displayed(core_t *cor);
int	is_ply_dmg_displayed(core_t *cor);

void	select_conso(core_t *cor);
void	life_potion(core_t *cor);
void	big_life_potion(core_t *cor);
void	apple(core_t *cor);
void	cheese(core_t *cor);

void	get_armor_defense_enemy(core_t *cor);
void	get_armor_defense_player(core_t *cor);

int	is_ply_dmg_displayed(core_t *cor);
int	is_enm_dmg_displayed(core_t *cor);

int	is_critical_enemy(core_t *cor);
int	is_miss_enemy(core_t *cor);
int	is_critical_player(core_t *cor);
int	is_miss_player(core_t *cor);

void	reset_special_tornado(core_t *cor);
void	reset_special_sword_psy(core_t *cor);
void	reset_special_frog(core_t *cor);
void	reset_special_kaleidoscope(core_t *cor);
void	reset_special_blindy(core_t *cor);

int	is_all_anim_ended(core_t *cor);

/* --- GET CHARACTERISTICS --- */
int	get_damage(float attack, float strength);
int	get_defense(float armor, float defense);
int	get_critical(float critical);
int	get_miss(float esquive);
int	get_chance(float luck);

void	ai_ennemy(core_t *cor);

int	ai_torus(core_t *cor);
int	ai_centaur(core_t *cor);
int	ai_gnomes(core_t *cor);
int	ai_tiki(core_t *cor);
int	ai_warlords(core_t *cor);
int	ai_skeleton(core_t *cor);
int	ai_dragon(core_t *cor);
int	ai_zarboid(core_t *cor);
int	ai_yeti(core_t *cor);
int	ai_lyon(core_t *cor);
int	ai_mermaid(core_t *cor);

/* --------------- SPELLS ------------- */
void	anim_ply_handling(core_t *cor, int spell_id, int anim_id, int snd_id);
void	txt_state_ply_handling(core_t *cor, int txt_state);
int	defense_ply_handling(core_t *cor, float armor, float defense);
int	miss_ply_handling(core_t *cor, float esquive);
int	critical_ply_handling(core_t *cor, float critical, int coeff);
int	elem_handling(core_t *cor, int elem, int nb_elem);

void	select_spell(core_t *cor);

void	spell_meteor(core_t *cor);
void	spell_bramble(core_t *cor);
void	spell_wind(core_t *cor);
void	spell_light(core_t *cor);
void	spell_frog(core_t *cor);
void	spell_heal(core_t *cor);
void	spell_steal(core_t *cor);
void	spell_special(core_t *cor);

void	anim_mob_handling(core_t *cor, int spell_id, int snd_id);
void	txt_state_mob_handling(core_t *cor, int txt_state);
int	defense_mob_handling(core_t *cor, float armor, float defense);
int	miss_mob_handling(core_t *cor, float esquive);
int	critical_mob_handling(core_t *cor, float critical);

void	mob_spell_basic(core_t *cor);
void	mob_spell_cold_glaw(core_t *cor);
void	mob_spell_sword_psy(core_t *cor);
void	mob_spell_fire(core_t *cor);
void	mob_spell_insidious_stroke(core_t *cor);
void	mob_spell_kaleidoscope(core_t *cor);
void	mob_spell_tornado(core_t *cor);
void	mob_spell_heal(core_t *cor);
void	mob_spell_bindly(core_t *cor);
void	mob_spell_mandale(core_t *cor);

void 	display_spell_menu(core_t *cor);
void	event_spell_menu(core_t *cor, int *status);

int	id_spell_from_pos(V2F pos);
int	is_spell_selected(core_t *cor, V2F pos);
int	recup_id_tab_spell(core_t *cor, int id);
int	recup_free_tab_spell(core_t *cor);
int	verif_pos_select_spell_menu(V2F pos);

void	get_map_tab_int(int fd, map_t *map);
void	get_map_mob(int fd, map_t *map);

obj_t	**parse_map_tileset(char *path, int nb_case_line, int nb_line);
int	**get_layer_map(int **tab, sfVector2i param, int fd);
char 	**my_str_to_word_array(char *str, char c);
char	*my_get_next_line(int fd);
int	my_getnbr(char *str);
void	load_inv(core_t *cor, char **tab);
void	display_scare(core_t *cor);
int	exec_mob_2(core_t *cor, char **tab);
char	*concat(char *str1, char *str2);
char	*get_files(char const *filepath);
char	*my_strdup(char const *str);
int	get_enum(char *str);
int	my_cheat(int nb);
void	display_scare(core_t *cor);
char	*my_strcat(char *dest, char *src);
char	*my_itoa(int nb);
float	my_percent(double nb, double max);
char	*line_return(char *str);
obj_game_t	**get_struct_from_xml(void);

void	display_game(core_t *cor, obj_t **obj);
void	display_map(core_t *cor, obj_t **obj);
void 	display_menu(core_t *cor);
void 	display_pause(core_t *cor);
void	display_inventory(core_t *cor);
void 	display_spell_menu(core_t *cor);
void	analyse_events(core_t *cor);
void	scene_handling(core_t *cor, obj_t **obj);

void	get_map_event(int fd, map_t *map);
void	get_map(core_t *cor, char *path);
int	my_strlen(const char *str);
int	get_size_tab(char **tab);
void	my_putstr(char *str);

V2I	get_pos_player(core_t *cor);
text_t	*text_box(core_t *cor);
void	adding_text(char *str, core_t *cor);

void	coromp_files_test(void);

void	event_mob(core_t *cor);
int	my_exit(int i);
void	exec_jump_mob(core_t *cor, V2I param, char **tab, V2I pos);
void	start_fight(int i, int give_mob, core_t *cor);
void	exec_rand_speak(core_t *cor, char *str);
int	exec_png(void);
loot_t	*text_loot(core_t *cor);
void	add_give_iteam(core_t *cor, int id);
int	delete_mob_item(core_t *cor, int item);
int	exec_min(core_t *cor, char **tab);
void	add_item(core_t *cor, int id);
void	exec_give(core_t *cor, char **tab);
void	exec_fight(core_t *cor, char **tab, int mob);
int	exec_mob(core_t *cor, int fd, V2I pos, int mob);
void	event_map(core_t *cor);
void	exec_save(core_t *cor);
void	exec_jump(core_t *cor, int fd, char **tab);
int	exec_command(core_t *cor, int fd);
int	comp_char_files(char *files);
int	coromp_files_test_3(int nb);
void	exec_speak(char *str, core_t *cor);
void	exec_add_quete(core_t *cor, char **tab);
void	load_save(core_t *cor, char *path);
int	exec_max(core_t *cor, char **tab);
void	exec_tuto(core_t *cor);
void	exec_end(core_t *cor);
void	exec_door(core_t *cor, char **tab);

void	move_player(core_t *cor, obj_t **obj, int player_nb);
void	move_up(core_t *cor, obj_t **obj, int player_nb);
void	move_down(core_t *cor, obj_t **obj, int player_nb);
void	move_right(core_t *cor, obj_t **obj, int player_nb);
void	move_left(core_t *cor, obj_t **obj, int player_nb);
int	create_sprite(sfSprite	*obj, sfTexture	*img, sfIntRect rect);
sfIntRect	my_recup_item_rect(int id);
item_t	*parse_item();
void	draw_text(char *str, core_t *cor, V2F pos, int i);

player_t	init_player(core_t);
item_t		*init_item(void);
armor_t		*init_armor(core_t cor);
obj_inv_t	init_obj_inventory(core_t cor);
obj_btl_t	init_obj_battle(core_t cor);
btl_t		init_battle(core_t cor);
obj_spell_t	init_obj_spell(core_t cor);
int		*init_int_tab(int len);
sfVector2f	*init_armor_pos(core_t cor);
void		init_characteristics_name(core_t *cor);

obj_game_t	**get_struct_from_xml(void);
float	my_getfloat(char *str);
char *copy_str(char *str);
char	*my_getchar(int nbr);
int	my_strcmp(char *str, char *str2);
void	save_fonction(core_t *cor, char *path);
obj_t **set_colider_tiles_set(char *path, obj_t **obj);
int	create_sprite(sfSprite	*obj, sfTexture	*img, sfIntRect rect);
void	display_hit_box_player(core_t *cor);
int	is_collide(core_t *cor, obj_t **obj, V2F pos_to_check);
void	analyse_game_events(core_t *cor);
button_t *parser_btn(char *path, core_t *cor);
void 	event_menu(core_t *cor, obj_t **obj);
void 	change_state_buttons(core_t *cor, int i, int state);
void 	refresh_state_buttons(core_t *cor, int next, int select);
void 	event_keyboard_menu(core_t *cor, int *status);
void 	event_mouse_menu(core_t *cor);
int 	mouse_is_hover(sfSprite *elem, sfVector2i pos_click, sfVector2f size);
void 	generate_mouse_coords(core_t *cor);
void 	event_window_resize(core_t *cor);
int 	keyboard_button_click(core_t *cor, int id, sfKeyCode key, int *status);
int 	mouse_button_click(core_t *cor, int id, sfVector2f rect, int *status);
int 	macro_button_click(sfKeyCode key, int *status);
void 	event_battle(core_t *cor);

void 	display_buttons(core_t *cor);

void 	animation_stand_main_character(core_t *cor);
void	animation_hit_main_character(core_t *cor);
void	animation_acast_main_character(core_t *cor);
void	animation_bcast_main_character(core_t *cor);
void 	animation_dodge_main_character(core_t *cor);
void 	animation_dead_main_character(core_t *cor);
void 	animation_win_main_character(core_t *cor);

void 	animation_special_spell(core_t *cor);
void 	animation_bramble_spell(core_t *cor);
void 	animation_meteor_spell(core_t *cor);
void 	animation_wind_spell(core_t *cor);
void 	animation_light_spell(core_t *cor);
void 	animation_heal_spell(core_t *cor);
void 	animation_dark_spell(core_t *cor);
void 	animation_curse_spell(core_t *cor);

void 	animation_cast_ennemy(core_t *cor, int id);
void 	animation_hit_ennemy(core_t *cor, int id);
void 	animation_attack_spell(core_t *cor);
void 	animation_dead_ennemy(core_t *cor, int id);

void	change_scene(core_t *cor, int scene, int menu);
void 	next_scene_menu(int *next_scene, int *next_menu, core_t *cor);

void 	display_spell_animation(core_t *cor);
void 	display_quest_menu(core_t *cor);
void	display_quest(core_t *cor, int i, V2F pos);
void 	init_sound(core_t *cor);

sfVector2f	center_map(map_t map);

int	save_exist(char *path);

void 	event_change_keyboard_player_main(core_t *cor, int *status);
void 	event_change_mouse_player_main(core_t *cor, int *status);
void 	event_change_keyboard_control_main(core_t *cor, int *status);
void 	event_change_mouse_control_main(core_t *cor, int *status);
void 	event_change_mouse_return(core_t *cor, int *status);
void 	event_change_inventory_pannel(core_t *cor, int *status);
void 	event_change_quest_menu(core_t *cor, int *status);
void 	event_hover_quest_menu(core_t *cor);
void 	event_change_submenu_spell_menu(core_t *cor, int **status);
void 	event_change_submenu_quest_spell_menu(core_t *cor, int *status);

void	move_inv_up(core_t *cor, int *key, int *status);
void	move_inv_down(core_t *cor, int *key, int *status);
void	move_inv_left(core_t *cor, int *key, int *status);
void	move_inv_right(core_t *cor, int *key, int *status);

void 	move_mob(core_t *cor, obj_t **obj);
void 	move_mob_right(core_t *cor, obj_t **obj, int i, float s_perso);
void 	move_mob_left(core_t *cor, obj_t **obj, int i, float s_perso);
void 	move_mob_up(core_t *cor, obj_t **obj, int i, float s_perso);
void 	move_mob_down(core_t *cor, obj_t **obj, int i, float s_perso);

V2F	center_map(map_t map);
void	verif_is_printable(core_t *cor, obj_t **obj, int tab[3],
V2F tab_pos[2]);
void	verif_is_printable_2(core_t *cor, obj_t **obj, int tab[3],
V2F tab_pos[2]);
void	browse_column_2(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2]);
void	browse_line_2(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2]);
void	browse_layer_2(core_t *cor, obj_t **obj, int tab[3], V2F tab_pos[2]);

void 	display_entities(core_t *cor);

void 	change_hero_skin(core_t *cor);
void 	change_ui_volume(core_t *cor);
void 	change_music_volume(core_t *cor);

void 	event_change_keyboard_menu_main(core_t *cor, int *status);
void 	event_change_mouse_menu_main(core_t *cor, int *status);
void 	event_change_keyboard_menu_play(core_t *cor, int *status, obj_t **obj);
void 	event_change_mouse_menu_play(core_t *cor, int *status, obj_t **obj);

sfRenderWindow 	*my_window_create(void);
void 	change_save_sprite(core_t *cor);

void 	animation_blue_claw_spell(core_t *cor);
void 	animation_sword_psy_spell(core_t *cor);
void 	animation_fireball_spell(core_t *cor);
void 	animation_insidious_spell(core_t *cor);
void 	animation_kaleid_spell(core_t *cor);
void 	animation_tornado_spell(core_t *cor);
void 	animation_heal2_spell(core_t *cor);
void 	animation_eyes_spell(core_t *cor);
void 	animation_blow_spell(core_t *cor);

void 	particle_menu(core_t *cor);
void 	particle_move(core_t *cor);
void 	particle_draw_move(core_t *cor, int y);
void 	particle_pregeneration_move(core_t *cor);
void 	init_particle(core_t *cor);
void 	particle_event(core_t *cor);
void 	particle_draw_event(core_t *cor, int y);

void	level_up(core_t *cor, int value);

void 	event_over(core_t *cor);
void 	exec_tuto_continue(core_t *cor);
void	move_player_mous_b(core_t *cor, obj_t **obj, int player_nb, V2F vect);
void 	move_player_continue(core_t *cor, obj_t **obj, int player_nb);

#endif
