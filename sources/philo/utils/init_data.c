/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/06 15:59:25 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <stdlib.h>

void	create_philo(t_data *dt, int num)
{
	dt->philo[num].num = num + 1;
	dt->philo[num].data = dt;
}

void static	init_threads_mutex(t_data *dt)
{
	int	i;

	i = -1;
	dt->id = malloc(sizeof(pthread_t) * dt->num_philos);
	dt->mutex = malloc(sizeof(pthread_mutex_t) * dt->num_philos);
	while (++i < dt->num_philos)
	{
		// TODO
		// INICIAR LOS MUTEX ANTES DE LOS HILOS
		// UNO PARA MUTEX PRINT
		pthread_mutex_init(&dt->mutex[i], NULL);
		pthread_create(&dt->id[i], NULL, &processes, &dt->philo[i]);
		create_philo(dt, i);
	}
}

int	init_data(int argc, char *argv[], t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->philo = ft_calloc(data->num_philos, sizeof(t_philo));
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
	init_threads_mutex(data);
	return (0);
}
