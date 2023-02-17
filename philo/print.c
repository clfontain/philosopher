/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:33:37 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/28 14:46:17 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_forks(t_philo *philo)
{
	t_struct	*data;

	data = (t_struct *)philo->data;
	pthread_mutex_lock(&data->m_print);
	if (check_end(data) == 0)
	{
		printf("%ld %d has taken a fork\n",
			get_time(data->time_start), philo->index + 1);
		printf("%ld %d has taken a fork\n",
			get_time(data->time_start), philo->index + 1);
	}
	else
		return (pthread_mutex_unlock(&data->m_print), 1);
	pthread_mutex_unlock(&data->m_print);
	return (0);
}

int	eat_count(t_philo *philo)
{
	t_struct	*data;

	data = philo->data;
	if (data->philo[philo->index].eat_count > 0)
	{
		data->philo[philo->index].eat_count--;
		if (data->philo[philo->index].eat_count == 0)
		{
			pthread_mutex_lock(&data->m_eat);
			data->end_eat++;
			pthread_mutex_unlock(&data->m_eat);
		}
	}
	return (0);
}

int	eating_print(t_philo *philo)
{
	t_struct	*data;

	data = (t_struct *)philo->data;
	if (check_end(data) == 1)
		return (1);
	pthread_mutex_lock(&data->m_print);
	if (check_end(data) == 0)
	{
		eat_count(philo);
		printf("%ld %d is eating\n",
			get_time(data->time_start), philo->index + 1);
	}
	else
		return (pthread_mutex_unlock(&data->m_print), 1);
	pthread_mutex_unlock(&data->m_print);
	return (0);
}

int	sleeping_print(t_philo *philo)
{
	t_struct	*data;

	data = (t_struct *)philo->data;
	pthread_mutex_lock(&data->m_print);
	if (check_end(data) == 0)
	{
		printf("%ld %d is sleeping\n",
			get_time(data->time_start), philo->index + 1);
	}
	else
		return (pthread_mutex_unlock(&data->m_print), 1);
	pthread_mutex_unlock(&data->m_print);
	return (0);
}

int	thinking_print(t_philo *philo)
{
	t_struct	*data;

	data = (t_struct *)philo->data;
	pthread_mutex_lock(&data->m_print);
	if (check_end(data) == 0)
	{
		printf("%ld %d is thinking\n",
			get_time(data->time_start), philo->index + 1);
	}
	else
		return (pthread_mutex_unlock(&data->m_print), 1);
	pthread_mutex_unlock(&data->m_print);
	return (0);
}
