/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:54:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/16 20:52:10 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// static void	execute_philo(sem_t *exec)
// {
// 	sem_wait(exec);
// 	exit(0);
// }

static void	sleep_think(t_philo *p)
{
	printf("%8d "CYAN"%3zu"RES STR_S, \
		time_stamp(*p), p->name);
	usleep(p->arg.sleep_t * 1000);
	printf("%8d "CYAN"%3zu"RES STR_T, \
		time_stamp(*p), p->name);
}

static int	can_eat(t_philo *p, sem_t *fork, sem_t *fed)
{
	sem_wait(fork);
	printf("%8d "CYAN"%3zu"RES STR_F, time_stamp(*p), p->name);
	sem_wait(fork);
	printf("%8d "CYAN"%3zu"RES STR_F, time_stamp(*p), p->name);
	gettimeofday(&p->last_fed, NULL);
	printf(GREEN "%8d %3zu"RES STR_E, time_stamp(*p), p->name);
	usleep(p->arg.eat_t * 1000);
	p->fed += 1;
	if (p->fed == p->arg.eat_n)
		sem_post(fed);
	sem_post(fork);
	sem_post(fork);
	return (1);
}

void	philo_action(void *a, sem_t *fork, t_exit exit)
{
	t_philo		*p;
	pthread_t	tid[2];

	p = (t_philo *)a;
	exit.p = p;
	pthread_create(&tid[0], 0, (void *)check_starving, &exit);
	while (1)
	{
		usleep(100);
		if (can_eat(p, fork, exit.fed))
			sleep_think(p);
	}
}
