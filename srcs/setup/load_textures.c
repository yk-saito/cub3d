/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 22:00:14 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 02:18:47 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

void	load_textures(t_game *game, t_list *scene)
{
	int	i;

	i = 0;
	while (i < NUM_TEXTURES)
	{
		game->textures[i].img = mlx_xpm_file_to_image(game->mlx,
													game->textures[i].path,
													&game->textures[i].width,
													&game->textures[i].height);
		if (game->textures[i].img == NULL)
		{
			lst_free(scene);
			setup_error_exit(game, ERR_ROAD_TEXS);
		}
		game->textures[i].addr = (int *)mlx_get_data_addr(game->textures[i].img,
												&game->textures[i].bpp,
												&game->textures[i].line_len,
												&game->textures[i].endian);
		if (game->textures[i].addr == NULL)
		{
			lst_free(scene);
			setup_error_exit(game, ERR_ROAD_TEXS);
		}
		i++;
	}
}
