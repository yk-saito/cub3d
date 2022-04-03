/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:27:51 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:45:31 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_img_addr(t_game *game, int color)
{
	int		x;
	int		y;
	char	*dst;

	x = 0;
	while (x < game->win.width)
	{
		y = 0;
		while (y < game->win.height)
		{
			dst = game->img.addr
					+ (y * game->img.line_len + x * (game->img.bpp / 8));
			*(unsigned int*)dst = color;
			y++;
		}
		x++;
	}
	return ;
}
