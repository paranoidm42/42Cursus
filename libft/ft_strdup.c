/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 00:40:23 by ccur              #+#    #+#             */
/*   Updated: 2023/07/07 11:31:41 by ccur             ###   ########.fr       */
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
