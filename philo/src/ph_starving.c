/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_starving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:34:15 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 17:55:02 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	exit_flag(t_philo *p)
{
	size_t	i;

	i = 0;
	while (i < p->arg.eat_n)
	{
		p[i].exit = 1;
		i++;
	}
}

static int	death_stamp(t_philo p)
{
	struct timeval	mark;
	unsigned int	elapse;
	int				diff;
	int				diff_sec;

	gettimeofday(&mark, NULL);
	diff = (mark.tv_usec - p.last_fed.tv_usec) / 1000;
	diff_sec = mark.tv_sec - p.last_fed.tv_sec;
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
		printf("Number of eat times has reached.\n");
		exit_flag(p);
		return (1);
	}
	return (0);
}

void	check_starving(t_philo *p)
{
	size_t	i;
	int		died;

	died = p->arg.die_t / 1000;
	while (1)
	{
		i = 0;
		if (check_fed(p))
			break ;
		while (i < p->arg.phil_n)
		{
			if (death_stamp(*p) > died)
			{
				printf("%8d "RED"%3zu"RES" has died\n", \
					time_stamp(*p), p[i].name);
				exit_flag(p);
				return ;
			}
			i++;
		}
		usleep(1000);
	}
}
