/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char_in_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 16:51:37 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 21:10:52 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

static void	set_player_info(t_game *game, int i, int j, char direction)
{
	game->player.x += j;
	game->player.y += i;
	game->player.first_direction = direction;
}

void		check_char_in_map(t_game *game, char **map)
{
	int			i;
	int			j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr(" 012NSWE", map[i][j]) == NULL)
				error_handling(game, ERR_MAP_CHAR, map, NULL);
			if (ft_strchr("NSWE", map[i][j]))
			{
				game->map.player_flag += 1;
				set_player_info(game, (i + 1), (j + 1), map[i][j]);
			}
			j++;
		}
		i++;
	}
	if (game->map.player_flag != 1)
		error_handling(game, ERR_PLAYER, map, NULL);
}
