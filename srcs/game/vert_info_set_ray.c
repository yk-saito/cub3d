/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertinfo_set_ray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:11:59 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:32:21 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	vert_info_set_ray(t_game *game, t_cast *ray_info,
						int win_x, double hit_dist)
{
	game->rays[win_x].distance = hit_dist;
	game->rays[win_x].wall_hit_x = ray_info->vert_hit_x;
	game->rays[win_x].wall_hit_y = ray_info->vert_hit_y;
	game->rays[win_x].hit_content = ray_info->vert_content;
	game->rays[win_x].hit_vertical = true;
	game->rays[win_x].ray_angle = ray_info->ray_angle;
	if (ray_info->ray_left)
		game->rays[win_x].direction = WE;
	else
		game->rays[win_x].direction = EA;
}
