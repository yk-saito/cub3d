/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 17:47:01 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 16:42:12 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	args_error_exit(char *errfmt)
{
	ft_putstr(ERR_HEADER);
	ft_putstr(errfmt);
	ft_putstr(ARGS_FORMAT);
	ft_putstr(ARGS_EX1);
	ft_putstr(ARGS_EX2);
	exit(EXIT_FAILURE);
}

void	error_exit(char *errfmt)
{
	ft_putstr(ERR_HEADER);
	ft_putstr(errfmt);
	exit(EXIT_FAILURE);
}

void	setup_error_exit(t_game *game, char *errfmt)
{
	free_game(game);
	ft_putstr(ERR_HEADER);
	ft_putstr(errfmt);
	exit(EXIT_FAILURE);
}

void	game_exit(t_game *game)
{
	free_game(game);
	exit(EXIT_SUCCESS);
}
