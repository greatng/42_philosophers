/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_starving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:34:15 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/16 21:01:54 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	kill_philo(t_philo *p, t_exit exit, sem_t *forkk)
{
	size_t	i;

	i = 0;
	sem_wait(exit.died);
	while (i < p->arg.phil_n)
		kill(p[i++].pid, SIGINT);
	free(p);
	sem_close(exit.died);
	sem_unlink(DIED_SEM);
	sem_close(forkk);
	sem_unlink(FORK_SEM);
}

static void	thread_fed(t_exit *exit)
{
	size_t	i;
	size_t	philo_n;

	i = 0;
	philo_n = exit->p_num;
	while (i < philo_n)
	{
		sem_wait(exit->fed);
		i++;
	}
	sem_post(exit->died);
	printf("All philosophers have fed\n");
}

void	check_fed(t_exit exit)
{
	pthread_t	pid;

	pthread_create(&pid, 0, (void *)thread_fed, &exit);
}

void	check_starving(t_exit *exitt)
{
	t_philo		*p;
	int			died;

	p = exitt->p;
	died = p->arg.die_t;
	while (1)
	{
		if (death_stamp(*p) > died)
		{
			printf("%8d "RED"%3zu"RES STR_D, \
				time_stamp(*p), p->name);
			sem_post(exitt->died);
			exit(0);
		}
		usleep(50);
	}
}
