/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:43:00 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:46:09 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_game(t_game *game)
{
	free_textures(game, game->textures);
	free_sprites(game->sprites);
	free_rays(game);
	free_double_array(game->map.map);
	free_image(game);
	free_display(game);
}
