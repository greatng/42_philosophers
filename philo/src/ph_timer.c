/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:01:45 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/04 09:37:34 by pngamcha         ###   ########.fr       */
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

void	my_sleep(int t, int elapse)
{
	struct timeval	mark;
	struct timeval	now;
	int				diff;
	int				diff_sec;

	gettimeofday(&mark, NULL);
	usleep(t * 2 / 3);
	gettimeofday(&now, NULL);
	diff = (now.tv_usec - mark.tv_usec) / 1000;
	diff_sec = now.tv_sec - mark.tv_sec;
	elapse = diff + (diff_sec * 1000);
	while (elapse < t)
	{
		gettimeofday(&now, NULL);
		diff = (now.tv_usec - mark.tv_usec) / 1000;
		diff_sec = now.tv_sec - mark.tv_sec;
		elapse = diff + (diff_sec * 1000);
		usleep(300);
	}
	return ;
}

int	death_stamp(t_philo p)
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