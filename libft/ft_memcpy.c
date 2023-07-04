/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 23:12:38 by ccur              #+#    #+#             */
/*   Updated: 2023/07/04 23:12:38 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char   *d;
	unsigned char   *s;

    if (!dst && !src)
	    return (NULL);

	d = (char *)dst;
	s = (char *)src;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dst);
}