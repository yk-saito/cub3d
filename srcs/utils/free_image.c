/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:50:07 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:50:16 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_image(t_game *game)
{
	if (game->img.img != NULL)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		game->img.img = NULL;
	}
}
