/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:12:14 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 11:31:09 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

time_t	get_time(time_t start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000) - start);
}

void	ft_clean_up(t_struct *data)
{
	int	i;

	i = 0;
	if (data->forks != NULL)
	{
		while (i < data->nbr_philo)
		{
			pthread_mutex_destroy(&data->forks[i].m_forks);
			i++;
		}
	}	
	pthread_mutex_destroy(&data->m_print);
	pthread_mutex_destroy(&data->m_eat);
	pthread_mutex_destroy(&data->m_bool_end);
	pthread_mutex_destroy(&data->m_t_eat);
	pthread_mutex_destroy(&data->m_print_end);
	if (data->philo != NULL)
		free (data->philo);
	if (data->forks != NULL)
		free (data->forks);
}

void	init_data(t_struct *data)
{
	data->end_eat = 0;
	data->bool = 0;
	data->philo = NULL;
	data->forks = NULL;
	pthread_mutex_init(&data->m_print, NULL);
	pthread_mutex_init(&data->m_eat, NULL);
	pthread_mutex_init(&data->m_t_eat, NULL);
	pthread_mutex_init(&data->m_bool_end, NULL);
	pthread_mutex_init(&data->m_print_end, NULL);
	data->time_start = 0;
}

int	main(int argc, char **argv)
{
	t_struct	data;

	if (argc != 5 && argc != 6)
		return (write(2, "Error, philo need 4 or 5 arguments\n", 35), 1);
	init_data(&data);
	if (build_arg(argc, argv, &data) == 1)
		return (ft_clean_up(&data), 1);
	if (data.nbr_philo == 1)
	{
		if (one_philo(&data) == 1)
			return (ft_clean_up(&data), 1);
	}
	else
	{
		if (build_philo(&data) == 1)
			return (ft_clean_up(&data), 1);
	}
	ft_clean_up(&data);
	return (0);
}
