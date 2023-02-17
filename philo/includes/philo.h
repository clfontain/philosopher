/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <clement.f.fontaine@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:08:51 by cfontain          #+#    #+#             */
/*   Updated: 2022/11/02 11:31:08 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_forks
{
	pthread_mutex_t	m_forks;
	int				state;
}	t_forks;

typedef struct s_philo
{
	void		*data;
	pthread_t	thread;
	int			index;
	int			forks_count;
	int			left;
	int			right;
	int			eat_count;
	time_t		t_eat;
	time_t		t_start;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
}	t_philo;

typedef struct s_struct
{
	int				i;
	int				bool;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_eat;
	pthread_mutex_t	m_t_eat;
	pthread_mutex_t	m_bool_end;
	pthread_mutex_t	m_print_end;
	time_t			time_start;
	long int		end_eat;
	long int		nbr_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		time_each_philo_eat;
	t_forks			*forks;
	t_philo			*philo;
}	t_struct;

int			main(int argc, char **argv);
time_t		get_time(time_t start);
void		ft_clean_up(t_struct *data);
int			check_nbr(char *str);
int			build_arg(int argc, char **argv, t_struct *data);
int			build_philo(t_struct *data);
int			one_philo(t_struct *data);
int			end(t_philo *philo);
int			dead(t_philo *philo);
int			eating(t_philo *philo, t_forks *forks1, t_forks *forks2);
int			choose_forks(t_philo *philo, t_forks *forks1, t_forks *forks2);
int			eating_beg(t_philo *philo, t_struct *data);
int			eating_print(t_philo *philo);
int			sleeping_print(t_philo *philo);
int			thinking_print(t_philo *philo);
int			print_forks(t_philo *philo);
void		*routine(void *arg);
void		*routine_one_philo(void *arg);
void		*routine_sup(void *arg);
int			sleeping(t_philo *philo);
int			thinking(t_philo *philo);
int			check_end(t_struct *data);
int			check_dead(t_philo *philo);
int			check_t_eat(t_philo *philo);
int			check_end_eat(t_struct *data);
void		change_t_eat(t_philo *philo);
long int	ft_atoi(const char *nptr);
int			ft_isdigit(int c);
int			take_fork(t_forks *fork);
int			drop_fork(t_forks *fork);
int			check_fork(t_forks *fork);
int			routine_main(t_struct *data);
int			check_argv(char **argv);
int			all_eat(t_struct *data);
#endif