/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 12:05:35 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/18 16:01:51 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	if (dst == NULL && src == NULL)
	{
		return (dst);
	}
	dp = dst;
	sp = src;
	while (n-- > 0)
	{
		*dp++ = *sp++;
	}
	return (dst);
}
