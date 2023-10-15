/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:16:47 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 14:26:01 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_update(int num, t_push *s)
{
	p_ab('a', s);
	return (--num);
}

int	ft_sort_small_b(t_push *s, int len)
{
	if (len == 1)
		p_ab('a', s);
	else if (len == 2)
	{
		if (s->b[0] < s->b[1])
			s_ab('b', s);
		while (len--)
			p_ab('a', s);
	}
	else if (len == 3)
	{
		while (len || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 1 && s->a[0] > s->a[1])
				s_ab('a', s);
			else if (len == 1 || (len >= 2 && s->b[0] > s->b[1]) || (len == 3
					&& s->b[0] > s->b[2]))
				len = len_update(len, s);
			else
				s_ab('b', s);
		}
	}
	return (0);
}

void	ft_quicksort_3(t_push *s, int len)
{
	if (len == 3 && s->a_len == 3)
		ft_three_sort(s);
	else if (len == 2)
	{
		if (s->a[0] > s->a[1])
			s_ab('a', s);
	}
	else if (len == 3)
	{
		while (len != 3 || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (len == 3 && s->a[0] > s->a[1] && s->a[2])
				s_ab('a', s);
			else if (len == 3 && !(s->a[2] > s->a[0] && s->a[2] > s->a[1]))
			{
				p_ab('b', s);
				len--;
			}
			else if (s->a[0] > s->a[1])
				s_ab('a', s);
			else if (len++)
				p_ab('a', s);
		}
	}
}
