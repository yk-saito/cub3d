/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 20:23:07 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 21:11:03 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

void	lst_free(t_list *scene)
{
	t_list	*temp;

	while (scene != NULL)
	{
		temp = scene->next;
		free(scene->info);
		free(scene);
		scene = temp;
	}
}

void	setup_scene(t_game *game, char *file_path)
{
	t_list	*scene;
	t_count count;
	char	**map;

	ft_bzero(&count, sizeof(t_count));
	scene = read_cubfile(file_path);
	check_elements(game, scene, &count);
	if (check_count(&count) == ERROR)
	{
		lst_free(scene);
		choose_errfmt_and_exit(game, &count);
	}
	load_textures(game, scene);
	map = set_map(game, scene);
	lst_free(scene);
	if (map == NULL)
		setup_error_exit(game, ERR_MALLOC);
	check_char_in_map(game, map);
	check_sprite_in_map(game, map);
	check_wall_in_map(game, map, game->player.x, game->player.y);
	free_double_array(map);
}
