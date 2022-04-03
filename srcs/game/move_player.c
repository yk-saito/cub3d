/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:48:39 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/26 15:45:00 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"
#include "map.h"

static bool	check_collision(t_game *game, t_position *pos)
{
	if (!(map_has_wall_at(game, pos->new_player_x, pos->new_player_y))
		&& (!(map_has_sprite_at(game, pos->new_player_x, pos->new_player_y)))
		&& (!(map_has_wall_at(game, pos->new_lside_x, pos->new_lside_y)))
		&& (!(map_has_wall_at(game, pos->new_rside_x, pos->new_rside_y))))
		return (false);
	else
		return (true);
}

void		move_player(t_game *game)
{
	t_position	pos;

	ft_bzero(&pos, sizeof(t_position));
	game->player.rotation_angle +=
	game->player.turn_direction * game->player.turn_speed;
	normalize_angle(&game->player.rotation_angle);
	pos.move_step = game->player.walk_direction * game->player.walk_speed;
	pos.new_player_x = game->player.x +
	cos(game->player.rotation_angle + game->player.side) * pos.move_step;
	pos.new_player_y = game->player.y +
	sin(game->player.rotation_angle + game->player.side) * pos.move_step;
	pos.new_lside_x = game->player.x + cos((game->player.rotation_angle
								+ pos.move_drct) - (2 / PI)) * pos.move_step;
	pos.new_lside_y = game->player.y + sin((game->player.rotation_angle
								+ pos.move_drct) - (2 / PI)) * pos.move_step;
	pos.new_rside_x = game->player.x + cos((game->player.rotation_angle
								+ pos.move_drct) + (2 / PI)) * pos.move_step;
	pos.new_rside_y = game->player.y + sin((game->player.rotation_angle
								+ pos.move_drct) + (2 / PI)) * pos.move_step;
	if (check_collision(game, &pos) == false)
	{
		game->player.x = pos.new_player_x;
		game->player.y = pos.new_player_y;
	}
	return ;
}
