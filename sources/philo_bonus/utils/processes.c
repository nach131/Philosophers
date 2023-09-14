/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/14 23:23:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "error.h"
#include "philo_bonus.h"
#include <stdbool.h>
#include <stdio.h>

void print_does(t_philo *philo, int type)
{
	char *mss;

	if (philo->data->is_dead)
		return;
	mss = (char *)g_party[type];
	sem_wait(philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s\n", mss);
	sem_post(philo->data->m_print);
}

//=========================================================================
// void	eat(PhilosopherData *philosopher)
// {
// 	printf("Philosopher %d is eating.\n", philosopher->id);
// 	usleep(200000); // Simulate eating time in microseconds
// 	philosopher->meals_eaten++;
// }

void think(t_philo *philo)
{
	// printf("Philosopher %d is thinking.\n", philo->num);

	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s\n", g_party[THINK]);
	usleep(philo->data->t_sleep); // Simulate thinking time in microseconds
}

static void take_spoon(t_philo *philo)
{
	if (philo->num % 2)
	{
		sem_wait(philo->data->forks[philo->num]);
		print_does(philo, TAKE);
		if (philo->num == 0)
			sem_wait(philo->data->forks[philo->num]);
		else
			sem_wait(philo->data->forks[philo->num - 1]);
		print_does(philo, TAKE);
	}
	else
	{
		sem_wait(philo->data->forks[philo->num - 1]);
		print_does(philo, TAKE);
		sem_wait(philo->data->forks[philo->num]);
		print_does(philo, TAKE);
	}
}

void *philosopher_life(void *arg)
{
	t_philo *philo;

	// PhilosopherData *philosopher = (PhilosopherData *)arg;
	philo = (t_philo *)arg;
	while (philo->eats < philo->data->num_meals)
	// while (philosopher->meals_eaten < MAX_MEALS)
	{
		take_spoon(philo);
		// think(philo);
		// sem_wait(philo->data->forks[philo->num + 1 % philo->data->num_philos]);
		//===============falta==========================================================
		// eat(philosopher);
		// sem_post(forks[philosopher->id]);
		// sem_post(forks[(philosopher->id + 1) % NUM_PHILOSOPHERS]);
	}
	return (NULL);
}

// take_fork
// all_eating
// drop_fork
// sleep
// think
