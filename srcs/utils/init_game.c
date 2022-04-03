/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:57:10 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:22:24 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_game(t_game *game)
{
	int idx;

	idx = 0;
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		setup_error_exit(game, ERR_INIT);
	while (idx < NUM_TEXTURES)
	{
		ft_bzero(&game->textures[idx], sizeof(t_texture));
		idx++;
	}
}
