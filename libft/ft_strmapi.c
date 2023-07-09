/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 00:01:37 by ccur              #+#    #+#             */
/*   Updated: 2023/07/10 00:01:37 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *result;
	size_t  len;
    size_t  i;

    len = ft_strlen(s);

	if (!s || !f)
		return NULL;
    result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return NULL;

	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return result;
}