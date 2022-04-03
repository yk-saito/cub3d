/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:49:38 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 15:52:08 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "event.h"
#include "utils.h"
#include "setup.h"

int		set_exit_flag(t_game *game)
{
	game->flag.exit = 1;
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.walk_direction = 0;
	if (keycode == KEY_S)
		game->player.walk_direction = 0;
	if (keycode == KEY_D)
	{
		game->player.walk_direction = 0;
		game->player.side = 0;
	}
	if (keycode == KEY_A)
	{
		game->player.walk_direction = 0;
		game->player.side = 0;
	}
	if (keycode == KEY_LEFT)
		game->player.turn_direction = 0;
	if (keycode == KEY_RIGHT)
		game->player.turn_direction = 0;
	return (0);
}

int		key_press(int keycode, t_game *game)
{
	game->flag.update = 1;
	if (keycode == KEY_W)
		game->player.walk_direction = +1;
	if (keycode == KEY_S)
		game->player.walk_direction = -1;
	if (keycode == KEY_D)
	{
		game->player.walk_direction = +1;
		game->player.side += (PI / 2);
	}
	if (keycode == KEY_A)
	{
		game->player.walk_direction = -1;
		game->player.side += (PI / 2);
	}
	if (keycode == KEY_LEFT)
		game->player.turn_direction = -1;
	if (keycode == KEY_RIGHT)
		game->player.turn_direction = +1;
	if (keycode == KEY_ESC)
		game->flag.exit = 1;
	return (0);
}
