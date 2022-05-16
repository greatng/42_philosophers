/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:56:27 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/16 17:57:54 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	philo_release(t_philo *p, int philo_n, sem_t *forkk, t_exit exit)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < philo_n)
	{
		pid = fork();
		if (pid)
			p[i].pid = pid;
		else
		{
			p[i].pid = pid;
			philo_action(&p[i], forkk, exit);
		}
		i++;
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
	t_exit	exit;
	sem_t	*forkk;

	if (!is_valid(argc, argv))
		return (instruct());
	arg_init(&a, argc, argv);
	sem_unlink(FORK_SEM);
	sem_unlink(FED_SEM);
	sem_unlink(DIED_SEM);
	forkk = sem_open(FORK_SEM, O_CREAT | O_EXCL, 0644, a.phil_n);
	exit.died = sem_open(DIED_SEM, O_CREAT | O_EXCL, 0644, 1);
	exit.fed = sem_open(FED_SEM, O_CREAT | O_EXCL, 0644, a.phil_n);
	sem_wait(exit.died);
	fed_init(exit.fed, a.phil_n);
	p = malloc(sizeof(t_philo) * (a.phil_n + 1));
	if (!p)
		return (1);
	philo_create(p, a);
	philo_release(p, a.phil_n, forkk, exit);
	check_fed(p, exit);
	printf("PID %d\n", getpid());
	kill_philo(p, exit, forkk);
	printf("EOF\n");
}
