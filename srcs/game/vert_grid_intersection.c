/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection_vert_grid.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:20:21 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:30:02 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"
#include "map.h"

static void	find_intersection(t_game *game, t_cast *ray_info)
{
	double	dist_p_to_interx;

	ray_info->intercept_x = floor(game->player.x / TILE_SIZE) * TILE_SIZE;
	ray_info->intercept_x += ray_info->ray_right ? TILE_SIZE : 0;
	dist_p_to_interx = (ray_info->intercept_x - game->player.x);
	ray_info->intercept_y =
	game->player.y + dist_p_to_interx * tan(ray_info->ray_angle);
}

static void	calc_increment_step(t_cast *ray_info, t_grid *grid)
{
	ray_info->step_x = TILE_SIZE;
	ray_info->step_x *= ray_info->ray_left ? -1 : 1;
	ray_info->step_y = TILE_SIZE * tan(ray_info->ray_angle);
	ray_info->step_y *= (ray_info->ray_up && ray_info->step_y > 0) ? -1 : 1;
	ray_info->step_y *= (ray_info->ray_down && ray_info->step_y < 0) ? -1 : 1;
	grid->next_x = ray_info->intercept_x;
	grid->next_y = ray_info->intercept_y;
}

static void	save_hit_info(t_game *game, t_cast *ray_info, t_grid *grid)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(grid->check_y / TILE_SIZE);
	map_y = (int)floor(grid->check_x / TILE_SIZE);
	ray_info->vert_hit_x = grid->next_x;
	ray_info->vert_hit_y = grid->next_y;
	ray_info->vert_content = get_map_at(&game->map, map_x, map_y);
}

int			vert_grid_intersection(t_game *game, t_cast *ray_info)
{
	t_grid grid;

	ft_bzero(&grid, sizeof(t_grid));
	find_intersection(game, ray_info);
	calc_increment_step(ray_info, &grid);
	while (is_inside_map(game, grid.next_x, grid.next_y))
	{
		grid.check_x = grid.next_x + (ray_info->ray_left ? -1 : 0);
		grid.check_y = grid.next_y;
		if (map_has_wall_at(game, grid.check_x, grid.check_y))
		{
			save_hit_info(game, ray_info, &grid);
			return (1);
		}
		grid.next_x += ray_info->step_x;
		grid.next_y += ray_info->step_y;
	}
	return (0);
}
