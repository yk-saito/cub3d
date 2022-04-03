/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:29:01 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/05 23:22:53 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*ft_strdup(char *str)
{
	char	*newstr;
	int		strlen;
	int		i;

	if (str == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	newstr = malloc(sizeof(char) * (strlen + 1));
	if (newstr == NULL)
		return (NULL);
	ft_bzero(newstr, strlen + 1);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
