/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 14:30:18 by ccur              #+#    #+#             */
/*   Updated: 2023/07/10 14:37:01 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_fd(int n, int fd)
{
	if (nb == -2147483648)
	{
		write(1, '-', 1);
		write(1, '2', 1);
		ft_putnbr(147483648);
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', 1);
		nb = nb * -1;
		ft_putchar_fd(nb, 1);
	}
	else if (nb > 9)
	{
		ft_putchar_fd(nb / 10, 1);
		ft_putchar_fd(nb % 10, 1);
	}
	else
		ft_putchar_fd(nb +48, 1);
}
