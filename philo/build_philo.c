/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:27:53 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 11:38:32 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_struct *data)
{
	data->philo = malloc(sizeof(t_philo) * ((data->nbr_philo)));
	if (data->philo == NULL)
		return (write(2, "malloc error\n", 13), 1);
	data->philo[0].thread = 0;
	data->philo[0].data = data;
	data->time_start = get_time(data->time_start);
	data->philo[0].t_start = data->time_start;
	if (pthread_create(&data->philo[0].thread, NULL,
			routine_one_philo, &data->philo[0]) != 0)
		return (1);
	pthread_join(data->philo[0].thread, NULL);
	return (0);
}

int	init_philo(t_philo *philo, t_struct *data, int i)
{
	philo->thread = 0;
	philo->eat_count = data->time_each_philo_eat;
	philo->t_eat = data->time_start;
	philo->data = data;
	philo->index = i;
	philo->t_start = data->time_start;
	philo->left = 0;
	philo->right = 0;
	philo->time_to_die = data->time_to_die;
	philo->time_to_eat = data->time_to_eat;
	philo->forks_count = 0;
	philo->time_to_sleep = data->time_to_sleep;
	philo->t_eat = get_time(data->time_start);
	if (pthread_create(&philo->thread, NULL, routine, philo) != 0)
		return (1);
	return (0);
}

int	build_philo(t_struct *data)
{
	int	i;

	data->i = 0;
	i = 0;
	data->philo = malloc(sizeof(t_philo) * ((data->nbr_philo)));
	if (data->philo == NULL)
		return (write(2, "malloc error\n", 13), 1);
	data->time_start = get_time(data->time_start);
	while (data->i < (data->nbr_philo))
	{
		if (init_philo(&data->philo[data->i], data, data->i) == 1)
			return (write(2, "init error\n", 11), 1);
		data->i++;
	}
	i = 0;
	if (data->nbr_philo != 1)
		routine_main(data);
	while (i < (data->nbr_philo))
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	return (0);
}
