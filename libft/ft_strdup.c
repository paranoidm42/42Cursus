/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 00:40:23 by ccur              #+#    #+#             */
/*   Updated: 2023/07/07 00:40:23 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*strdup;
	size_t	len;

	len = ft_strlen(str);
	strdup = (char *)malloc(len + 1);
	if (!(strdup))
	{
		return (NULL);
	}
	ft_memcpy(strdup, str, len + 1);
	return (strdup);
}
