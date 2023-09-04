/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/04 14:14:38 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <stdio.h>

void	put_num(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philo[i].num = i + 1;
		i++;
	}
}

// void static	init_threads(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
// 	data->threads = malloc(sizeof(pthread_t) * data->num_philo);
// }

int	init_data(int argc, char *argv[], t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->philo = ft_calloc(data->num_philos, sizeof(t_philo));
	put_num(data);
	data->t_die = ft_atoi(argv[2]) * 1000;
	data->t_eat = ft_atoi(argv[3]) * 1000;
	data->t_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	if (data->num_philos < 0 || data->t_die < 0 || data->t_eat < 0
		|| data->t_sleep < 0 || data->num_meals < 0)
	{
		ft_message(DANGER, "All arguments have to be positive.");
		return (1);
	}
	else if (data->num_philos <= 1)
	{
		ft_message(DANGER, "Minimum two philosophers.");
		return (1);
	}
	return (0);
}
