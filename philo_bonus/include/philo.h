/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:55 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/16 18:45:22 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define RES "\033[0m"

# define FORK_SEM "/fork"
# define DIED_SEM "/died"
# define FED_SEM "/fed"
# define EXEC_SEM "/exec"

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
	struct timeval	last_fed;
	struct timeval	start;
	pid_t			pid;
	t_arg			arg;
	size_t			name;	
	size_t			fed;
}	t_philo;

typedef struct s_exit
{
	sem_t	*fed;
	sem_t	*died;
	sem_t	*execute;
	size_t	p_num;
	t_philo	*p;
}	t_exit;

int		is_valid(int argc, char **argv);
int		time_stamp(t_philo p);
int		death_stamp(t_philo p);

void	arg_init(t_arg *a, int argc, char **argv);
void	philo_create(t_philo *p, t_arg a);
void	check_starving(t_exit *exit);
void	check_fed(t_exit exit);
void	kill_philo(t_philo *p, t_exit exit, sem_t *forkk);
void	philo_action(void *a, sem_t *fork, t_exit exit);
void	fed_init(sem_t *fed, size_t n);

#endif