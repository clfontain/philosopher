/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:30:23 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/28 15:00:57 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating_wait(t_philo *philo)
{
	time_t		deadly_eat;
	t_struct	*data;

	data = philo->data;
	change_t_eat(philo);
	deadly_eat = philo->time_to_die + check_t_eat(philo);
	if (eating_print(philo) == 1)
		return (1);
	if (get_time(data->time_start) + philo->time_to_eat > deadly_eat)
	{
		usleep((deadly_eat - get_time(data->time_start)) * 1000);
		dead(philo);
		return (1);
	}
	else
		usleep(philo->time_to_eat * 1000);
	return (0);
}

int	eating(t_philo *philo, t_forks *forks1, t_forks *forks2)
{
	t_struct	*data;

	data = philo->data;
	if (check_end(data) == 1)
		return (1);
	take_fork(forks1);
	take_fork(forks2);
	if (print_forks(philo) == 1)
		return (drop_fork(forks1), drop_fork(forks2), 1);
	if (eating_wait(philo) == 1)
		return (drop_fork(forks1), drop_fork(forks2), 1);
	drop_fork(forks1);
	drop_fork(forks2);
	return (0);
}

int	choose_forks(t_philo *philo, t_forks *forks1, t_forks *forks2)
{
	int	i;

	i = philo->index;
	if (i % 2 != 0)
	{
		if (eating(philo, forks1, forks2) == 1)
			return (1);
	}
	else
	{
		usleep(50);
		if (eating(philo, forks2, forks1) == 1)
			return (1);
	}
	return (0);
}

int	eating_beg(t_philo *philo, t_struct *data)
{
	int			i;
	t_forks		*forks1;
	t_forks		*forks2;

	i = philo->index;
	forks1 = &data->forks[i];
	if (i == (data->nbr_philo - 1))
		forks2 = &data->forks[0];
	else
		forks2 = &data->forks[i + 1];
	if (choose_forks(philo, forks1, forks2) == 1)
		return (1);
	return (0);
}
