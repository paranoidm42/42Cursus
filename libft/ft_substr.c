/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 22:26:11 by ccur              #+#    #+#             */
/*   Updated: 2023/07/07 22:26:11 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	char	*src;
    size_t slen;

	src = (char *)s;
    slen = ft_strlen(s);
	if (!src)
		return (NULL);
    if (start >= ft_strlen(slen))
    {
        str = (char *)malloc(sizeof(char));
        if (!str)
            return (NULL);
        *str = '\0';
    }
    else
    {
        if (slen - start < len )
            len = slen - start;
        str = (char *)malloc(sizeof(char));
        if (!str)
            return (NULL);
        ft_strlcpy(str, (char *)(s + start), len +1);
    }
    return (str);
}