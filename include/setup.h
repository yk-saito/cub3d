/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:52:36 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 21:58:24 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETUP_H
# define SETUP_H

# include "cub3d.h"

typedef struct		s_list
{
	char			*info;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst_sp
{
	int				x;
	int				y;
	struct s_lst_sp	*next;
}					t_lst_sp;

typedef struct		s_count
{
	int				win_size;
	int				no;
	int				so;
	int				we;
	int				ea;
	int				sp;
	int				f;
	int				c;
	int				char_err;
	int				map;
	int				map_err;
}					t_count;

typedef struct		s_path
{
	char			*tex;
}					t_path;

void				check_args(int argc, char *argv[], int *save_flag);
void				error_handling(t_game *game, char *errfmt,
								char **map, t_lst_sp *sprite_info);
void				choose_errfmt_and_exit(t_game *game, t_count *count);

/*
** setup_scene.c
*/
void				setup_scene(t_game *game, char *file_path);
t_list				*read_cubfile(char *file_path);
void				check_elements(t_game *game, t_list *scene, t_count *count);
void				load_textures(t_game *game, t_list *scene);
char				**set_map(t_game *game, t_list *scene);
void				check_char_in_map(t_game *game, char **map);
void				check_sprite_in_map(t_game *game, char **map);
void				check_wall_in_map(t_game *game, char **map,
									int player_x, int player_y);
void				lst_free(t_list *scene);

/*
** check_elements_utils.c
*/
void				save_texture_path(t_game *game, char *info_path,
									int *count, int idx);
void				set_check_color(char **color, int *r, int *g, int *b);
void				set_color(int *color, int set_color, int *flag);
int					create_trgb(int t, int r, int g, int b);
int					check_count(t_count *count);

/*
** lst_sp.c
*/
t_lst_sp			*lst_sp_new(void);
t_lst_sp			*lst_sp_add(t_lst_sp *sp_info, int i, int j);
void				lst_sp_free(t_lst_sp *sprite_info);

#endif
