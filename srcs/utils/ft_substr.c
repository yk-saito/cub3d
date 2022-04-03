/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:33:02 by ysaito            #+#    #+#             */
/*   Updated: 2020/10/30 14:46:27 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*ft_substr(char *str, int start, int end)
{
	char	*newstr;
	int		strlen;

	if (str == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	if (start > strlen || end <= 0)
		return (ft_strdup(""));
	newstr = malloc(sizeof(char) * (end + 1));
	if (newstr == NULL)
		return (NULL);
	while (start < end)
	{
		newstr[start] = str[start];
		start++;
	}
	newstr[start] = '\0';
	return (newstr);
}
