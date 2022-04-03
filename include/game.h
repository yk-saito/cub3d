/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:47:05 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/26 15:14:48 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "cub3d.h"

typedef struct	s_position
{
	double		move_step;
	double		move_drct;
	double		new_player_x;
	double		new_player_y;
	double		new_lside_x;
	double		new_lside_y;
	double		new_rside_x;
	double		new_rside_y;
}				t_position;

typedef struct	s_cast
{
	double		ray_angle;
	int			ray_down;
	int			ray_up;
	int			ray_right;
	int			ray_left;
	double		intercept_x;
	double		intercept_y;
	double		step_x;
	double		step_y;
	double		horz_hit_x;
	double		horz_hit_y;
	int			horz_content;
	double		vert_hit_x;
	double		vert_hit_y;
	int			vert_content;
	int			horz_wallhit;
	int			vert_wallhit;
}				t_cast;

typedef struct	s_grid
{
	double		next_x;
	double		next_y;
	double		check_x;
	double		check_y;
}				t_grid;

int				game_hook(t_game *game);
void			move_player(t_game *game);
void			cast_rays(t_game *game);
int				horz_grid_intersection(t_game *game, t_cast *ray_info);
int				vert_grid_intersection(t_game *game, t_cast *ray_info);
void			horz_info_set_ray(t_game *game, t_cast *ray_info,
								int win_x, double hit_dist);
void			vert_info_set_ray(t_game *game, t_cast *ray_info,
								int win_x, double hit_dist);
double			distance_points(double x1, double y1, double x2, double y2);
void			normalize_angle(double *angle);
void			set_window(t_game *game);

#endif
