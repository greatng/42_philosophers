/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_starving.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:34:15 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 10:58:19 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	check_loop(t_philo *p)
{
	int	n;
	int	diff;
	int	died;

	died = p->arg.die_t;
	while (1)
	{
		n = 0;
		while (n < (int)p->arg.phil_n)
		{
			if (p[n].need_eat)
			{	
				gettimeofday(&p[n].wait, NULL);
				diff = p[n].wait.tv_usec - p[n].last_fed.tv_usec;
				if (diff * 1000 > died)
				{
					*(p->died) = n + 1;
					return ;
				}
			}
			n++;
		}
		usleep(5);
		*(p->died) = n + 1;
	}
}

void	check_starving(t_philo *p)
{
	pthread_t	tid;

	pthread_create(&tid, NULL, (void *)check_loop, p);
	while (!(p->died))
		printf("%d", *(p->died) - 1);
}