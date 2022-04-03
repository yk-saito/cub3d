/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 15:40:53 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 16:13:37 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"
#include "bmp.h"
#include "render.h"
#include "event.h"

int	game_hook(t_game *game)
{
	if (game->flag.exit)
		game_exit(game);
	if (game->flag.update)
	{
		mlx_do_sync(game->mlx);
		init_img_addr(game, 0x00000000);
		move_player(game);
		cast_rays(game);
		render_projection(game);
		render_sprite(game);
	}
	if (game->flag.save)
	{
		make_bitmap(game);
		game_exit(game);
	}
	game->flag.update = 0;
	set_window(game);
	return (0);
}
