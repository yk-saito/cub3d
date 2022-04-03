/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:43:16 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 11:43:29 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_ray	*init_rays(t_game *game)
{
	t_ray	*new_rays;

	new_rays = malloc(sizeof(t_ray) * (game->win.width + 1));
	if (new_rays == NULL)
		return (NULL);
	ft_bzero(new_rays, (sizeof(t_ray) * (game->win.width + 1)));
	return (new_rays);
}
