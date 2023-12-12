/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:37:38 by ccur              #+#    #+#             */
/*   Updated: 2023/12/12 11:28:23 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	exit_launcher(t_table *t, t_philo *p)
{
	int	i;

	i = -1;
	while (++i < t->num_philo)
		pthread_join(p[i].t_num, NULL);
	i = -1;
	while (++i < t->num_philo)
		pthread_mutex_destroy(&t->forks[i]);
	pthread_mutex_destroy(&(t->m_count_eat));
	pthread_mutex_destroy(&(t->m_die));
	pthread_mutex_destroy(&(t->m_meal));
	pthread_mutex_destroy(&(t->m_print));
	free(t->forks);
	free(t->philo);
}

void	death_checker_more(t_table *t)
{
	int	i;

	i = -1;
	while (++i < t->num_philo && !t->is_died)
	{
		pthread_mutex_lock(&t->m_meal);
		if (timestamp() - t->philo[i].last_meal >= t->time_die)
		{
			pthread_mutex_lock(&t->m_die);
			if (t->is_died == 0)
				printf("%lld %d died\n", timestamp() - t->start_time, i + 1);
			t->is_died = 1;
			pthread_mutex_unlock(&t->m_die);
		}
		pthread_mutex_unlock(&t->m_meal);
		usleep(100);
	}
}

void	death_checker(t_table *t)
{
	pthread_mutex_lock(&t->m_count_eat);
	while (t->all_ate != t->num_philo)
	{
		if (t->all_ate == t->num_philo)
			break ;
		pthread_mutex_unlock(&t->m_count_eat);
		death_checker_more(t);
		if (t->is_died)
			break ;
		pthread_mutex_lock(&t->m_count_eat);
	}
}

int	eat_check(t_philo *p)
{
	if (p->num_eat == p->table->philo_m_eat)
	{
		pthread_mutex_lock(&p->table->m_count_eat);
		p->table->all_ate++;
		pthread_mutex_lock(&p->table->m_meal);
		p->last_meal += p->table->time_die * 2;
		pthread_mutex_unlock(&p->table->m_meal);
		pthread_mutex_unlock(&p->table->m_count_eat);
		return (0);
	}
	return (1);
}

int	free_all_mutex(t_table *table)
{
	if (pthread_mutex_init(&table->m_print, NULL))
		return (0);
	else if (pthread_mutex_init(&table->m_meal, NULL))
		return (pthread_mutex_destroy(&table->m_print), 0);
	else if (pthread_mutex_init(&table->m_die, NULL))
	{
		pthread_mutex_destroy(&(table->m_meal));
		pthread_mutex_destroy(&(table->m_print));
		return (0);
	}
	else if (pthread_mutex_init(&table->m_count_eat, NULL))
	{
		pthread_mutex_destroy(&(table->m_die));
		pthread_mutex_destroy(&(table->m_meal));
		pthread_mutex_destroy(&(table->m_print));
		return (0);
	}
	return (1);
}
