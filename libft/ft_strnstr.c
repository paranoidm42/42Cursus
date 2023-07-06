/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:47:27 by ccur              #+#    #+#             */
/*   Updated: 2023/07/06 17:01:47 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (haystack == NULL)
		return (NULL);
	if (haystack == needle || n_len == 0)
		return ((char *)haystack);
	while (((char *)(haystack))[i] != '\0' && i < len)
	{
		i2 = 0;
		while (((char *)(haystack))[i + i2] != '\0' && needle[i2] != '\0'
			&& ((char *)(haystack))[i + i2] == needle[i2] && i + i2 < len)
		{
			i2++;
		}
		if (i2 == n_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
