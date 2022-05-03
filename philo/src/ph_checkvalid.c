/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_checkvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pngamcha <pngamcha@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:42:11 by pngamcha          #+#    #+#             */
/*   Updated: 2022/05/02 14:57:45 by pngamcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_digit(char *arg)
{
	size_t	i;

	i = 0;
	if (!arg[i])
		return (0);
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(int argc, char **argv)
{
	size_t	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (0);
	while (argv[i])
	{
		if (!is_digit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
