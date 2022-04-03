/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 13:43:05 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/24 13:43:38 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	normalize_angle(double *angle)
{
	*angle = remainder(*angle, TWO_PI);
	if (*angle < 0)
	{
		*angle = TWO_PI + *angle;
	}
	return ;
}
