/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:49:36 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 15:49:43 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_double_array(char **array)
{
	int	idx;

	if (array == NULL)
		return ;
	idx = 0;
	while (array[idx] != NULL)
	{
		free(array[idx]);
		array[idx] = NULL;
		idx++;
	}
	free(array);
	array = NULL;
}
