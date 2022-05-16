/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_timer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 01:01:45 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/16 19:26:51 by pngamcha         ###   ########.fr       */
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
