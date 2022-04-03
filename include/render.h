/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 09:50:15 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 16:07:29 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cub3d.h"

typedef struct	s_screen
{
	double		sift_size_x;
	int			render_x;
	double		win_left_x;
	double		win_right_x;
	int			win_width;
}				t_screen;

typedef struct	s_render
{
	double		angle_diff;
	double		perp_distance;
	double		projected_h;
	int			strip_h;
	int			top_pixel;
	int			btm_pixel;
	double		tex_offset_x;
	int			tex_offset_y;
	int			tex_width;
	int			tex_height;
	int			tex_num;
}				t_render;

void			render_projection(t_game *game);
void			render_sprite(t_game *game);
void			sort_sprites_by_distance(t_game *game);
void			put_ray_vs_sprite_color(t_game *game, int idx, int color);
void			put_wall_hit_point(t_game *game, int idx, int color);

/*
**rendering_utils.c
*/
void			calc_size_to_project(t_game *game, t_render *target,
									double dist_to_target);
void			put_color_to_projection(t_game *game, int x, int y, int color);
void			draw_one_pixel(t_game *game, t_render *target, int win_x);
void			draw_sprite_one_pixel(t_game *game, t_render *sprite,
									t_screen *value, int sprite_id);
double			set_inc_or_decr(t_game *game, t_screen *value,
								t_render *sprite);

#endif
