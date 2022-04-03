/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:08:12 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 22:11:10 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "utils.h"
#include "game.h"

static void
	calc_angle_diff(t_game *game, t_render *sprite, int sprite_id)
{
	double	vect_x;
	double	vect_y;
	double	angle_player_to_sprite;

	vect_x = game->sprites[sprite_id].x - game->player.x;
	vect_y = game->sprites[sprite_id].y - game->player.y;
	angle_player_to_sprite = atan2(vect_y, vect_x);
	normalize_angle(&angle_player_to_sprite);
	if ((game->player.rotation_angle > 3 / 2 * PI
		&& game->player.rotation_angle <= 2 * PI)
		&& ((int)angle_player_to_sprite == 0))
	{
		angle_player_to_sprite += 2 * PI;
	}
	else if (((int)game->player.rotation_angle == 0)
			&& (angle_player_to_sprite > 3 / 2 * PI
			&& angle_player_to_sprite <= 2 * PI))
	{
		angle_player_to_sprite -= 2 * PI;
	}
	sprite->angle_diff = game->player.rotation_angle - angle_player_to_sprite;
}

static void
	calc_value_on_screen(t_game *game, t_render *sprite, t_screen *value)
{
	value->sift_size_x = (game->win.width / game->fov_angle)
							* sprite->angle_diff;
	value->render_x = game->win.width / 2 - value->sift_size_x;
	value->win_left_x = value->render_x - (sprite->strip_h / 2);
	value->win_right_x = value->render_x + (sprite->strip_h / 2);
	value->win_width = (int)value->win_right_x - value->win_left_x;
	sprite->tex_num = 4;
	sprite->tex_width = game->textures[sprite->tex_num].width;
	sprite->tex_height = game->textures[sprite->tex_num].height;
}

static void
	draw_left_half(t_game *game, t_render *sprite, t_screen *value, int id)
{
	double	dist_point_wall;
	double	wall_x;
	double	wall_y;

	sprite->tex_offset_x =
	(TILE_SIZE / 2) * (game->textures[sprite->tex_num].width / TILE_SIZE);
	while (value->render_x >= value->win_left_x)
	{
		if (value->render_x < 0)
			break ;
		if (value->render_x < game->win.width)
		{
			wall_x = game->rays[value->render_x].wall_hit_x;
			wall_y = game->rays[value->render_x].wall_hit_y;
			dist_point_wall =
			distance_points(game->player.x, game->player.y, wall_x, wall_y);
			if (game->sprites[id].distance < dist_point_wall)
			{
				draw_one_pixel(game, sprite, value->render_x);
			}
		}
		value->render_x--;
		sprite->tex_offset_x -= set_inc_or_decr(game, value, sprite);
	}
}

static void
	draw_right_half(t_game *game, t_render *sprite, t_screen *value, int id)
{
	double	dist_point_wall;
	double	wall_x;
	double	wall_y;

	value->render_x = game->win.width / 2 - value->sift_size_x;
	sprite->tex_offset_x =
	(TILE_SIZE / 2) * (game->textures[sprite->tex_num].width / TILE_SIZE);
	while (value->render_x < value->win_right_x)
	{
		if (value->render_x >= game->win.width)
			break ;
		if (value->render_x >= 0)
		{
			wall_x = game->rays[value->render_x].wall_hit_x;
			wall_y = game->rays[value->render_x].wall_hit_y;
			dist_point_wall =
			distance_points(game->player.x, game->player.y, wall_x, wall_y);
			if (game->sprites[id].distance < dist_point_wall)
			{
				draw_one_pixel(game, sprite, value->render_x);
			}
		}
		value->render_x++;
		sprite->tex_offset_x += set_inc_or_decr(game, value, sprite);
	}
}

void
	render_sprite(t_game *game)
{
	int			id;
	t_render	sprite;
	t_screen	value_sprite;

	if (!(game->map.sprite_flag))
		return ;
	sort_sprites_by_distance(game);
	id = 0;
	while (id < game->map.sprite_flag)
	{
		ft_bzero(&sprite, sizeof(t_render));
		ft_bzero(&value_sprite, sizeof(t_screen));
		calc_angle_diff(game, &sprite, id);
		if (!(sprite.angle_diff >= game->fov_angle)
			&& !(sprite.angle_diff <= -1 * game->fov_angle))
		{
			calc_size_to_project(game, &sprite, game->sprites[id].distance);
			calc_value_on_screen(game, &sprite, &value_sprite);
			draw_left_half(game, &sprite, &value_sprite, id);
			draw_right_half(game, &sprite, &value_sprite, id);
		}
		id++;
	}
	return ;
}
