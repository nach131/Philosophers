/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/20 16:32:40 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "error.h"
#include "philosophers.h"
#include <stdbool.h>
#include <stdio.h>

static void	choose_spoon(t_philo *philo, int *spoon_l, int *spoon_r)
{
	*spoon_l = philo->num - 1;
	*spoon_r = philo->num % philo->data->num_philos;
}

static int	drop_spoon(t_philo *philo)
{
	if (philo->data->is_dead || philo->eats == philo->data->num_meals)
		return (1);
	pthread_mutex_unlock(philo->data->mutex + (philo->num
				% philo->data->num_philos));
	pthread_mutex_unlock(philo->data->mutex + (philo->num - 1));
	print_does(philo, SLEEP);
	return (0);
}

static int	take_spoon(t_philo *philo)
{
	int	spoon_l;
	int	spoon_r;

	if (philo->data->is_dead || philo->eats == philo->data->num_meals)
		return (1);
	choose_spoon(philo, &spoon_l, &spoon_r);
	pthread_mutex_lock(philo->data->mutex + spoon_l);
	print_does(philo, TAKE);
	pthread_mutex_lock(philo->data->mutex + spoon_r);
	print_does(philo, TAKE);
	return (0);
}

static int	eating(t_philo *philo)
{
	if (philo->data->is_dead || philo->eats == philo->data->num_meals
		|| philo->data->num_philos == 1)
		return (1);
	if (philo->eats < philo->data->num_meals)
	{
		philo->eats++;
		philo->last_meal = time_elapsed();
		my_sleep(philo->data->t_eat);
	}
	print_does(philo, EAT);
	return (0);
}

static int	sleeping(t_philo *philo)
{
	if (philo->data->is_dead || philo->eats == philo->data->num_meals)
		return (1);
	my_sleep(philo->data->t_sleep);
	print_does(philo, THINK);
	return (0);
}

void	*processes(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->m_print);
	pthread_mutex_unlock(&philo->data->m_print);
	if (!(philo->num % 2))
		my_sleep(philo->data->t_eat);
	while (42)
	{
		// if (philo->data->is_dead || philo->eats == philo->data->num_meals
		// 	|| philo->data->num_philos == 1)
		// 	break ;
		if (take_spoon(philo) || eating(philo) || drop_spoon(philo)|| sleeping(philo))
			break ;
		// print_does(philo, EAT);
		// eating(philo);
		// drop_spoon(philo);
		// print_does(philo, SLEEP);
	}
	return (NULL);
}
