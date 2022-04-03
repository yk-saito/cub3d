/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:29:11 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 03:14:01 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "utils.h"

static unsigned int		get_color_to_put(t_game *game, int data_x, int data_y)
{
	unsigned int	color;

	color =
	*((unsigned int *)(game->img.addr + data_y * game->img.line_len) + data_x);
	return (color);
}

static unsigned char	get_setting_value(unsigned int color, char *trgb)
{
	if (ft_strncmp(trgb, "blue", 4) == 0)
		return (color);
	else if (ft_strncmp(trgb, "green", 5) == 0)
		return (color >> 8);
	else if (ft_strncmp(trgb, "red", 3) == 0)
		return (color >> 16);
	else
		return (color >> 24);
}

void					set_pixel(t_game *game, int width_in_bytes, int fd)
{
	unsigned char	*bmp_line_data;
	int				bmp_x;
	int				bmp_y;
	unsigned int	color;

	if (!(bmp_line_data = malloc(width_in_bytes)))
		setup_error_exit(game, ERR_MALLOC);
	bmp_y = (game->win.height);
	while (--bmp_y >= 0)
	{
		ft_bzero(bmp_line_data, width_in_bytes);
		bmp_x = 0;
		while (bmp_x < game->win.width)
		{
			color = get_color_to_put(game, bmp_x, bmp_y);
			bmp_line_data[bmp_x * 4] = get_setting_value(color, "blue");
			bmp_line_data[bmp_x * 4 + 1] = get_setting_value(color, "green");
			bmp_line_data[bmp_x * 4 + 2] = get_setting_value(color, "red");
			bmp_line_data[bmp_x * 4 + 3] = get_setting_value(color, "trans");
			bmp_x++;
		}
		write(fd, (char*)bmp_line_data, width_in_bytes);
	}
	free(bmp_line_data);
	bmp_line_data = NULL;
}
