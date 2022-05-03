/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:27 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 17:47:51 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	instruct(void)
{
	printf("run by : ./philo no_of_philo time_to_die");
	printf(" time_to_eat time_to_sleep [no_of_eat]\n");
	printf("ex : ./philo 5 200 200 200\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg	a;
	t_philo	*p;
	int		i;

	if (!is_valid(argc, argv))
		return (instruct());
	arg_init(&a, argc, argv);
	p = malloc(sizeof(t_philo) * (a.phil_n + 1));
	if (!p)
		return (1);
	philo_create(p, a);
	i = -1;
	while (++i < (int)a.phil_n)
	{
		gettimeofday(&p[i].start, NULL);
		pthread_create(&p[i].tid, NULL, philo_action, &p[i]);
	}
	check_starving(p);
	usleep(1000);
	free(p);
}
