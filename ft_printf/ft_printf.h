/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:08:08 by ccur              #+#    #+#             */
/*   Updated: 2023/07/19 13:08:10 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int nb);
int	ft_putnbr_unsigned(unsigned int nb);
int	base(unsigned long long int k, char x);
int	ft_strlen(const char *s);
int	ft_printf(const char *s, ...);

#endif
