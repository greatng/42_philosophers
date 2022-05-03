/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:55 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 13:35:16 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define RES "\033[0m"

typedef struct s_arg
{
	size_t	phil_n;
	size_t	die_t;
	size_t	eat_t;
	size_t	sleep_t;
	size_t	eat_n;
}	t_arg;

typedef struct s_philo
{
	t_arg	arg;
	struct s_philo	*l_philo;
	size_t	name;
	pthread_mutex_t	fork;
	size_t	fed;
	struct timeval	last_fed;
	struct timeval	start;
	struct timeval	wait;
	pthread_t	tid;
}	t_philo;

int		is_valid(int argc, char **argv);

void	arg_init(t_arg *a, int argc, char **argv);
void	philo_create(t_philo *p, t_arg a);
void	philo_action(t_philo *p);
void	check_starving(t_philo *p);
int	time_stamp(t_philo p);

#endif