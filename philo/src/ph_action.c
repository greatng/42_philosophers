/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:54:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 22:31:58 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	time_stamp(t_philo p)
{
	int				diff;
	int				diff_sec;
	struct timeval	mark;
	unsigned int	elapse;

	gettimeofday(&mark, NULL);
	diff = (mark.tv_usec - p.start.tv_usec) / 1000;
	diff_sec = mark.tv_sec - p.start.tv_sec;
	elapse = diff + (diff_sec * 1000);
	return (elapse);
}

static void	sleep_think(t_philo *p)
{
	if (*(p->exit))
		return ;
	printf("%8d "CYAN"%3zu"RES STR_S, \
		time_stamp(*p), p->name);
	usleep(p->arg.sleep_t);
	if (*(p->exit))
		return ;
	printf("%8d "CYAN"%3zu"RES STR_T, \
		time_stamp(*p), p->name);
}

static int	can_eat(t_philo *p)
{
	if (*(p->exit))
		return (0);
	if (!pthread_mutex_lock(&p->fork) && \
		!pthread_mutex_lock(&(p->l_philo)->fork))
	{
		if (*(p->exit))
			return (0);
		printf("%8d "CYAN"%3zu"RES STR_F, \
			time_stamp(*p), p->name);
		printf("%8d "CYAN"%3zu"RES STR_F, \
			time_stamp(*p), p->name);
		if (*(p->exit))
			return (0);
		printf("%8d "CYAN"%3zu"RES STR_E, \
			time_stamp(*p), p->name);
		gettimeofday(&p->last_fed, NULL);
		p->fed += 1;
		usleep(p->arg.eat_t);
		pthread_mutex_unlock(&(p->l_philo)->fork);
		pthread_mutex_unlock(&p->fork);
		return (1);
	}	
	return (0);
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
	return (NULL);
}
