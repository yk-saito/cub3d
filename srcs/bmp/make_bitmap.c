/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 00:40:15 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 12:31:45 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "utils.h"

void	make_bitmap(t_game *game)
{
	int				fd;
	int				width_in_bytes;
	unsigned char	bmp_header[HEADER_SIZE];

	fd = open("cub3D.bmp", O_CREAT | O_WRONLY, 0666);
	if (fd < 0)
		setup_error_exit(game, ERR_OPEN_FILE);
	width_in_bytes = game->win.width * (BIT_COUNT / 8);
	set_header(game, bmp_header, width_in_bytes);
	write(fd, &bmp_header, HEADER_SIZE);
	set_pixel(game, width_in_bytes, fd);
	close(fd);
}
