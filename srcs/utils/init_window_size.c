/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:49:50 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 11:50:06 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		init_window_size(t_game *game)
{
	int	get_size_x;
	int	get_size_y;

	mlx_get_screen_size(game->mlx, &get_size_x, &get_size_y);
	if (get_size_x < game->win.width)
		game->win.width = get_size_x;
	if (get_size_y < game->win.height)
		game->win.height = get_size_y;
	return ;
}
