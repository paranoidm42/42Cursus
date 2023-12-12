/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:37:45 by ccur              #+#    #+#             */
/*   Updated: 2023/12/10 10:37:45 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	check_arg(int ac, char **av)
{
	int				x;
	int				y;
	long long int	res;

	x = 0;
	if (ac < 5 || ac > 6)
		return (0);
	while (av[x])
	{
		y = 0;
		if (av[x][0] == '+')
			y++;
		while (av[x][y])
		{
			if (ft_isdigit(av[x][y]) == 0)
				return (printf("It is not number. "), 0);
			y++;
		}
		res = ft_atoi_long(av[x]);
		if (res > 2147483647 || res <= 0)
			return (printf("Number long. "), 0);
		x++;
	}
	return (1);
}

int	init_mutex(t_table *table)
{
	int	i;

	i = table->num_philo;
	table->forks = malloc(sizeof(pthread_mutex_t) * i);
	if (!table->forks)
		return (0);
	if (!free_all_mutex(table))
		return (0);
	while (--i >= 0)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			while (++i < table->num_philo)
				pthread_mutex_destroy(&table->forks[i]);
			pthread_mutex_destroy(&(table->m_die));
			pthread_mutex_destroy(&(table->m_meal));
			pthread_mutex_destroy(&(table->m_print));
			pthread_mutex_destroy(&(table->m_count_eat));
			return (0);
		}
	}
	return (1);
}

int	init_philo(t_table *table)
{
	int	i;

	i = table->num_philo;
	table->philo = malloc(sizeof(t_philo) * i);
	if (!table->philo)
		return (free(table->forks), 0);
	while (--i >= 0)
	{
		table->philo[i].num = i + 1;
		table->philo[i].num_eat = 0;
		table->philo[i].last_meal = 0;
		table->philo[i].r_fork = (i + 1) % table->num_philo;
		table->philo[i].l_fork = i;
		table->philo[i].table = table;
	}
	return (1);
}

int	parse(char **av, int ac, t_table *table)
{
	table->num_philo = (int)ft_atoi_long(av[0]);
	table->time_die = (int)ft_atoi_long(av[1]);
	table->time_eat = (int)ft_atoi_long(av[2]);
	table->time_slep = (int)ft_atoi_long(av[3]);
	table->philo_m_eat = -1;
	table->all_ate = 0;
	table->is_died = 0;
	if (ac == 6)
		table->philo_m_eat = (int)ft_atoi_long(av[4]);
	if (!init_mutex(table))
		return (0);
	if (init_philo(table) == 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	argv++;
	if (check_arg(argc, argv) == 0)
		return (printf("Argumants erorr!\n"), 0);
	if (parse(argv, argc, &table) == 0)
		return (printf("Define/init error!!"), 0);
	if (start_thread_main(&table) == 0)
		return (free(table.forks), printf("Thread Erorr!\n"), 0);
	return (1);
}
