/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:27 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 22:32:37 by pngamcha         ###   ########.fr       */
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
	size_t	exit;
	int		i;

	if (!is_valid(argc, argv))
		return (instruct());
	arg_init(&a, argc, argv);
	p = malloc(sizeof(t_philo) * (a.phil_n + 1));
	if (!p)
		return (1);
	exit = 0;
	philo_create(p, a, &exit);
	i = -1;
	while (++i < (int)a.phil_n)
	{
		pthread_create(&p[i].tid, NULL, philo_action, &p[i]);
		pthread_detach(p[i].tid);
	}
	check_starving(p);
	usleep(50000);
	free(p);
}
