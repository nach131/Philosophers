/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/26 10:15:04 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <limits.h>
#include <stdlib.h>

int	create_mutex(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
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

int static	init_mutex(t_data *data)
{
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
	if (create_mutex(data))
		return (1);
	return (0);
}

int	create_threads(t_data *data, int *success_count)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		data->philo[i].num = i + 1;
		data->philo[i].data = data;
		if (pthread_create(&data->id[i], NULL, &processes,
				&data->philo[i]) != 0)
		{
			ft_message(DANGER, "Error create pthread");
			free(data->id);
			return (1);
		}
		else
			(*success_count)++;
	}
	return (0);
}

int static	init_threads(t_data *dt)
{
	int	success_count;

	success_count = 0;
	dt->id = malloc(sizeof(pthread_t) * dt->num_philos);
	if (!dt->id)
	{
		ft_message(DANGER, "Error allocating memory to id");
		return (1);
	}
	create_threads(dt, &success_count);
	if (success_count != dt->num_philos)
	{
		ft_message(DANGER, "Not all threads were created successfully");
		free(dt->id);
		return (1);
	}
	return (0);
}

int	init_data(int argc, char *argv[], t_data *data)
{
	data->philo = ft_calloc(data->num_philos, sizeof(t_philo));
	if (!data->philo)
		return (1);
	if (is_digit(argv[1]) || is_digit(argv[2]) || is_digit(argv[3])
		|| is_digit(argv[4]))
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
	if (if_neg(data))
		return (1);
	if (init_mutex(data) || init_threads(data))
		return (1);
	return (0);
}
