/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 21:59:50 by ccur              #+#    #+#             */
/*   Updated: 2023/10/04 17:00:41 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_push
{
	int		*a;
	int		*b;
	int		a_len;
	int		b_len;
	int		len;
	char	**swap;
}			t_push;

int			ft_check_argv(char **argv);
int			ft_check_limits(char **argv);
int			ft_check_duplicate(int *argv, int len);
int			ft_max(int *list, int len);
int			ft_min(int *list, int len);
int			ft_find_index(t_push *s, int ind);
int			ft_fill_list(t_push *s);
int			ft_check_sort_smal(int *str, int len);
int			ft_check_sort_big(int *str, int len);
int			ft_sstrlen(char **s);
long		ft_atoi_long(const char *argv);
void		ft_three_sort(t_push *s);
void		ft_five_sort(t_push *s);
int			ft_sort_small_b(t_push *s, int len);
void		ft_quicksort_3(t_push *s, int len);
void		p_ab(char c, t_push *s);
void		s_ab(char c, t_push *s);
void		r_ab(char c, t_push *s);
void		rr_ab(char c, t_push *s);
void		ss(t_push *s);
void		rr(t_push *s);
void		rrr(t_push *s);
void		ft_sort_int_tmp(int *tmp_stack, int size);
int			ft_get_middle(int *pivot, int *stack_a, int size);
int			ft_sort_small_b(t_push *s, int len);
int			ft_quick_a(t_push *s, int len, int count);
int			ft_quick_b(t_push *s, int len, int count);

#endif
