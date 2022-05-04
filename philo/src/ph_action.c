/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:54:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/04 10:08:55 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	sleep_think(t_philo *p)
{
	if (*(p->exit))
		return ;
	printf("%8d "CYAN"%3zu"RES STR_S, \
		time_stamp(*p), p->name);
	my_sleep(p->arg.sleep_t, 0);
	if (*(p->exit))
		return ;
	printf("%8d "CYAN"%3zu"RES STR_T, \
		time_stamp(*p), p->name);
}

static int	can_eat(t_philo *p)
{
	if (*(p->exit))
		return (0);
	pthread_mutex_lock(&p->fork);
	if (*(p->exit))
		return (0);
	printf("%8d "CYAN"%3zu"RES STR_F, time_stamp(*p), p->name);
	pthread_mutex_lock(&(p->l_philo)->fork);
	if (*(p->exit))
		return (0);
	printf("%8d "CYAN"%3zu"RES STR_F, time_stamp(*p), p->name);
	if (*(p->exit))
		return (0);
	gettimeofday(&p->last_fed, NULL);
	printf(GREEN "%8d %3zu"STR_E RES, time_stamp(*p), p->name);
	p->fed += 1;
	my_sleep(p->arg.eat_t, 0);
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_unlock(&(p->l_philo)->fork);
	return (1);
}

void	*philo_action(void *a)
{
	t_philo	*p;

	p = (t_philo *)a;
	p->last_fed = p->start;
	while (!*(p->exit))
	{
		if (can_eat(p))
			sleep_think(p);
	}
	pthread_mutex_destroy(&p->fork);
	return (NULL);
}
