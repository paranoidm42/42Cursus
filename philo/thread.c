/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 10:43:56 by ccur              #+#    #+#             */
/*   Updated: 2023/12/10 10:43:56 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <stdio.h>

void	mutex_printf(char *str, t_philo *p)
{
	pthread_mutex_lock(&p->table->m_die);
	pthread_mutex_lock(&p->table->m_print);
	if (!p->table->is_died)
		printf("%lld %d %s", timestamp() - p->table->start_time, p->num, str);
	pthread_mutex_unlock(&p->table->m_die);
	pthread_mutex_unlock(&p->table->m_print);
}

int	eate_routine(t_philo *p)
{
	pthread_mutex_lock(&p->table->forks[p->r_fork]);
	pthread_mutex_lock(&p->table->forks[p->l_fork]);
	mutex_printf("has taken a fork\n", p);
	mutex_printf("is eating\n", p);
	pthread_mutex_lock(&p->table->m_meal);
	p->last_meal = timestamp();
	p->num_eat++;
	pthread_mutex_unlock(&p->table->m_meal);
	ft_usleep(p->table->time_eat);
	pthread_mutex_unlock(&p->table->forks[p->l_fork]);
	pthread_mutex_unlock(&p->table->forks[p->r_fork]);
	mutex_printf("is sleeping\n", p);
	ft_usleep(p->table->time_slep);
	mutex_printf("is thinking\n", p);
	return (1);
}

void	one_philo(t_philo *p)
{
	mutex_printf(" has taken a fork\n", p);
	ft_usleep(p->table->time_die);
	mutex_printf(" died\n", p);
}

void	*routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	if (p->table->num_philo == 1)
		return (one_philo(p), NULL);
	if (p->num % 2 == 0)
		ft_usleep(p->table->time_eat / 2);
	while (1)
	{
		pthread_mutex_lock(&(p->table->m_die));
		if (p->table->is_died)
		{
			pthread_mutex_unlock(&(p->table->m_die));
			break ;
		}
		pthread_mutex_unlock(&(p->table->m_die));
		eate_routine(p);
		if (!eat_check(p))
			break ;
	}
	return (NULL);
}

int	start_thread_main(t_table *table)
{
	t_philo	*philo;
	int		i;

	philo = table->philo;
	i = 0;
	table->start_time = timestamp();
	while (i < table->num_philo)
	{
		if (pthread_create(&(philo[i].t_num), NULL, routine, &(philo[i])))
			return (0);
		pthread_mutex_lock(&table->m_meal);
		philo[i].last_meal = timestamp();
		pthread_mutex_unlock(&table->m_meal);
		i++;
	}
	death_checker(philo->table);
	exit_launcher(philo->table, philo);
	return (1);
}
