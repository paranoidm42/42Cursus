/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:26:12 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 14:32:18 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	ft_max(int *list, int len)
{
	int	i;
	int	max_value;
	int	max_index;

	i = 0;
	max_value = list[0];
	max_index = 0;
	while (i < len)
	{
		i++;
		if (list[i] > max_value)
		{
			max_value = list[i];
			max_index = i;
		}
	}
	return (max_index);
}

int	ft_min(int *list, int len)
{
	int	i;
	int	max_value;
	int	max_index;

	i = 0;
	max_value = list[0];
	max_index = 0;
	while (i < len)
	{
		i++;
		if (list[i] < max_value)
		{
			max_value = list[i];
			max_index = i;
		}
	}
	return (max_index);
}

int	ft_find_index(t_push *s, int ind)
{
	int	i;

	i = 0;
	while (i < s->a_len)
	{
		if (ind <= s->a[i])
			return (i);
		i++;
	}
	return (i);
}

int	ft_get_middle(int *pivot, int *stack_a, int size)
{
	int	i;
	int	*tmp;

	tmp = (int *)malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp[i] = stack_a[i];
		i++;
	}
	ft_sort_int_tmp(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}

void	ft_sort_int_tmp(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
