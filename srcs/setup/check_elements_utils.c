/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 13:32:18 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 21:57:29 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

void	save_texture_path(t_game *game, char *info_path,
						int *count, int idx)
{
	if (*count == 0)
	{
		game->textures[idx].path = ft_strdup(info_path);
		*count += 1;
		return ;
	}
	free(game->textures[idx].path);
	game->textures[idx].path = NULL;
	*count += 1;
}

void	set_check_color(char **color, int *r, int *g, int *b)
{
	*r = ft_atoi_cub(color[0]);
	*g = ft_atoi_cub(color[1]);
	*b = ft_atoi_cub(color[2]);
}

void	set_color(int *color, int set_color, int *count)
{
	*color = set_color;
	*count += 1;
	return ;
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		check_count(t_count *count)
{
	if (count->win_size != 1 || count->no != 1 || count->so != 1
		|| count->we != 1 || count->ea != 1 || count->sp != 1
		|| count->f != 1 || count->c != 1 || count->char_err != 0)
	{
		return (ERROR);
	}
	return (1);
}
