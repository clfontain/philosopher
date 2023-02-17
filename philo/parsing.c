/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:11:19 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 14:27:39 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_nbr(char *str)
{
	long int	nbr;

	nbr = ft_atoi(str);
	if (nbr < 0 || nbr > 2147483647)
		return (1);
	return (0);
}

int	str_is_big(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	if (i >= 11)
	{
		write(2, "too big arguments\n", 18);
		return (1);
	}	
	return (0);
}

int	str_is_nbr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	check_argv(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (str_is_nbr(argv[i]) == 1)
			return (1);
		if (str_is_big(argv[i]) == 1)
			return (1);
		if (check_nbr(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
