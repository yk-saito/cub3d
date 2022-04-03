/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:51:20 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:51:31 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_textures(t_game *game, t_texture *textures)
{
	int	idx;

	idx = 0;
	while (idx < NUM_TEXTURES)
	{
		if ((textures[idx].img != NULL))
		{
			mlx_destroy_image(game->mlx, textures[idx].img);
			textures[idx].img = NULL;
		}
		if ((textures[idx].path) != NULL)
		{
			free(textures[idx].path);
			textures[idx].path = NULL;
		}
		idx++;
	}
	return ;
}
