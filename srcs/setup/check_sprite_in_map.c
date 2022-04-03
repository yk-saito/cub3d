/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprite_in_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:47:23 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 12:11:47 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

static void	set_sprites_info(t_game *game, t_lst_sp *sprite_info)
{
	int	idx;

	idx = 0;
	while (idx < game->map.sprite_flag)
	{
		game->sprites[idx].x = (sprite_info->x + 0.5) * TILE_SIZE;
		game->sprites[idx].y = (sprite_info->y + 0.5) * TILE_SIZE;
		sprite_info = sprite_info->next;
		idx++;
	}
}

void		check_sprite_in_map(t_game *game, char **map)
{
	t_lst_sp	*sprite_info;
	int			i;
	int			j;

	sprite_info = lst_sp_new();
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == '2')
			{
				game->map.sprite_flag += 1;
				if (lst_sp_add(sprite_info, (i + 1), (j + 1)) == NULL)
					error_handling(game, ERR_MALLOC, map, sprite_info);
			}
			j++;
		}
		i++;
	}
	if (!(game->sprites = init_sprite(game->map.sprite_flag)))
		error_handling(game, ERR_MALLOC, map, sprite_info);
	set_sprites_info(game, sprite_info);
	lst_sp_free(sprite_info);
}
