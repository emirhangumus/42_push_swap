/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_extended.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egumus <egumus@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:21:05 by egumus            #+#    #+#             */
/*   Updated: 2023/12/17 18:56:29 by egumus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	check_before_apply(int res, int sign, int c)
{
	if (sign == 1 && (res > 2147483647 / 10
			|| (res == 2147483647 / 10 && c - '0' > 7)))
		return (0);
	if (sign == -1 && (res > 2147483648 / 10
			|| (res == 2147483648 / 10 && c - '0' > 8)))
		return (0);
	return (1);
}

int	ft_atoi_extended(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		++i;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		++i;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		if (!check_before_apply(res, sign, nptr[i]))
			return (0);
		res = res * 10 + (nptr[i] - '0');
		++i;
	}
	return (sign * res);
}
