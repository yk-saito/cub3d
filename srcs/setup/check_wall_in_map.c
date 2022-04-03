/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:01:21 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:45:12 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

static void	check_wall_around_player(t_game *game, char **check_map,
									int i, int j)
{
	if (i < 0 || i >= game->map.num_row_max
		|| j < 0 || j >= game->map.num_col_max
		|| check_map[i][j] == '1')
	{
		return ;
	}
	if (check_map[i][j] == 'x')
		return ;
	if (check_map[i][j] == '#')
	{
		game->map.out_flag += 1;
		return ;
	}
	else
		check_map[i][j] = 'x';
	check_wall_around_player(game, check_map, i + 1, j);
	check_wall_around_player(game, check_map, i - 1, j);
	check_wall_around_player(game, check_map, i, j + 1);
	check_wall_around_player(game, check_map, i, j - 1);
}

static char	**make_outer_frame(char **check_map, int check_map_w,
							int check_map_h)
{
	int i;
	int j;

	i = 0;
	while (i < check_map_h)
	{
		j = 0;
		check_map[i] = malloc(sizeof(char *) * check_map_w + 1);
		ft_bzero(check_map[i], check_map_w);
		while (j < check_map_w)
		{
			if (j == 0 || j == (check_map_w - 1)
				|| i == 0 || i == (check_map_h - 1))
				check_map[i][j] = '#';
			else
				check_map[i][j] = ' ';
			j++;
		}
		check_map[i][j] = '\0';
		i++;
	}
	check_map[i] = NULL;
	return (check_map);
}

static char	**make_map_for_checking(char **map, int check_map_w,
								int check_map_h)
{
	char	**check_map;
	int		i;
	int		j;

	check_map = malloc(sizeof(char *) * (check_map_h + 1));
	if (check_map == NULL)
		return (NULL);
	check_map = make_outer_frame(check_map, check_map_w, check_map_h);
	if (check_map == NULL)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			check_map[i + 1][j + 1] = map[i][j];
			j++;
		}
		i++;
	}
	return (check_map);
}

void		check_wall_in_map(t_game *game, char **map,
							int player_x, int player_y)
{
	char	**check_map;

	game->map.num_col_max += 2;
	game->map.num_row_max = (game->map.end_row - game->map.start_row + 2);
	check_map = make_map_for_checking(map, game->map.num_col_max,
									game->map.num_row_max);
	if (check_map == NULL)
		error_handling(game, ERR_MALLOC, map, NULL);
	check_wall_around_player(game, check_map, player_y, player_x);
	if (game->map.out_flag)
	{
		free_double_array(check_map);
		error_handling(game, ERR_MAP_WALL, map, NULL);
	}
	free_double_array(check_map);
	game->map.map = make_map_for_checking(map, game->map.num_col_max,
										game->map.num_row_max);
	if (game->map.map == NULL)
		error_handling(game, ERR_MALLOC, map, NULL);
}
