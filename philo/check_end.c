/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:20:25 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 11:31:12 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	change_t_eat(t_philo *philo)
{
	t_struct	*data;

	data = philo->data;
	pthread_mutex_lock(&data->m_t_eat);
	philo->t_eat = get_time(data->time_start);
	pthread_mutex_unlock(&data->m_t_eat);
}

int	check_t_eat(t_philo *philo)
{
	time_t		t_eat;
	t_struct	*data;

	data = philo->data;
	pthread_mutex_lock(&data->m_t_eat);
	t_eat = philo->t_eat;
	pthread_mutex_unlock(&data->m_t_eat);
	return (t_eat);
}

int	check_end_eat(t_struct *data)
{
	int	end_eat;

	end_eat = 0;
	pthread_mutex_lock(&data->m_eat);
	end_eat = data->end_eat;
	pthread_mutex_unlock(&data->m_eat);
	return (end_eat);
}

int	check_end(t_struct *data)
{
	int	end;

	end = 0;
	pthread_mutex_lock(&data->m_bool_end);
	end = data->bool;
	pthread_mutex_unlock(&data->m_bool_end);
	return (end);
}
