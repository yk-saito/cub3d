/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:48:57 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 16:19:08 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_display(t_game *game)
{
	if (game->win.win != NULL)
	{
		mlx_destroy_window(game->mlx, game->win.win);
		game->win.win = NULL;
	}
	if (game->mlx != NULL)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
}
