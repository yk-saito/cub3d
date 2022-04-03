/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_errfmt_and_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:54:27 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 22:02:06 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

void	choose_errfmt_and_exit(t_game *game, t_count *count)
{
	if (count->win_size != 1)
		setup_error_exit(game, ERR_COUNT_WIN);
	if (count->no != 1)
		setup_error_exit(game, ERR_COUNT_NORTH);
	if (count->so != 1)
		setup_error_exit(game, ERR_COUNT_SORTH);
	if (count->we != 1)
		setup_error_exit(game, ERR_COUNT_WEST);
	if (count->ea != 1)
		setup_error_exit(game, ERR_COUNT_EAST);
	if (count->sp != 1)
		setup_error_exit(game, ERR_COUNT_SPRITE);
	if (count->f != 1)
		setup_error_exit(game, ERR_COUNT_F);
	if (count->c != 1)
		setup_error_exit(game, ERR_COUNT_C);
	if (count->char_err != 0)
		setup_error_exit(game, ERR_CHAR);
}
