/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:43:56 by ccur              #+#    #+#             */
/*   Updated: 2023/12/10 10:43:56 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sys/time.h"
#include <unistd.h>

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	else
		return (0);
}

long	ft_atoi_long(const char *argv)
{
	long	res;
	long	sig;

	res = 0;
	sig = 1;
	while (ft_isspace(*argv))
		argv++;
	if (*argv == '-' || *argv == '+')
	{
		if (*argv == '-')
			sig = -1;
		argv++;
	}
	while (ft_isdigit(*argv))
	{
		res = res * 10 + (*argv - '0');
		argv++;
	}
	return (res * sig);
}

long long	timestamp(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	ft_usleep(int ms)
{
	long long int	time;

	time = timestamp();
	while (timestamp() - time < ms)
		usleep(ms / 10);
}
