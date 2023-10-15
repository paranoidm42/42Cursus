/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:45:45 by ccur              #+#    #+#             */
/*   Updated: 2023/10/15 19:20:37 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static int	check_all_arg(t_push *s)
{
	if (s->len == 0)
		return (0);
	else if (ft_check_argv(s->swap) == 0)
		return (0);
	else if (ft_check_limits(s->swap) == 0)
		return (0);
	if (ft_fill_list(s) == 0)
		return (0);
	if (ft_check_duplicate(s->a, s->a_len) == 0)
		return (0);
	return (1);
}

static int	ft_push_swap(t_push *s)
{
	s->b = malloc(sizeof(int) * s->len);
	if (!s->b)
		return (0);
	s->b_len = 0;
	s->a_len = s->len;
	if (s->len <= 3)
		ft_three_sort(s);
	else if (s->len <= 5)
		ft_five_sort(s);
	else
		ft_quick_a(s, s->a_len, 0);
	free(s->b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_push	s;

	argv++;
	s.swap = argv;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		s.swap = ft_split(*argv, ' ');
	s.len = ft_sstrlen(s.swap);
	s.a = malloc(sizeof(int) * s.len);
	if (!s.a)
		return (0);
	if (check_all_arg(&s) == 0)
	{
		free(s.a);
		ft_free(s.swap, s.len, argc);
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	if (ft_check_sort_smal(s.a, s.len) == 0)
		ft_push_swap(&s);
	free(s.a);
	ft_free(s.swap, s.len, argc);
	return (0);
}
