##
## EPITECH PROJECT, 2017
## makefile
## File description:
## makefile day13
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wextra

CFLAGS	+=	-L ../.graphic_programming/lib/

CFLAGS	+=	-I ../.graph_programming/include/SFML/

CFLAGS	+=	-I ./include/

CFLAGS	+=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

#LIB	=	-lm -lc_graph_prog

NAME	=	my_rpg

SRC	=	src/main.c					\
		src/engine/exec_mob.c				\
		src/engine/move.c				\
		src/engine/move2.c 				\
		src/engine/move_mob.c 				\
		src/engine/move_mob_dir.c 			\
		src/parse_btn.c					\
		src/setup/init.c				\
		src/setup/init_2.c				\
		src/setup/init_sound.c 				\
		src/display/display_game.c			\
		src/display/display_game2.c 			\
		src/misc/misc_display_game.c 			\
		src/engine/parser.c				\
		src/misc/get_next_line.c			\
		src/misc/lib_fonc.c				\
		src/misc/lib_func2.c 				\
		src/misc/lib_func3.c 				\
		src/misc/lib_func4.c 				\
		src/misc/str_to_word_arrays.c			\
		src/system/system_user_interaction.c 		\
		src/system/system_window_handle.c 		\
		src/system/system_user_actions.c 		\
		src/engine/colider_tileset.c			\
		src/event/event_menu.c 				\
		src/event/event_menu2.c 			\
		src/engine/exec_end.c				\
		src/engine/pars_xml.c				\
		src/engine/text_box.c				\
		src/engine/save_load.c				\
		src/engine/text_box_2.c				\
		src/engine/exit.c				\
		src/engine/cheat.c				\
		src/engine/cheat_2.c				\
		src/engine/scene_handling.c 			\
		src/display/display_menu.c 			\
		src/display/display_quest.c 			\
		src/engine/check_collide.c			\
		src/engine/save.c 				\
		src/engine/get_event.c				\
		src/engine/get_map.c				\
		src/engine/exec_mob_2.c				\
		src/event/event_map.c				\
		src/engine/exec_event_2.c			\
		src/engine/exec_event_3.c			\
		src/engine/exec_event_4.c			\
		src/engine/exec_event.c				\
		src/engine/global.c				\
		src/event/event_game.c				\
		src/event/event_game_2.c			\
		src/event/event_game_3.c			\
		src/event/event_inventory.c			\
		src/event/event_battle.c 			\
		src/inventory/display_inventory.c		\
		src/inventory/display_item.c			\
		src/inventory/display_obj.c			\
		src/inventory/display_obj_inventory.c		\
		src/inventory/display_obj_armor.c		\
		src/inventory/display_infobar.c			\
		src/inventory/display_stat.c			\
		src/inventory/move_inventory.c			\
		src/inventory/move_inventory_2.c		\
		src/inventory/move_inventory_tools.c		\
		src/inventory/inventory_parser.c		\
		src/inventory/inventory_parser_enum.c		\
		src/inventory/inventory_tools.c			\
		src/animation/animation_character.c 		\
		src/animation/animation_character2.c 		\
		src/animation/animation_spell.c 		\
		src/animation/animation_spell2.c 		\
		src/animation/animation_spell3.c 		\
		src/animation/animation_spell4.c 		\
		src/animation/animation_spell5.c 		\
		src/animation/animation_ennemy.c 		\
		src/animation/animation_scene.c 		\
		src/animation/particle_menu.c 			\
		src/animation/particle_move.c 			\
		src/animation/particle_event.c 			\
		src/setup/init_particle.c 			\
		src/battle/display_battle.c			\
		src/battle/display_battle_ui.c			\
		src/battle/display_battle_spell.c		\
		src/battle/display_battle_object.c		\
		src/battle/display_battle_messages.c		\
		src/battle/display_battle_dice.c		\
		src/battle/display_battle_life.c		\
		src/battle/display_battle_damage.c		\
		src/battle/battle_tools.c			\
		src/battle/randomise_dice.c			\
		src/battle/conso.c				\
		src/battle/get_characteristics.c		\
		src/battle/ply_spell/ply_spell_handling.c	\
		src/battle/ply_spell/ply_spell_handling_2.c	\
		src/battle/ply_spell/spell_bramble.c		\
		src/battle/ply_spell/spell_frog.c		\
		src/battle/ply_spell/spell_heal.c		\
		src/battle/ply_spell/spell_light.c		\
		src/battle/ply_spell/spell_meteor.c		\
		src/battle/ply_spell/spell_special.c		\
		src/battle/ply_spell/spell_steal.c		\
		src/battle/ply_spell/spell_wind.c		\
		src/battle/mob_spell/mob_spell_handling.c	\
		src/battle/mob_spell/spell_basic.c		\
		src/battle/mob_spell/spell_bindly.c		\
		src/battle/mob_spell/spell_cold_glaw.c		\
		src/battle/mob_spell/spell_fire.c		\
		src/battle/mob_spell/spell_heal.c		\
		src/battle/mob_spell/spell_insidious_stroke.c	\
		src/battle/mob_spell/spell_kaleidoscope.c	\
		src/battle/mob_spell/spell_mandale.c		\
		src/battle/mob_spell/spell_sword_psy.c		\
		src/battle/mob_spell/spell_tornado.c		\
		src/battle/mob_ai/ai_selection.c		\
		src/battle/mob_ai/ai_centaur.c			\
		src/battle/mob_ai/ai_dragon.c			\
		src/battle/mob_ai/ai_gnomes.c			\
		src/battle/mob_ai/ai_lyon.c			\
		src/battle/mob_ai/ai_mermaid.c			\
		src/battle/mob_ai/ai_skeleton.c			\
		src/battle/mob_ai/ai_tiki.c			\
		src/battle/mob_ai/ai_torus.c			\
		src/battle/mob_ai/ai_warlords.c			\
		src/battle/mob_ai/ai_yeti.c			\
		src/battle/mob_ai/ai_zarboid.c			\
		src/battle/reset_special_attack.c		\
		src/battle/turn_managment.c			\
		src/battle/init_battle.c			\
		src/spell_menu/display_spell_menu.c		\
		src/spell_menu/spell_menu_tools.c		\
		src/event/event_spell_menu.c			\
		src/system/system_change_skin.c 		\
		src/system/system_change_volume.c		\
		src/engine/player_level.c 			\
		src/event/event_over.c 				\

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	export LIBRARY_PATH=$LIBRARY_PATH:/home/charlieono/.graph_programming/lib
	export LD_LIBRARY_PATH=$LIBRARY_PATH:/home/charlieono/.graph_programming/lib
	export CPATH=$CPATH:/home/charlieono/.graph_programming/include
	$(CC) $(OBJ) $(CFLAGS) $(LIB) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
