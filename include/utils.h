/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:13:23 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 16:45:31 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/*
** get_next_line.c
*/
# define GNL_ERR	-1
# define GNL_EOF	0
# define GNL_READ	1

/*
** ft_atoi_cub.c
*/
# define INT_MAX	2147483647
# define INT_MIN	-2147483648

# include "cub3d.h"

int			ft_atoi_cub(char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isdigit(int c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		ft_putstr(char *s);
int			ft_strlen(char *s);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(char *s, int c);
char		*ft_strdup(char *str);
char		*ft_substr(char *str, int start, int end);
char		*ft_strjoin_and_free(char *s1, char *s2);
char		**ft_split(char const *s, char c);
int			get_next_line(int fd, char **line);

/*
**	init
*/
void		init_game(t_game *game);
void		init_game_loop(t_game *game, int save_flag);
void		init_img_addr(t_game *game, int color);
t_ray		*init_rays(t_game *game);
t_sprite	*init_sprite(int num_sprites);
void		init_window_size(t_game *game);

/*
** exit.c
*/
void		args_error_exit(char *errfmt);
void		error_exit(char *errfmt);
void		setup_error_exit(t_game *game, char *errfmt);
void		game_exit(t_game *game);

/*
** free
*/
void		free_display(t_game *game);
void		free_double_array(char **array);
void		free_game(t_game *game);
void		free_image(t_game *game);
void		free_rays(t_game *game);
void		free_sprites(t_sprite *sprites);
void		free_textures(t_game *game, t_texture *textures);

#endif
