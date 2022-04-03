/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysaito <ysaito@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 10:19:28 by ysaito            #+#    #+#             */
/*   Updated: 2020/11/25 01:22:30 by ysaito           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			ft_isspace(const char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n' \
	|| str[idx] == '\v' || str[idx] == '\f' || str[idx] == '\r')
	{
		idx++;
	}
	return (idx);
}

int			check_num(long num, char *str, int idx)
{
	while (str[idx] != '\0')
	{
		if (!(ft_isdigit(str[idx])))
		{
			return (0);
		}
		idx++;
	}
	if (num >= INT_MAX)
		return (INT_MAX);
	else
		return (INT_MIN);
}

int			check_char(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (!(ft_isdigit(str[idx])))
		{
			return (ERROR);
		}
		idx++;
	}
	return (1);
}

int			ft_atoi_cub(char *str)
{
	long	num;
	int		negative;
	int		i;

	num = 0;
	negative = 1;
	i = ft_isspace(str);
	if (check_char(str) == ERROR)
		return (-1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num * negative >= INT_MAX || num * negative <= INT_MIN)
			return (check_num((num * negative), str, i));
	}
	if (str[i] != '\0')
		return (0);
	return (num * negative);
}
