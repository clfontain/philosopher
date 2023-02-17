/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:28:43 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 14:40:16 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	build_arg2(int argc, char **argv, t_struct *data)
{
	data->nbr_philo = ft_atoi(argv[1]);
	if (data->nbr_philo > 200 || data->nbr_philo <= 0)
		return (data->nbr_philo = 0, write(2, "error philo arguments\n", 23), 1);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->time_each_philo_eat = ft_atoi(argv[5]);
		if (data->time_each_philo_eat == 0)
			return (1);
	}	
	else
		data->time_each_philo_eat = -1;
	return (0);
}

int	build_arg(int argc, char **argv, t_struct *data)
{
	int		i;

	i = 0;
	if (check_argv(argv) == 1)
		return (data->nbr_philo = 0, write(2, "wrong arguments\n", 16), 1);
	if (build_arg2(argc, argv, data) == 1)
		return (1);
	data->forks = malloc(sizeof(t_forks) * data->nbr_philo);
	if (data->forks == NULL)
		return (write(2, "malloc error\n", 13), 1);
	while (i < (data->nbr_philo))
	{
		data->forks[i].state = 0;
		pthread_mutex_init(&data->forks[i].m_forks, NULL);
		i++;
	}
	return (0);
}
