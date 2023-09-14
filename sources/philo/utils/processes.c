/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/14 17:42:05 by nmota-bu         ###   ########.fr       */
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

	if (philo->data->is_dead)
		return ;
	mss = (char *)g_party[type];
	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s\n", mss);
	pthread_mutex_unlock(&philo->data->m_print);
}

static void	take_spoon(t_philo *philo)
{
	if (philo->num % 2)
	{
		pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);
		print_does(philo, TAKE);
		if (philo->num == 1)
			pthread_mutex_lock(&philo->data->mutex[philo->data->num_philos
				- 1]);
		else
			pthread_mutex_lock(&philo->data->mutex[philo->num - 2]);
		print_does(philo, TAKE);
	}
	else
	{
		pthread_mutex_lock(&philo->data->mutex[philo->num - 2]);
		print_does(philo, TAKE);
		pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);
		print_does(philo, TAKE);
	}
}

static void	drop_spoon(t_philo *philo)
{
	if (philo->num % 2)
	{
		pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
		if (philo->num == 1)
			pthread_mutex_unlock(&philo->data->mutex[philo->data->num_philos
				- 1]);
		else
			pthread_mutex_unlock(&philo->data->mutex[philo->num - 2]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mutex[philo->num - 2]);
		pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
	}
}

static void	eating(t_philo *philo)
{
	if (philo->eats < philo->data->num_meals)
	{
		usleep(philo->data->t_eat * 1000);
		philo->eats++;
		philo->last_meal = time_elapsed();
	}
}

void	*processes(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->m_print);
	pthread_mutex_unlock(&philo->data->m_print);
	while (1)
	{
		if (philo->data->is_dead || philo->eats == philo->data->num_meals)
			break ;
		take_spoon(philo);
		print_does(philo, EAT);
		eating(philo);
		drop_spoon(philo);
		print_does(philo, SLEEP);
		usleep(philo->data->t_sleep * 1000);
		print_does(philo, THINK);
	}
	return (NULL);
}
