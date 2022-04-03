/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_loop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:37:26 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 16:24:29 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void			init_game_loop(t_game *game, int save_flag)
{
	init_window_size(game);
	game->img.img =
	mlx_new_image(game->mlx, game->win.width, game->win.height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
								&game->img.line_len, &game->img.endian);
	game->rays = init_rays(game);
	if (!(game->img.img) || !(game->img.addr) || !(game->rays))
		setup_error_exit(game, ERR_INIT);
	game->fov_angle = (ANGLE * (PI / HORZ_ANGLE));
	game->win.dist_prj_plane = ((game->win.width / 2)
								/ tan(game->fov_angle / 2));
	game->player.x = (game->player.x + 0.51) * TILE_SIZE;
	game->player.y = (game->player.y + 0.51) * TILE_SIZE;
	if (game->player.first_direction == 'N')
		game->player.rotation_angle = PI + (PI / 2);
	else if (game->player.first_direction == 'S')
		game->player.rotation_angle = PI / 2;
	else if (game->player.first_direction == 'W')
		game->player.rotation_angle = PI;
	else
		game->player.rotation_angle = 0;
	game->player.walk_speed = 2;
	game->player.turn_speed = 1 * (PI / 180);
	game->flag.save = save_flag;
	game->flag.update = 1;
}
