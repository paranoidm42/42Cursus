/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:14:14 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 16:49:43 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ss(t_push *s)
{
	int	tmp;

	if (s->a_len > 1 && s->b_len > 1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
	ft_putstr_fd("ss\n", 1);
}

void	rr(t_push *s)
{
	int	i;
	int	swp;

	i = 0;
	swp = s->a[0];
	while (++i < s->a_len)
		s->a[i - 1] = s->a[i];
	s->a[s->a_len - 1] = swp;
	i = 0;
	swp = s->b[0];
	while (++i < s->b_len)
		s->b[i - 1] = s->b[i];
	s->b[s->a_len - 1] = swp;
	ft_putstr_fd("rr\n", 1);
}

void	rrr(t_push *s)
{
	int	i;
	int	swp;

	i = s->a_len;
	swp = s->a[s->a_len - 1];
	while (--i > 0)
		s->a[i] = s->a[i - 1];
	s->a[0] = swp;
	i = s->b_len;
	swp = s->b[s->b_len - 1];
	while (--i > 0)
		s->b[i] = s->b[i - 1];
	s->b[0] = swp;
	ft_putstr_fd("rrr\n", 1);
}
