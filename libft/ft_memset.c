/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@k1m14s08.42kocaeli.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 01:47:31 by ccur              #+#    #+#             */
/*   Updated: 2023/07/04 01:47:31 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *s, int c, size_t n) 
{
    size_t  i;
    char    *str;

    i = 0;
    str  = (char *)s;
    while (i < n)
    {
        str[i] = c;
        i++;
    }
    return (s); // işlem bittiğinde s'in başlangıç adresini dondürürüz ve bu adresi daha sonra başka bir pointera eşleyebiliriz.
}

/* 
Void pointer bir fonksiyon;
- Değer dondürebilir
- typecast (değişken türü değiştirme) yapılmazsa derleme hatası verir
*/ 