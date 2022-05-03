/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_starving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:34:15 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 22:26:34 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	exit_flag(t_philo *p)
{
	*(p->exit) = 1;
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
		exit_flag(p);
		printf("Number of eat times has reached.\n");
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
				exit_flag(p);
				printf("%8d "RED"%3zu"RES STR_D, \
					time_stamp(*p), p[i].name);
				return ;
			}
			i++;
		}
		usleep(50);
	}
}
