/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:46:18 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 16:49:02 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	else
		return (0);
}

long	ft_atoi_long(const char *argv)
{
	long	res;
	long	sig;

	res = 0;
	sig = -1;
	while (ft_isspace(*argv))
		argv++;
	if (*argv == '-' || *argv == '+')
	{
		if (*argv == '-')
			sig = -1;
		argv++;
	}
	while (ft_isdigit(*argv))
	{
		res = res * 10 + (*argv - '0');
		argv++;
	}
	return (res * sig);
}
