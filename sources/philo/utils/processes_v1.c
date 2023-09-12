/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/12 17:10:24 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "error.h"
#include "philosophers.h"
#include <stdbool.h>
#include <stdio.h>

void	print_does(t_philo *philo, int type)
{
	char	*mss;

	mss = (char *)g_party[type];
	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s", mss);
	pthread_mutex_unlock(&philo->data->m_print);
}

static void take_spoon(t_philo *philo)
{
	if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->data->mutex[philo->num]);
		if (philo->num == 1)
			pthread_mutex_lock(&philo->data->mutex[philo->data->num_philos]);
		else
			pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);
	}
	else
	{
		pthread_mutex_lock(&philo->data->mutex[philo->num]);
		pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);
	}
}

static void drop_spoon(t_philo *philo)
{
	if (philo->num % 2)
	{
		pthread_mutex_unlock(&philo->data->mutex[philo->num]);
		if (philo->num == 1)
			pthread_mutex_unlock(&philo->data->mutex[philo->data->num_philos]);
		else
			pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mutex[philo->num]);
		pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
	}
}

static void eating(t_philo *philo)
{
	philo->eats++;
	philo->last_meal = time_elapsed();
	// printf("\x1B[43m\x1B[31mphilo: %d \x1B[0m ", philo->num);
	// printf(UYELLOW "comidas: %d\n" RESET, philo->eats);
	usleep(philo->data->t_sleep);
}

void	*processes(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		take_spoon(philo);
		print_does(philo, TAKE);
		print_does(philo, EAT);
		eating(philo);
		print_does(philo, SLEEP);
		drop_spoon(philo);
		usleep(philo->data->t_sleep);
		print_does(philo, THINK);
	}
	return (NULL);
}
