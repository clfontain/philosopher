/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:31:00 by cfontain          #+#    #+#             */
/*   Updated: 2022/10/28 15:00:33 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	drop_fork(t_forks *fork)
{
	fork->state = 0;
	pthread_mutex_unlock(&fork->m_forks);
	return (0);
}

int	take_fork(t_forks *fork)
{
	pthread_mutex_lock(&fork->m_forks);
	fork->state = 1;
	return (0);
}
