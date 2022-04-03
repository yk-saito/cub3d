/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 09:49:35 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 23:56:29 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "utils.h"

static void	render_ceiling(t_game *game, t_render *wall, int x)
{
	int	y;

	y = 0;
	while (y < wall->top_pixel)
	{
		put_color_to_projection(game, x, y, game->color.ceiling);
		y++;
	}
	return ;
}

static void	render_wall(t_game *game, t_render *wall, int win_x)
{
	int	wall_hit_x;
	int	wall_hit_y;

	wall_hit_x = (int)game->rays[win_x].wall_hit_x;
	wall_hit_y = (int)game->rays[win_x].wall_hit_y;
	wall->tex_num = game->rays[win_x].direction;
	wall->tex_width = game->textures[wall->tex_num].width;
	wall->tex_height = game->textures[wall->tex_num].height;
	if (game->rays[win_x].hit_vertical)
	{
		wall->tex_offset_x = (wall_hit_y % TILE_SIZE) *
						((double)(wall->tex_width) / (double)(TILE_SIZE));
		if (game->rays[win_x].direction == 2)
			wall->tex_offset_x = wall->tex_width - wall->tex_offset_x;
	}
	else
	{
		wall->tex_offset_x = (wall_hit_x % TILE_SIZE) *
						((double)(wall->tex_width) / (double)(TILE_SIZE));
		if (game->rays[win_x].direction == 1)
			wall->tex_offset_x = wall->tex_width - wall->tex_offset_x;
	}
	if (game->rays[win_x].hit_content == '1')
		draw_one_pixel(game, wall, win_x);
	return ;
}

static void	render_floor(t_game *game, t_render *wall, int win_x)
{
	int	win_y;

	win_y = wall->btm_pixel;
	while (win_y < game->win.height)
	{
		put_color_to_projection(game, win_x, win_y, game->color.floor);
		win_y++;
	}
}

void		render_projection(t_game *game)
{
	t_render	wall;
	int			win_x;

	ft_bzero(&wall, sizeof(t_render));
	win_x = 0;
	while (win_x < game->win.width)
	{
		wall.angle_diff =
		game->rays[win_x].ray_angle - game->player.rotation_angle;
		calc_size_to_project(game, &wall, game->rays[win_x].distance);
		render_ceiling(game, &wall, win_x);
		render_wall(game, &wall, win_x);
		render_floor(game, &wall, win_x);
		win_x++;
	}
}
