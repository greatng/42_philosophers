/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:55 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/04 09:32:08 by pngamcha         ###   ########.fr       */
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
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RES "\033[0m"

# define STR_D " has died\n"
# define STR_S " is sleeping\n"
# define STR_T " is thinking\n"
# define STR_E " is eating\n"
# define STR_F " has taken a fork\n"

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
	struct s_philo	*l_philo;
	struct timeval	last_fed;
	struct timeval	start;
	struct timeval	wait;
	pthread_t		tid;
	t_arg			arg;
	size_t			name;	
	size_t			fed;
	size_t			*exit;
	pthread_mutex_t	fork;
}	t_philo;

int		is_valid(int argc, char **argv);
int		time_stamp(t_philo p);
int		death_stamp(t_philo p);

void	arg_init(t_arg *a, int argc, char **argv);
void	philo_create(t_philo *p, t_arg a, size_t *exit);
void	check_starving(t_philo *p);
void	my_sleep(int t, int elapse);
void	*philo_action(void *a);
void	*philo_lastaction(void *a);

#endif