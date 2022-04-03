# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/14 17:09:00 by ysaito            #+#    #+#              #
#    Updated: 2020/11/26 15:24:32 by ysaito           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3D
SRC_DIR	:=	./srcs
SRC_FILE	:=	main.c \
				utils/ft_atoi_cub.c \
				utils/ft_bzero.c \
				utils/ft_isdigit.c \
				utils/ft_memcpy.c \
				utils/ft_putstr.c \
				utils/ft_strlen.c \
				utils/ft_strncmp.c \
				utils/ft_strchr.c \
				utils/ft_strrchr.c \
				utils/ft_strdup.c \
				utils/ft_strjoin_and_free.c \
				utils/ft_substr.c \
				utils/ft_split.c \
				utils/get_next_line.c \
				utils/init_game.c \
				utils/init_game_loop.c \
				utils/init_img_addr.c \
				utils/init_rays.c \
				utils/init_sprite.c \
				utils/init_window_size.c \
				utils/free_display.c \
				utils/free_double_array.c \
				utils/free_game.c \
				utils/free_image.c \
				utils/free_rays.c \
				utils/free_sprites.c \
				utils/free_textures.c \
				utils/exit.c \
				setup/check_args.c \
				setup/check_elements.c \
				setup/check_elements_utils.c \
				setup/check_char_in_map.c \
				setup/check_sprite_in_map.c \
				setup/check_wall_in_map.c \
				setup/choose_errfmt_and_exit.c \
				setup/error_handling.c \
				setup/load_textures.c \
				setup/lst_sp.c \
				setup/read_cubfile.c \
				setup/setup_scene.c \
				setup/set_map.c \
				game/cast_rays.c \
				game/distance_points.c \
				game/game_hook.c \
				game/move_player.c \
				game/normalize_angle.c \
				game/horz_grid_intersection.c \
				game/vert_grid_intersection.c \
				game/horz_info_set_ray.c \
				game/vert_info_set_ray.c \
				game/set_window.c \
				bmp/make_bitmap.c \
				bmp/set_header.c \
				bmp/set_pixel.c \
				event/event.c \
				map/map.c \
				render/render_projection.c \
				render/render_sprite.c \
				render/render_utils.c \
				render/sort_sprite.c
INC_DIR	:=	./include
SRCS	:=	$(addprefix $(SRC_DIR)/,$(SRC_FILE))
OBJS	:=	$(SRCS:.c=.o)
CC		:=	gcc
AR		:=	ar rc
RM		:=	rm -f

#UNAME	:= $(shell uname)
#ifeq ($(UNAME), Linux)
MLX_NAME	:=	libmlx.a
MLX_DIR		:=	./minilibx-linux
LIBS		:=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm
#else
#	MLX_NAME	:=	libmlx.dylib
#	MLX_DIR		:=	./minilibx_mms_20200219
#	LIBS		:=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -lm
#endif

CFLAGS	:=	-Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR)
#CFLAGS	:=	-Wall -Wextra -Werror -g -fsanitize=address -I$(INC_DIR) -I$(MLX_DIR)

$(NAME):	$(OBJS)
			$(MAKE) -C $(MLX_DIR)
			cp $(MLX_DIR)/$(MLX_NAME) .
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS)

all:		$(NAME)

bonus:		all

clean:
			$(MAKE) -C $(MLX_DIR) clean
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(MLX_NAME)
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all bonus clean fclean re
