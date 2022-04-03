/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_sp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 02:00:21 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 02:02:06 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "setup.h"
#include "utils.h"

t_lst_sp	*lst_sp_new(void)
{
	t_lst_sp	*newlst_sp;

	newlst_sp = malloc(sizeof(t_lst_sp));
	if (newlst_sp == NULL)
	{
		return (NULL);
	}
	ft_bzero(newlst_sp, sizeof(t_lst_sp));
	return (newlst_sp);
}

t_lst_sp	*lst_sp_add(t_lst_sp *sp_info, int i, int j)
{
	while (sp_info->next != NULL)
	{
		sp_info = sp_info->next;
	}
	sp_info->next = lst_sp_new();
	if (sp_info->next == NULL)
		return (NULL);
	sp_info->x = j;
	sp_info->y = i;
	return (sp_info);
}

void		lst_sp_free(t_lst_sp *sprite_info)
{
	t_lst_sp	*temp;

	while (sprite_info->next != NULL)
	{
		temp = sprite_info;
		sprite_info = sprite_info->next;
		free(temp);
		temp = NULL;
	}
	free(sprite_info);
	sprite_info = NULL;
	return ;
}
