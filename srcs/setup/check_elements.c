/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 21:13:04 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/26 15:38:23 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

static void	check_window_size(t_game *game, char **info, t_count *count)
{
	int	num;

	num = 0;
	while (info[num] != NULL)
	{
		num++;
	}
	if (num != 3)
		return ;
	count->win_size += 1;
	game->win.width = ft_atoi_cub(info[1]);
	game->win.height = ft_atoi_cub(info[2]);
	if (game->win.width <= 0 || game->win.height <= 0)
		count->win_size += 1;
}

static void	check_texture_path(t_game *game, char *element,
							char *info_path, t_count *count)
{
	if (ft_strncmp(element, "NO", 3) == 0)
		save_texture_path(game, info_path, &count->no, 0);
	else if (ft_strncmp(element, "SO", 3) == 0)
		save_texture_path(game, info_path, &count->so, 1);
	else if (ft_strncmp(element, "WE", 3) == 0)
		save_texture_path(game, info_path, &count->we, 2);
	else if (ft_strncmp(element, "EA", 3) == 0)
		save_texture_path(game, info_path, &count->ea, 3);
	else if (ft_strncmp(element, "S", 2) == 0)
		save_texture_path(game, info_path, &count->sp, 4);
	else
		count->char_err += 1;
}

static void	check_color(t_game *game, char *key,
						char **info_color, t_count *count)
{
	char	**split_color;
	int		num;
	int		r;
	int		g;
	int		b;

	split_color = ft_split(*info_color, ',');
	num = 0;
	while (split_color[num] != NULL)
		num++;
	if (num != 3)
	{
		free_double_array(split_color);
		return ;
	}
	set_check_color(split_color, &r, &g, &b);
	free_double_array(split_color);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return ;
	if (ft_strncmp(key, "F", 1) == 0)
		set_color(&game->color.floor, create_trgb(0, r, g, b), &count->f);
	else
		set_color(&game->color.ceiling, create_trgb(0, r, g, b), &count->c);
}

static void	check_info(t_game *game, char **info, t_count *count)
{
	int num;

	num = 0;
	while (info[num] != NULL)
	{
		num++;
	}
	if (ft_strncmp(info[0], "R", 2) == 0)
		check_window_size(game, info, count);
	else if ((ft_strlen(info[0]) == 2
			|| ft_strncmp(info[0], "S", 2) == 0)
			&& num == 2)
		check_texture_path(game, info[0], info[1], count);
	else if ((ft_strncmp(info[0], "F", 2) == 0
			|| ft_strncmp(info[0], "C", 2) == 0)
			&& num == 2)
		check_color(game, info[0], &info[1], count);
	else
		count->char_err += 1;
}

void		check_elements(t_game *game, t_list *scene, t_count *count)
{
	char	**info;

	while (scene->next != NULL)
	{
		game->map.start_row += 1;
		if (ft_strlen(scene->info) != 0)
		{
			info = ft_split(scene->info, ' ');
			if (info[0][0] == '0' || info[0][0] == '1' || info[0][0] == '2')
			{
				free_double_array(info);
				break ;
			}
			check_info(game, info, count);
			free_double_array(info);
		}
		scene = scene->next;
	}
}
