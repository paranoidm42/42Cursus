/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:03:22 by ccur              #+#    #+#             */
/*   Updated: 2023/07/07 23:03:22 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    if (!s1 || !s2)
        return NULL;
    char *result;
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    size_t totalLen = len1 + len2;

    result = (char *)malloc((totalLen + 1) * sizeof(char));
    if (!result)
        return NULL;

    char *temp = result;

    while (*s1)
        *temp++ = *s1++;

    while (*s2)
        *temp++ = *s2++;

    *temp = '\0';

    return result;
}