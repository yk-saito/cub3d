/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 22:54:42 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 11:58:59 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"

void		set_window(t_game *game)
{
	if (game->win.win == NULL)
	{
		game->win.win =
		mlx_new_window(game->mlx, game->win.width, game->win.height, "cub3D");
	}
	mlx_put_image_to_window(game->mlx, game->win.win, game->img.img, 0, 0);
}
