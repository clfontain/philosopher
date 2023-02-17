/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:30:58 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/28 15:06:37 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philo)
{
	time_t		deadly_sleep;
	t_struct	*data;

	data = philo->data;
	deadly_sleep = 0;
	if (sleeping_print(philo) == 1)
		return (1);
	deadly_sleep = philo->time_to_die + check_t_eat(philo);
	if (get_time(data->time_start) + philo->time_to_sleep > deadly_sleep)
	{
		usleep((deadly_sleep - get_time(data->time_start)) * 1000);
		dead(philo);
		return (1);
	}	
	else
		usleep(philo->time_to_sleep * 1000);
	return (0);
}
