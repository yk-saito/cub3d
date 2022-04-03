/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 23:23:52 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/22 23:59:16 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bmp.h"
#include "utils.h"

static void
	set_littleendian(unsigned char *header, int value, int *idx, int num_byte)
{
	int	count;

	count = 0;
	while (count < num_byte)
	{
		header[*idx] = (unsigned char)(value >> (8 * count));
		*idx += 1;
		count++;
	}
}

void
	set_header(t_game *game, unsigned char *bmp_header, int width_in_bytes)
{
	unsigned int	file_size;
	int				idx;

	file_size = HEADER_SIZE + (width_in_bytes * game->win.height);
	width_in_bytes = game->win.width * (BIT_COUNT / 8);
	file_size = HEADER_SIZE + (width_in_bytes * game->win.height);
	idx = 0;
	ft_bzero(bmp_header, HEADER_SIZE);
	ft_memcpy(bmp_header, "BM", 2);
	idx += 2;
	set_littleendian(bmp_header, file_size, &idx, 4);
	set_littleendian(bmp_header, 0, &idx, 2);
	set_littleendian(bmp_header, 0, &idx, 2);
	set_littleendian(bmp_header, HEADER_SIZE, &idx, 4);
	set_littleendian(bmp_header, CORE_HEADER_SIZE, &idx, 4);
	set_littleendian(bmp_header, game->win.width, &idx, 2);
	set_littleendian(bmp_header, game->win.height, &idx, 2);
	set_littleendian(bmp_header, 1, &idx, 2);
	set_littleendian(bmp_header, BIT_COUNT, &idx, 2);
}
