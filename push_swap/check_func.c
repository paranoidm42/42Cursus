/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:45:49 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 16:48:53 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_sstrlen(char **s)
{
	int	lenght;

	lenght = 0;
	if (!s)
		return (0);
	lenght = 0;
	while (s[lenght])
		lenght++;
	return (lenght);
}

int	ft_check_limits(char **argv)
{
	int				i;
	long long int	res;

	res = 0;
	i = 0;
	while (argv[i])
	{
		res = ft_atoi_long(argv[i]);
		if (res < -2147483648 || res > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_duplicate(int *argv, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < len)
	{
		while (j < len)
		{
			if (argv[i] == argv[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}
