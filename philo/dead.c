/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:34:16 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 11:31:20 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_eat(t_struct *data)
{
	if (data->time_each_philo_eat == -1)
		return (0);
	if (check_end_eat(data) == data->nbr_philo)
	{
		pthread_mutex_lock(&data->m_bool_end);
		data->bool = 1;
		pthread_mutex_unlock(&data->m_bool_end);
		return (1);
	}
	return (0);
}

int	dead(t_philo *philo)
{
	t_struct	*data;

	data = (t_struct *)philo->data;
	pthread_mutex_lock(&data->m_print_end);
	if (check_end(data) == 0)
	{
		pthread_mutex_lock(&data->m_bool_end);
		data->bool++;
		pthread_mutex_unlock(&data->m_bool_end);
		pthread_mutex_lock(&data->m_print);
		printf("%ld %d died\n", get_time(data->time_start), philo->index + 1);
		pthread_mutex_unlock(&data->m_print);
	}
	pthread_mutex_unlock(&data->m_print_end);
	return (0);
}
