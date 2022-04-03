/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horz_grid_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 18:19:30 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:31:08 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"
#include "map.h"

static void	find_intersection(t_game *game, t_cast *ray_info)
{
	double	dist_p_to_intery;

	ray_info->intercept_y = floor(game->player.y / TILE_SIZE) * TILE_SIZE;
	ray_info->intercept_y += ray_info->ray_down ? TILE_SIZE : 0;
	dist_p_to_intery = (ray_info->intercept_y - game->player.y);
	ray_info->intercept_x =
	game->player.x + dist_p_to_intery / tan(ray_info->ray_angle);
}

static void	calc_increment_step(t_cast *ray_info, t_grid *grid)
{
	ray_info->step_y = TILE_SIZE;
	ray_info->step_y *= ray_info->ray_up ? -1 : 1;
	ray_info->step_x = TILE_SIZE / tan(ray_info->ray_angle);
	ray_info->step_x *= (ray_info->ray_left && ray_info->step_x > 0) ? -1 : 1;
	ray_info->step_x *= (ray_info->ray_right && ray_info->step_x < 0) ? -1 : 1;
	grid->next_x = ray_info->intercept_x;
	grid->next_y = ray_info->intercept_y;
}

static void	save_hit_info(t_game *game, t_cast *ray_info, t_grid *grid)
{
	int	map_x;
	int	map_y;

	map_x = (int)floor(grid->check_y / TILE_SIZE);
	map_y = (int)floor(grid->check_x / TILE_SIZE);
	ray_info->horz_hit_x = grid->next_x;
	ray_info->horz_hit_y = grid->next_y;
	ray_info->horz_content = get_map_at(&game->map, map_x, map_y);
}

int			horz_grid_intersection(t_game *game, t_cast *ray_info)
{
	t_grid	grid;

	ft_bzero(&grid, sizeof(t_grid));
	find_intersection(game, ray_info);
	calc_increment_step(ray_info, &grid);
	while (is_inside_map(game, grid.next_x, grid.next_y))
	{
		grid.check_x = grid.next_x;
		grid.check_y = grid.next_y + (ray_info->ray_up ? -1 : 0);
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
