/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:33:54 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 13:32:04 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "utils.h"
#include "game.h"

static void	swap_values(t_game *game, int first, int second)
{
	t_sprite	temp_sprite;

	ft_bzero(&temp_sprite, sizeof(t_sprite));
	temp_sprite.x = game->sprites[first].x;
	temp_sprite.y = game->sprites[first].y;
	temp_sprite.distance = game->sprites[first].distance;
	game->sprites[first].x = game->sprites[second].x;
	game->sprites[first].y = game->sprites[second].y;
	game->sprites[first].distance = game->sprites[second].distance;
	game->sprites[second].x = temp_sprite.x;
	game->sprites[second].y = temp_sprite.y;
	game->sprites[second].distance = temp_sprite.distance;
}

static void	set_distance(t_game *game)
{
	int		idx;
	double	sp_x;
	double	sp_y;

	idx = 0;
	while (idx < game->map.sprite_flag)
	{
		sp_x = game->sprites[idx].x;
		sp_y = game->sprites[idx].y;
		game->sprites[idx].distance =
		distance_points(game->player.x, game->player.y, sp_x, sp_y);
		idx++;
	}
}

void		sort_sprites_by_distance(t_game *game)
{
	int	loop_count;
	int	first;
	int	second;

	set_distance(game);
	loop_count = 0;
	while (loop_count < game->map.sprite_flag)
	{
		first = game->map.sprite_flag - 2;
		second = game->map.sprite_flag - 1;
		while (first >= loop_count)
		{
			if (game->sprites[first].distance < game->sprites[second].distance)
				swap_values(game, first, second);
			first--;
			second--;
		}
		loop_count++;
	}
	return ;
}
