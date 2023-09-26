/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/26 09:38:15 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <limits.h>
#include <stdlib.h>

int static init_mutex(t_data *data)
{
	int i;
	int j;

	i = -1;
	j = -1;
	if (pthread_mutex_init(&data->m_print, NULL))
	{
		ft_message(DANGER, "Error initializing mutex");
		return (1);
	}

	data->mutex = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->mutex)
	{
		ft_message(DANGER, "Error allocating memory to mutex");
		return (1);
	}
	while (++i < data->num_philos)
	{
		if (pthread_mutex_init(&data->mutex[i], NULL) != 0)
		{
			while (++j < i)
				pthread_mutex_destroy(&data->mutex[j]);
			ft_message(DANGER, "Error initializing mutex");
			free(data->mutex);
			return (1);
		}
	}
	return (0);
}

void create_philo(t_data *dt, int i)
{
	dt->philo[i].num = i + 1;
	dt->philo[i].data = dt;
}
//=================ORI===================================================
// int static init_threads(t_data *dt)
// {
// 	int	i;

// 	i = -1;
// 	dt->id = malloc(sizeof(pthread_t) * dt->num_philos);
// 	dt->mutex = malloc(sizeof(pthread_mutex_t) * dt->num_philos);
// 	if (!dt->id || !dt->mutex)
// 		return (1);
// 	pthread_mutex_init(&dt->m_print, NULL);
// 	while (++i < dt->num_philos)
// 		pthread_mutex_init(&dt->mutex[i], NULL);
// 	i = -1;
// 	pthread_mutex_lock(&dt->m_print);
// 	while (++i < dt->num_philos)
// 	{
// 		create_philo(dt, i);
// 		pthread_create(&dt->id[i], NULL, &processes, &dt->philo[i]);
// 	}
// 	pthread_mutex_unlock(&dt->m_print);
// 	return (0);
// }
//=========================================================================
int static init_threads(t_data *dt)
{
	int i;
	int success_count = 0; // Contador de hilos creados con éxito

	i = -1;
	dt->id = malloc(sizeof(pthread_t) * dt->num_philos);
	if (!dt->id)
	{
		ft_message(DANGER, "Error allocating memory to id");
		return (1);
	}
	while (++i < dt->num_philos)
	{
		create_philo(dt, i);
		if (pthread_create(&dt->id[i], NULL, &processes, &dt->philo[i]) != 0)
		{
			ft_message(DANGER, "Error create pthread");
			free(dt->id);
			return (1);
		}
		else
		{
			success_count++; // Incrementa el contador de hilos creados con éxito
		}
	}

	if (success_count != dt->num_philos)
	{
		// Al menos un hilo no se creó con éxito, debemos manejarlo aquí
		ft_message(DANGER, "Not all threads were created successfully");
		free(dt->id);
		return (1);
	}

	// i = -1;
	// while (++i < dt->num_philos)
	// {
	// 	if (pthread_join(dt->id[i], NULL) != 0)
	// 	{
	// 		printf("aki\n");
	// 		ft_message(DANGER, "Error joining pthread");
	// 		dt->pthread = 1;
	// 		free(dt->id);
	// 		return (1);
	// 	}
	// }
	return (0);
}

int	init_data(int argc, char *argv[], t_data *data)
{
	data->philo = ft_calloc(data->num_philos, sizeof(t_philo));
	if (!data->philo)
	{
		ft_message(DANGER, "Error allocating memory to philo");
		return (1);
	}
	if (is_digit(argv[1]) || is_digit(argv[2]) || is_digit(argv[3]) || is_digit(argv[4]))
		return (1);
	data->num_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (is_digit(argv[5]))
			return (1);
		data->num_meals = ft_atoi(argv[5]);
	}
	else
		data->num_meals = INT_MAX;
	if (data->num_philos < 0 || data->t_die < 0 || data->t_eat < 0
		|| data->t_sleep < 0 || data->num_meals < 0)
	{
		ft_message(DANGER, "All arguments have to be positive.");
		return (1);
	}
	if (init_mutex(data) || init_threads(data))
		// if (init_threads(data))
		return (1);
	return (0);
}
