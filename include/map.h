/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 00:13:53 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 14:38:07 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

bool	map_has_wall_at(t_game *game, double x, double y);
bool	map_has_sprite_at(t_game *game, double x, double y);
int		get_map_at(t_map *map, int i, int j);
bool	is_inside_map(t_game *game, double x, double y);
int		get_minimap_wallcolor(t_map *map, int x, int y);

#endif
