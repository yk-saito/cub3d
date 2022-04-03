/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 22:07:14 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 02:27:28 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# define FILE_HEADER_SIZE	14
# define CORE_HEADER_SIZE	12
# define HEADER_SIZE		26
# define BIT_COUNT			32

/*
** BITMAPFILEHEADER
** {
**    unsigned int    file type;[2byte]='BM'
**    unsigned long   file size;[4byte]=[byte]
**    unsigned int    reserved1;[2byte]
**    unsigned int    reserved2;[2byte]
**    unsigned long   offset_bits;[4byte]
** }total[14byte]
*/
/*
** BITMAPCOREHEADER
** {
**     unsigned long   info header size;[4byte]=12
**     int             width;[2][int]=[pixel]
**     int             height;[2][int]=[pixel]
**     unsigned int    planes;[2][unsigned int]=always1
**     unsigned int    color bit_count;[2]=1,4,8,(16),24,32[bit]
** }total[12byte]
*/
/*
** [0][1]=type="BM"
** bmp_header[0] = 'B';
** bmp_header[1] = 'M';
**
** [2][3][4][5]=file_size=(HEADER_SIZE + (width_in_bytes * game->win.height)
** bmp_header[2] = 26;
** bmp_header[3] = 76;
** bmp_header[4] = 29;
** bmp_header[5] = 0;
**
** [6][7]=reserved1=0
** bmp_header[6] = 0;
** bmp_header[7] = 0;
**
** [8][9]=reserved2=0
** bmp_header[8] = 0;
** bmp_header[9] = 0;
**
** [10][11][12][13]=offset_bits=HEADER_SIZE=26
** bmp_header[10] = HEADER_SIZE;
** bmp_header[11] = 0;
** bmp_header[12] = 0;
** bmp_header[13] = 0;
**
** [14][15][16][17]=size=12
** bmp_header[14] = CORE_HEADER_SIZE;
** bmp_header[15] = 0;
** bmp_header[16] = 0;
** bmp_header[17] = 0;
**
** [18][19]=width=game->window.width=800
** bmp_header[18]= 32;
** bmp_header[19] = 3;
**
** [20][21]=height=gmae->window.height=400;
** bmp_header[20] = 144;
** bmp_header[21] = 1;
**
** [22][23]=planes=1
** bmp_header[22] = 1;
** bmp_header[23] = 0;
**
** [24][25]=bit_count=32
** bmp_header[24] = BIT_COUNT;
** bmp_header[25] = 0;
*/

# include "cub3d.h"

void	make_bitmap(t_game *game);
void	set_header(t_game *game, unsigned char *bmp_header, int width_in_bytes);
void	set_pixel(t_game *game, int width_in_bytes, int fd);

#endif
