/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 23:15:30 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:33:11 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"

static void	calc_and_choose_smallest(t_game *game, t_cast *ray_info, int win_x)
{
	double	horz_hit_distance;
	double	vert_hit_distance;

	horz_hit_distance = ray_info->horz_wallhit ?
						distance_points(game->player.x, game->player.y,
									ray_info->horz_hit_x, ray_info->horz_hit_y)
						: DBL_MAX;
	vert_hit_distance = ray_info->vert_wallhit ?
						distance_points(game->player.x, game->player.y,
									ray_info->vert_hit_x, ray_info->vert_hit_y)
						: DBL_MAX;
	if (vert_hit_distance < horz_hit_distance)
		vert_info_set_ray(game, ray_info, win_x, vert_hit_distance);
	else
		horz_info_set_ray(game, ray_info, win_x, horz_hit_distance);
	return ;
}

static void	init_ray_info(t_cast *ray_info, double ray_angle)
{
	ft_bzero(ray_info, sizeof(t_cast));
	ray_info->ray_angle = ray_angle;
	ray_info->ray_down = ray_angle > 0 && ray_angle < PI;
	ray_info->ray_up = !ray_info->ray_down;
	ray_info->ray_right = ray_angle < 0.5 * PI || ray_angle > 1.5 * PI;
	ray_info->ray_left = !ray_info->ray_right;
	return ;
}

static void	cast_one_ray(t_game *game, double ray_angle, int win_x)
{
	t_cast	ray_info;

	normalize_angle(&ray_angle);
	init_ray_info(&ray_info, ray_angle);
	ray_info.horz_wallhit = horz_grid_intersection(game, &ray_info);
	ray_info.vert_wallhit = vert_grid_intersection(game, &ray_info);
	calc_and_choose_smallest(game, &ray_info, win_x);
	return ;
}

void		cast_rays(t_game *game)
{
	int		win_x;
	double	ray_angle;
	double	angle_center_to_ray;

	win_x = 0;
	while (win_x < game->win.width)
	{
		angle_center_to_ray = atan((win_x - game->win.width / 2)
									/ game->win.dist_prj_plane);
		ray_angle = game->player.rotation_angle + angle_center_to_ray;
		cast_one_ray(game, ray_angle, win_x);
		win_x++;
	}
	return ;
}
