/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 00:38:11 by ccur              #+#    #+#             */
/*   Updated: 2023/07/07 00:38:11 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*swp;

	swp = malloc(count * size);
	if (swp)
		ft_bzero(swp, count * size);
	return (swp);
}