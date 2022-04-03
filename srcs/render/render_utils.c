/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:47:28 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 23:55:53 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "game.h"

void
	calc_size_to_project(t_game *game, t_render *target, double dist_to_target)
{
	target->perp_distance =
	dist_to_target * cos(target->angle_diff);
	target->projected_h =
	(TILE_SIZE / target->perp_distance) * game->win.dist_prj_plane;
	target->strip_h = target->projected_h;
	if (target->strip_h < 0)
		target->strip_h = 0;
	target->top_pixel = (game->win.height / 2) - (target->strip_h / 2);
	target->top_pixel = target->top_pixel < 0 ? 0 : target->top_pixel;
	target->btm_pixel = (game->win.height / 2) + (target->strip_h / 2);
	target->btm_pixel =
	target->btm_pixel > game->win.height ? game->win.height : target->btm_pixel;
	return ;
}

void
	put_color_to_projection(t_game *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_len + x * (game->img.bpp / 8));
	*(unsigned int*)dst = color;
	return ;
}

void
	draw_one_pixel(t_game *game, t_render *target, int win_x)
{
	int	win_y;
	int	distance_from_top;
	int	texcolor_pos;
	int	color;

	win_y = target->top_pixel;
	while (win_y < target->btm_pixel)
	{
		distance_from_top =
		win_y + (target->strip_h / 2) - (game->win.height / 2);
		target->tex_offset_y =
		distance_from_top * ((double)target->tex_height / target->strip_h);
		texcolor_pos =
		target->tex_width * target->tex_offset_y + (int)target->tex_offset_x;
		color = game->textures[target->tex_num].addr[texcolor_pos];
		if (!(target->tex_num == 4 && color == 0x00000000))
			put_color_to_projection(game, win_x, win_y, color);
		win_y++;
	}
	return ;
}

double
	set_inc_or_decr(t_game *game, t_screen *value, t_render *sprite)
{
	double	sprite_w;
	int		textures_w;

	sprite_w = (double)value->win_width;
	textures_w = game->textures[sprite->tex_num].width;
	return ((((double)TILE_SIZE / sprite_w) * (textures_w / TILE_SIZE)));
}
