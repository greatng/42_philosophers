/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:55 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 11:44:16 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define SALMON "\e[174m"
# define RES "\e[0m"

typedef struct s_arg
{
	size_t	phil_n;
	size_t	die_t;
	size_t	eat_t;
	size_t	sleep_t;
	size_t	eat_n;
	int	died;
}	t_arg;

typedef struct s_philo
{
	t_arg	arg;
	struct s_philo	*l_philo;
	size_t	name;
	pthread_mutex_t	fork;
	int	need_eat;
	struct timeval	last_fed;
	struct timeval	start;
	struct timeval	wait;
	int	*died;
}	t_philo;

int		is_valid(int argc, char **argv);

void	arg_init(t_arg *a, int argc, char **argv);
void	philo_create(t_philo *p, t_arg a);
void	philo_action(t_philo *p);
void	check_starving(t_philo *p);
void	check_loop(t_philo *p);

#endif