/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: ccur <ccur@student.42.fr>                  +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/12/10 10:43:56 by ccur              #+#    #+#             */
/*   Updated: 2023/12/10 10:43:56 by ccur             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

typedef struct s_philo
{
	struct s_table	*table;
	int				num;
	int				r_fork;
	int				l_fork;
	int				num_eat;
	long long int	last_meal;
	pthread_t		t_num;

}	t_philo;

typedef struct s_table
{
	int				num_philo;
	t_philo			*philo;
	int				time_die;
	int				time_eat;
	int				time_slep;
	int				philo_m_eat;
	long int		start_time;
	int				is_died;
	int				all_ate;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_meal;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_die;
	pthread_mutex_t	m_count_eat;
}	t_table;

int				ft_isdigit(int c);
long int		ft_atoi_long(const char *argv);
long long int	timestamp(void);
int				start_thread_main(t_table *table);
void			ft_usleep(int ms);
void			mutex_printf(char *str, t_philo *philo);
void			death_checker(t_table *t);
void			death_checker_more(t_table *t);
void			exit_launcher(t_table *t, t_philo *p);
int				eat_check(t_philo *p);
int				free_all_mutex(t_table *table);

#endif
