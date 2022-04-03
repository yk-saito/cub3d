/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:47:01 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 11:47:50 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_sprite	*init_sprite(int num_sprites)
{
	t_sprite	*new_sprites;

	new_sprites = malloc(sizeof(t_sprite) * (num_sprites + 1));
	if (new_sprites == NULL)
		return (NULL);
	ft_bzero(new_sprites, (sizeof(t_sprite) * (num_sprites + 1)));
	return (new_sprites);
}
