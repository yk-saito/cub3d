/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:57:33 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:44:25 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

bool	map_has_wall_at(t_game *game, double x, double y)
{
	int	map_grid_x;
	int	map_grid_y;

	map_grid_x = floor(x / TILE_SIZE);
	map_grid_y = floor(y / TILE_SIZE);
	if (map_grid_x < 0)
		map_grid_x = 0;
	else if (map_grid_x >= game->map.num_col_max)
		map_grid_x = (game->map.num_col_max - 1);
	if (map_grid_y < 0)
		map_grid_y = 0;
	else if (map_grid_y >= game->map.num_row_max)
		map_grid_y = (game->map.num_row_max - 1);
	if (game->map.map[map_grid_y][map_grid_x] == '1')
		return (true);
	else
		return (false);
}

bool	is_inside_map(t_game *game, double x, double y)
{
	if (x >= 0 && x <= game->map.num_col_max * TILE_SIZE
		&& y >= 0 && y <= game->map.num_row_max * TILE_SIZE)
	{
		return (true);
	}
	return (false);
}

int		get_map_at(t_map *map, int i, int j)
{
	return (map->map[i][j]);
}

bool	map_has_sprite_at(t_game *game, double x, double y)
{
	int	map_grid_x;
	int	map_grid_y;

	map_grid_x = floor(x / TILE_SIZE);
	map_grid_y = floor(y / TILE_SIZE);
	if (map_grid_x < 0)
		map_grid_x = 0;
	else if (map_grid_x >= game->map.num_col_max)
		map_grid_x = (game->map.num_col_max - 1);
	if (map_grid_y < 0)
		map_grid_y = 0;
	else if (map_grid_y >= game->map.num_row_max)
		map_grid_y = (game->map.num_row_max - 1);
	if (game->map.map[map_grid_y][map_grid_x] == '2')
		return (true);
	else
		return (false);
}
