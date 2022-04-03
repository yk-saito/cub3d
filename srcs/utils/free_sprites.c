/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:50:49 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:51:08 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_sprites(t_sprite *sprites)
{
	if (sprites != NULL)
	{
		free(sprites);
		sprites = NULL;
	}
}
