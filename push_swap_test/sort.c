/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:04:53 by ccur              #+#    #+#             */
/*   Updated: 2023/10/11 11:55:07 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_sort(t_push *s)
{
	if (ft_max(s->a, s->a_len) == 0)
		r_ab('a', s);
	else if (ft_max(s->a, s->a_len) == 1)
		rr_ab('a', s);
	else if (ft_max(s->a, s->a_len) == 2)
		s_ab('a', s);
	if (ft_check_sort_smal(s->a, s->a_len) == 0)
		s_ab('a', s);
}

void	ft_five_sort(t_push *s)
{
	int	mincount;
	int	i;

	i = -1;
	while (++i < 2)
	{
		mincount = ft_min(s->a, s->a_len - 1);
		while (s->a[0] != s->a[ft_min(s->a, s->a_len - 1)])
		{
			if (mincount <= 1)
				r_ab('a', s);
			else if (mincount == s->a_len / 2)
			{
				r_ab('a', s);
				s_ab('a', s);
			}
			else
				rr_ab('a', s);
		}
		p_ab('b', s);
	}
	ft_three_sort(s);
	while (--i >= 0)
		p_ab('a', s);
}

int	ft_quick_a(t_push *s, int len, int count)
{
	int	pivot;
	int	items;

	if (ft_check_sort_smal(s->a, s->a_len) == 1)
		return (1);
	items = len;
	if (len <= 3)
		return (ft_quicksort_3(s, len), 1);
	if (!ft_get_middle(&pivot, s->a, len))
		return (0);
	while (len != items / 2 + items % 2)
	{
		if (s->a[0] < pivot && (len--))
			p_ab('b', s);
		else if (++count)
			r_ab('a', s);
	}
	while (items / 2 + items % 2 != s->a_len && count--)
		rr_ab('a', s);
	return (ft_quick_a(s, items / 2 + items % 2, 0) && ft_quick_b(s, items / 2,
			0));
	return (1);
}

int	ft_quick_b(t_push *s, int len, int count)
{
	int	pivot;
	int	items;

	if (!count && ft_check_sort_big(s->b, s->b_len) == 1)
		while (len--)
			p_ab('a', s);
	if (len <= 3)
		return (ft_sort_small_b(s, len), 1);
	items = len;
	if (!ft_get_middle(&pivot, s->b, len))
		return (0);
	while (len != items / 2)
	{
		if (s->b[0] >= pivot && (len--))
			p_ab('a', s);
		else if (++count)
			r_ab('b', s);
	}
	while (items / 2 != s->b_len && count--)
		rr_ab('b', s);
	return (ft_quick_a(s, items / 2 + items % 2, 0) && ft_quick_b(s, items / 2,
			0));
}
