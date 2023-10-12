/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:45:22 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 16:48:38 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_fill_list(t_push *s)
{
	int	i;

	i = 0;
	s->b_len = 0;
	s->a_len = s->len;
	while (s->swap[i])
	{
		s->a[i] = ft_atoi(s->swap[i]);
		i++;
	}
	return (1);
}

int	ft_check_sort_smal(int *str, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (str[i - 1] > str[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_sort_big(int *str, int len)
{
	int	i;

	i = 1;
	while (i < len)
	{
		if (str[i - 1] < str[i])
			return (0);
		i++;
	}
	return (1);
}
