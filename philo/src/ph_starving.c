/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_starving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:34:15 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 13:37:38 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	death_stamp(t_philo p)
{
	struct timeval	action;
	int	diff;
	int	diff_sec;
	unsigned int	elapse;

	gettimeofday(&action, NULL);
	diff = (action.tv_usec - p.last_fed.tv_usec) / 1000;
	diff_sec = action.tv_sec - p.last_fed.tv_sec;
	elapse = diff + (diff_sec * 1000);
	return (elapse);
}

static int	check_fed(t_philo *p)
{
	size_t	i;
	size_t	min_fed;

	i = 0;
	min_fed = p->fed;
	if (!p->arg.eat_n)
		return (0);
	while (i < p[i].arg.phil_n)
	{
		if (p[i].fed < min_fed)
			min_fed = p[i].fed;
		i++;
	}
	if (min_fed >= p->arg.eat_n)
	{
		pthread_detach(p->tid);
		printf("Number of eat times has reach\n");
		return (1);
	}
	return (0);
}

void	check_starving(t_philo *p)
{
	int	i;
	int	died;

	died = p->arg.die_t;
	while (1)
	{
		i = 0;
		if (check_fed(p))
			break ;
		while (i < (int)p->arg.phil_n)
		{
			if (death_stamp(*p) > died)
			{
				printf("%8d "RED"%3zu"RES" has died\n", \
					time_stamp(*p), p[i].name);
				pthread_detach(p[i].tid);
				return ;
			}
			i++;
		}
		usleep(100);
	}
}
