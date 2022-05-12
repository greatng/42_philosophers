/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:27 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/12 23:08:15 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philo_release(t_philo *p, int philo_n)
{
	int	i;

	i = 0;
	while (i < philo_n)
	{
		pthread_create(&p[i].tid, NULL, philo_action, &p[i]);
		pthread_detach(p[i].tid);
		i += 2;
		if (i >= philo_n && !(i % 2))
		{
			usleep(500);
			i = 1;
		}
	}
}

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
	size_t	exit;

	if (!is_valid(argc, argv))
		return (instruct());
	arg_init(&a, argc, argv);
	p = malloc(sizeof(t_philo) * (a.phil_n + 1));
	if (!p)
		return (1);
	exit = 0;
	philo_create(p, a, &exit);
	philo_release(p, a.phil_n);
	check_starving(p);
	free(p);
}
