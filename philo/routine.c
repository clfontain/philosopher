/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:29:23 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 14:40:12 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_one_philo(void *arg)
{
	t_philo		*philo;
	t_struct	*data;

	philo = (t_philo *)arg;
	data = (t_struct *)philo->data;
	printf("%ld 1 has taken a fork\n", get_time(data->time_start));
	usleep(data->time_to_die * 1000);
	printf("%ld 1 died\n", get_time(data->time_start));
	return (arg);
}

int	routine_main(t_struct *data)
{
	int	i;

	i = 0;
	while (check_end(data) == 0)
	{
		i = 0;
		while (i < data->nbr_philo)
		{
			if ((get_time(data->time_start)
					- check_t_eat(&data->philo[i])) > data->time_to_die)
			{
				dead(&data->philo[i]);
				return (1);
			}
			i++;
		}
		if (all_eat(data) == 1)
			return (1);
		usleep(1000);
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	t_struct	*data;

	philo = (t_philo *)arg;
	data = (t_struct *)philo->data;
	if (data->time_to_die == 0)
		return (dead(philo), NULL);
	while (check_end(data) == 0)
	{
		if (eating_beg(philo, data) == 1)
			return (NULL);
		if (sleeping(philo) == 1)
			return (NULL);
		if (thinking(philo) == 1)
			return (NULL);
		usleep(50);
	}
	return (arg);
}
