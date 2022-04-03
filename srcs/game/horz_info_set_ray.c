/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horzinfo_set_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:16:45 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:32:41 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	horz_info_set_ray(t_game *game, t_cast *ray_info,
						int win_x, double hit_dist)
{
	game->rays[win_x].distance = hit_dist;
	game->rays[win_x].wall_hit_x = ray_info->horz_hit_x;
	game->rays[win_x].wall_hit_y = ray_info->horz_hit_y;
	game->rays[win_x].hit_content = ray_info->horz_content;
	game->rays[win_x].hit_vertical = false;
	game->rays[win_x].ray_angle = ray_info->ray_angle;
	if (ray_info->ray_up)
		game->rays[win_x].direction = NO;
	else
		game->rays[win_x].direction = SO;
}
