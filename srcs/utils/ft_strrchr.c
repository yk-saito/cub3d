/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 14:58:00 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/22 20:41:46 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char		*ft_strrchr(char *s, int c)
{
	char	ch;
	int		slen;

	ch = c;
	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (s[slen] == ch)
		{
			return ((char *)(s + slen));
		}
		slen--;
	}
	return (NULL);
}
