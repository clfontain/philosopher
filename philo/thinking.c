/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:32:12 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/28 14:55:30 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_philo *philo)
{
	t_struct	*data;
	time_t		t;

	data = (t_struct *)philo->data;
	if (thinking_print(philo) == 1)
		return (1);
	t = (data->time_to_die - (get_time(data->time_start)
				- check_t_eat(philo)) - data->time_to_eat) / 2;
	if (t > 650)
		t = 650;
	if (t > 0)
		usleep(t * 1000);
	return (0);
}
