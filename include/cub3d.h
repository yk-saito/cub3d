/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:02:41 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 16:45:10 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ERROR		0

# define ERR_HEADER			"Error\n"
# define ERR_MALLOC			"Failed to allocate malloc.\n"
# define ERR_TIPS			"There were these errors.\n"

/*
** check_args.c
*/
# define ERR_NUM_OF_ARGS	"The number of arguments is incorrect.\n"
# define ERR_FILE_NAME		"The file name is specified incorrectly.\n"
# define ERR_ARGMNT_SAVE	"The argument --save is specified incorrectly.\n"
# define ARGS_FORMAT		"Specify two or three arguments as follows.\n"
# define ARGS_EX1			"$ ./cub3D [file-path (extension .cub)]\n"
# define ARGS_EX2			"$ ./cub3D [file-path (extension .cub)] --save\n"

/*
** init_game.c
*/
# define ERR_INIT			"Initialization failed.\n"

/*
** setup_scene.c
*/
# define ERR_OPEN_FILE		"File open failed.\n"
# define ERR_NEW_LIST		"Failed to create a new list.\n"
# define ERR_READ_FILE		"Failed to read the .cubfile.\n"

/*
** ckeck_elements.c
*/
# define ERR_COUNT_WIN		"Multiple 'R's are specified or not specified.\n"
# define ERR_COUNT_NORTH	"Multiple 'NO's are specified or not specified.\n"
# define ERR_COUNT_SORTH	"Multiple 'SO's are specified or not specified.\n"
# define ERR_COUNT_WEST		"Multiple 'WE's are specified or not specified.\n"
# define ERR_COUNT_EAST		"Multiple 'EA's are specified or not specified.\n"
# define ERR_COUNT_SPRITE	"Multiple 'S's are specified or not specified.\n"
# define ERR_COUNT_F		"Multiple 'F's are specified or not specified.\n"
# define ERR_COUNT_C		"Multiple 'C's are specified or not specified.\n"
# define ERR_CHAR			"The file contains invalid characters.\n"

/*
** load_textures.c
*/
# define ERR_ROAD_TEXS		"Failed to read the texture file.\n"

/*
** check_map.c
*/
# define ERR_BIG_MAP		"The size of the map is too large.\n"
# define ERR_NO_MAP			"No map is specified.\n"
# define ERR_MULTI_MAP		"There are multiple maps.\n"
# define ERR_MAP_CHAR		"The map contains characters that cannot be used.\n"
# define ERR_PLAYER			"No players, or there are multiple players.\n"
# define ERR_MAP_WALL		"The player is not covered by a wall.\n"

/*
** make_bmp.c
*/
# define ERR_BMP			"Bitmap generation failed.\n"

/*
** setup
*/
# define MAP_SIZE_MAX	10000

/*
** game settings
*/
# define ANGLE				60
# define HORZ_ANGLE			180
# define PI					3.14159265
# define TWO_PI				6.28318530
# define DBL_MAX			1.7976931348623158e+308
# define TILE_SIZE			64
# define NUM_TEXTURES		5
# define MINIMAP_SCALE_FACTOR	0.2

# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_window
{
	char		*win;
	int			width;
	int			height;
	double		dist_prj_plane;
}				t_window;

typedef struct	s_player
{
	double		x;
	double		y;
	char		first_direction;
	int			turn_direction;
	int			walk_direction;
	double		rotation_angle;
	double		walk_speed;
	double		turn_speed;
	double		side;
}				t_player;

typedef struct	s_color
{
	int			floor;
	int			ceiling;
}				t_color;

typedef	struct	s_texture
{
	char		*path;
	void		*img;
	int			*addr;
	int			line_len;
	int			bpp;
	int			endian;
	int			width;
	int			height;
}				t_texture;

typedef struct	s_map
{
	char		**map;
	int			*width;
	int			num_row_max;
	int			num_col_max;
	int			start_row;
	int			end_row;
	int			player_flag;
	int			sprite_flag;
	int			out_flag;
	int			height;
}				t_map;

typedef	struct	s_sprite
{
	double		x;
	double		y;
	double		distance;
}				t_sprite;

typedef struct	s_image
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_image;

typedef enum	e_direction
{
	NO,
	SO,
	WE,
	EA
}				t_direction;

typedef struct	s_ray
{
	double		ray_angle;
	double		wall_hit_x;
	double		wall_hit_y;
	double		distance;
	bool		hit_vertical;
	char		hit_content;
	t_direction	direction;
}				t_ray;

typedef struct	s_flag
{
	int			save;
	int			exit;
	int			update;
}				t_flag;

typedef struct	s_game
{
	char		*mlx;
	double		fov_angle;
	t_window	win;
	t_player	player;
	t_color		color;
	t_texture	textures[NUM_TEXTURES];
	t_map		map;
	t_image		img;
	t_ray		*rays;
	t_sprite	*sprites;
	t_flag		flag;
}				t_game;

#endif
