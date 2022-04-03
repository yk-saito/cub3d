/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cubfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 14:11:03 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 19:59:03 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

static t_list	*lst_new(void)
{
	t_list	*newlst;

	newlst = malloc(sizeof(t_list));
	if (newlst == NULL)
		return (NULL);
	ft_bzero(newlst, sizeof(t_list));
	return (newlst);
}

static t_list	*lst_add(t_list *scene, char *oneline)
{
	while (scene->next != NULL)
	{
		scene = scene->next;
	}
	scene->next = lst_new();
	if (scene->next == NULL)
		return (NULL);
	scene->info = oneline;
	return (scene);
}

static t_list	*save_get_line(int fd)
{
	t_list	*scene;
	char	*get_line;
	int		rc;

	scene = lst_new();
	if (scene == NULL)
		error_exit(ERR_NEW_LIST);
	while (1)
	{
		rc = get_next_line(fd, &get_line);
		if (rc == 0 && ft_strlen(get_line) == 0)
			break ;
		if (rc == -1 || (lst_add(scene, ft_strdup(get_line)) == NULL))
		{
			free(get_line);
			lst_free(scene);
			error_exit(ERR_READ_FILE);
		}
		if (rc == 0)
			break ;
		free(get_line);
	}
	free(get_line);
	return (scene);
}

t_list			*read_cubfile(char *file_path)
{
	t_list	*scene;
	int		fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit(ERR_OPEN_FILE);
	scene = save_get_line(fd);
	close(fd);
	return (scene);
}
