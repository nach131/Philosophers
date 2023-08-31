/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/31 11:48:19 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylibft.h"
#include "error.h"
#include <stdio.h>

int init_data(int argc, char *argv[])
{
	int philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int meals;

	(void)argc;

	philo = ft_atoi(argv[1]);
	t_die = ft_atoi(argv[2]) * 1000;
	t_eat = ft_atoi(argv[3]) * 1000;
	t_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		meals = ft_atoi(argv[5]);
	if (philo < 0 || t_die < 0 || t_eat < 0 || t_sleep < 0 || meals < 0)
		return (1);
	printf("philo,%d\n", philo);
	printf("die,%d\n", t_die);
	printf("eat,%d\n", t_eat);
	printf("sleep,%d\n", t_sleep);
	return (0);
}
