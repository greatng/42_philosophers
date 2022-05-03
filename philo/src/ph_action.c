/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 15:54:41 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 13:40:13 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	time_stamp(t_philo p)
{
	struct timeval	action;
	int	diff;
	int	diff_sec;
	unsigned int	elapse;

	gettimeofday(&action, NULL);
	diff = (action.tv_usec - p.start.tv_usec) / 1000;
	diff_sec = action.tv_sec - p.start.tv_sec;
	elapse = diff + (diff_sec * 1000);
	return (elapse);
}

static void	sleep_think(t_philo *p)
{
	printf("%8d "CYAN"%3zu"RES" is sleeping\n", \
		time_stamp(*p), p->name);
	usleep(1000 * p->arg.sleep_t);
	printf("%8d "CYAN"%3zu"RES" is thinking\n", \
		time_stamp(*p), p->name);
}

static int	can_eat(t_philo *p)
{
	if (!pthread_mutex_lock(&p->fork))
	{
		if (!pthread_mutex_lock(&(p->l_philo)->fork))
		{	
			printf("%8d "CYAN"%3zu"RES" has taken a fork\n", \
				time_stamp(*p), p->name);
			printf("%8d "CYAN"%3zu"RES" is eating\n", \
				time_stamp(*p), p->name);
			gettimeofday(&p->last_fed, NULL);
			p->fed += 1;
			usleep(1000 * p->arg.eat_t);
			pthread_mutex_unlock(&(p->l_philo)->fork);
			pthread_mutex_unlock(&p->fork);
			return (1);
		}
		else
			pthread_mutex_unlock(&(p->l_philo)->fork);
	}
	return (0);
}

void	philo_action(t_philo *p)
{
	p->last_fed = p->start;
	while (1)
	{
		if (can_eat(p))
			sleep_think(p);
	}
}

//if (!pthread_mutex_lock(&p->fork))