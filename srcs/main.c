/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 18:59:29 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/26 00:13:51 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "utils.h"
#include "setup.h"
#include "game.h"
#include "event.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		save_flag;

	save_flag = 0;
	check_args(argc, argv, &save_flag);
	init_game(&game);
	setup_scene(&game, argv[1]);
	init_game_loop(&game, save_flag);
	game_hook(&game);
	mlx_hook(game.win.win, KEY_PRESS_EVENT, 1 << 0, &key_press, &game);
	mlx_hook(game.win.win, KEY_RELEASE_EVENT, 1 << 1, &key_release, &game);
	mlx_hook(game.win.win, DESTROY_NTFY_EVENT, 1 << 17, &set_exit_flag, &game);
	mlx_loop_hook(game.mlx, &game_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
