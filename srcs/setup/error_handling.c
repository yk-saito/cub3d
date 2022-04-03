/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 03:17:18 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:45:12 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

void	error_handling(t_game *game, char *errfmt,
						char **map, t_lst_sp *sprite_info)
{
	if (map != NULL)
		free_double_array(map);
	if (sprite_info != NULL)
		lst_sp_free(sprite_info);
	setup_error_exit(game, errfmt);
}
