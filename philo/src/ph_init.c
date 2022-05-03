/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:59:48 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/03 11:02:31 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	ft_atoi(const char *str)
{
	size_t		i;
	long int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result);
}

void	arg_init(t_arg *a, int argc, char **argv)
{
	a->died = 0;
	a->phil_n = ft_atoi(argv[1]);
	a->die_t = ft_atoi(argv[2]);
	a->eat_t = ft_atoi(argv[3]);
	a->sleep_t = ft_atoi(argv[4]);
	if (argc == 6)
		a->eat_n = ft_atoi(argv[5]);
	else
		a->eat_n = 0;
}

void	philo_create(t_philo *p, t_arg a)
{
	int	i;
	pthread_mutex_t *tmp;

	i = 0;
	while (i < (int)a.phil_n)
	{
		p[i].arg = a;
		p[i].name = i;
		p[i].need_eat = 1;
		tmp = &p[i].fork;
		if (pthread_mutex_init(tmp, NULL))
			printf("mutex init failed\n");
		p[i].l_philo = &p[(i + 1) % a.phil_n];
		p[i].died = &a.died;
		gettimeofday(&(p[i].start), NULL);
		i++;
	}
}