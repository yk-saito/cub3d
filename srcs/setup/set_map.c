/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:57:14 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 11:21:01 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

static int	get_map_size(t_game *game, t_list *scene)
{
	int	count;
	int	map_col_len;

	count = 0;
	while (count++ < game->map.start_row)
		scene = scene->next;
	while (scene->next != NULL)
	{
		count++;
		map_col_len = ft_strlen(scene->info);
		if (map_col_len == 0)
			return (1);
		if (game->map.num_col_max < map_col_len)
			game->map.num_col_max = map_col_len;
		scene = scene->next;
	}
	game->map.end_row = count;
	game->map.num_row_max = (game->map.end_row - game->map.start_row);
	if ((game->map.num_col_max * game->map.num_row_max) > MAP_SIZE_MAX)
		return (2);
	if (game->map.num_col_max == 0 || game->map.num_row_max == 0)
		return (3);
	return (0);
}

static void	send_errfmt_and_exit(t_game *game, int rc)
{
	if (rc == 1)
		error_handling(game, ERR_MULTI_MAP, NULL, NULL);
	if (rc == 2)
		error_handling(game, ERR_BIG_MAP, NULL, NULL);
	if (rc == 3)
		error_handling(game, ERR_NO_MAP, NULL, NULL);
}

char		**set_map(t_game *game, t_list *scene)
{
	char	**map;
	int		count;
	int		idx;
	int		rc;

	rc = get_map_size(game, scene);
	if (rc != 0)
	{
		lst_free(scene);
		send_errfmt_and_exit(game, rc);
	}
	count = 0;
	idx = 0;
	if (!(map = malloc(sizeof(char *) * (game->map.num_row_max + 1))))
		return (NULL);
	ft_bzero(map, (game->map.num_row_max + 1));
	while (count++ < (game->map.start_row - 1))
		scene = scene->next;
	while (count++ < game->map.end_row)
	{
		map[idx++] = ft_strdup(scene->info);
		scene = scene->next;
	}
	map[idx] = NULL;
	return (map);
}
