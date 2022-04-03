/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:11:23 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/22 20:38:26 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

static void	check_save(char *argmnt)
{
	int	len;

	len = ft_strlen(argmnt);
	if (len < 6 || len > 6
		|| ft_strncmp(argmnt, "--save", ft_strlen(argmnt)) != 0)
	{
		args_error_exit(ERR_ARGMNT_SAVE);
	}
}

static void	check_filename(char *filename)
{
	char	*find;

	find = ft_strrchr(filename, '.');
	if (find == NULL
		|| ft_strlen(find) != 4
		|| ft_strncmp(find, ".cub", ft_strlen(find)) != 0)
	{
		args_error_exit(ERR_FILE_NAME);
	}
}

void		check_args(int argc, char *argv[], int *save_flag)
{
	if (argc < 2 || argc > 3 || argv == NULL)
		args_error_exit(ERR_NUM_OF_ARGS);
	check_filename(argv[1]);
	if (argc == 3)
	{
		check_save(argv[2]);
		*save_flag = 1;
	}
}
