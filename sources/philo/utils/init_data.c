/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/26 11:33:26 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <limits.h>
#include <stdlib.h>

void create_philo(t_data *dt, int i)
{
	dt->philo[i].num = i + 1;
	dt->philo[i].data = dt;
}

void static init_threads_mutex(t_data *dt)
{
	int	i;

	i = -1;
	dt->id = malloc(sizeof(pthread_t) * dt->num_philos);
	dt->mutex = malloc(sizeof(pthread_mutex_t) * dt->num_philos);
	pthread_mutex_init(&dt->m_print, NULL);
	while (++i < dt->num_philos)
		pthread_mutex_init(&dt->mutex[i], NULL);
	i = -1;
	pthread_mutex_lock(&dt->m_print);
	while (++i < dt->num_philos)
	{
		create_philo(dt, i);
		pthread_create(&dt->id[i], NULL, &processes, &dt->philo[i]);
	}
	pthread_mutex_unlock(&dt->m_print);
}

int	init_data(int argc, char *argv[], t_data *data)
{
	data->philo = ft_calloc(data->num_philos, sizeof(t_philo));
	if (!data->philo)
		return (1);
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
	if (if_neg(data))
		return (1);
	init_threads_mutex(data);
	return (0);
}
