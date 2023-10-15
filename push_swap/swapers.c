/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swapers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 22:19:12 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 16:49:46 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	s_ab(char c, t_push *s)
{
	int	tmp;

	if (c == 'a' && s->a_len > 1)
	{
		tmp = s->a[0];
		s->a[0] = s->a[1];
		s->a[1] = tmp;
	}
	else if (c == 'b' && s->b_len > 1)
	{
		tmp = s->b[0];
		s->b[0] = s->b[1];
		s->b[1] = tmp;
	}
	ft_putchar_fd('s', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

static int	len_update(t_push *s, char flag)
{
	if (flag == 'a')
	{
		s->b_len--;
		s->a_len++;
	}
	else
	{
		s->a_len--;
		s->b_len++;
	}
	return (-1);
}

void	p_ab(char c, t_push *s)
{
	int	i;

	if (c == 'a' && s->b_len > 0)
	{
		i = s->a_len + 1;
		while (--i > 0)
			s->a[i] = s->a[i - 1];
		s->a[0] = s->b[0];
		i = len_update(s, 'a');
		while (++i < s->b_len)
			s->b[i] = s->b[i + 1];
		ft_putstr_fd("pa\n", 1);
	}
	else if (c == 'b' && s->a_len > 0)
	{
		i = s->b_len + 1;
		while (--i > 0)
			s->b[i] = s->b[i - 1];
		s->b[0] = s->a[0];
		i = len_update(s, 'b');
		while (++i < s->a_len)
			s->a[i] = s->a[i + 1];
		ft_putstr_fd("pb\n", 1);
	}
}

void	r_ab(char c, t_push *s)
{
	int	i;
	int	swp;

	if (c == 'a')
	{
		i = -1;
		swp = s->a[0];
		while (++i < s->a_len)
			s->a[i - 1] = s->a[i];
		s->a[s->a_len - 1] = swp;
	}
	else if (c == 'b')
	{
		i = -1;
		swp = s->b[0];
		while (++i < s->b_len)
			s->b[i - 1] = s->b[i];
		s->b[s->b_len - 1] = swp;
	}
	ft_putchar_fd('r', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}

void	rr_ab(char c, t_push *s)
{
	int	i;
	int	swp;

	if (c == 'a')
	{
		i = s->a_len;
		swp = s->a[i - 1];
		while (--i > 0)
			s->a[i] = s->a[i - 1];
		s->a[0] = swp;
	}
	else if (c == 'b')
	{
		i = s->b_len;
		swp = s->b[i - 1];
		while (--i > 0)
			s->b[i] = s->b[i - 1];
		s->b[0] = swp;
	}
	ft_putstr_fd("rr", 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
}
