/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/21 18:40:12 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors_bonus.h"
#include "error_bonus.h"
#include "philo_bonus.h"
#include <stdbool.h>
#include <stdio.h>

// void print_does(t_philo *philo, int type)
// {
// 	char *mss;

// 	mss = (char *)g_party[type];
// 	// sem_wait(philo->data->m_print);
// 	printf(CYAN "%04llums " RESET, time_elapsed());
// 	printf(MAGENTA "#%02d " RESET, philo->num);
// 	printf("%s\n", mss);
// 	// sem_post(philo->data->m_print);
// }

// //=========================================================================
// // void	eat(PhilosopherData *philosopher)
// // {
// // 	printf("Philosopher %d is eating.\n", philosopher->id);
// // 	usleep(200000); // Simulate eating time in microseconds
// // 	philosopher->meals_eaten++;
// // }

// void think(t_philo *philo)
// {
// 	// printf("Philosopher %d is thinking.\n", philo->num);

// 	printf(CYAN "%04llums " RESET, time_elapsed());
// 	printf(MAGENTA "#%02d " RESET, philo->num);
// 	printf("%s\n", g_party[THINK]);
// 	usleep(philo->data->t_sleep); // Simulate thinking time in microseconds
// }

// void choose_spoon(t_philo *philo, int *spoon_l, int *spoon_r)
// {
// 	*spoon_l = philo->num - 1;
// 	*spoon_r = philo->num % philo->data->num_philos;
// }

// void drop_spoon(t_philo *philo)
// {
// 	sam_post(philo->data->spoon[(philo->num % philo->data->num_philos)]);
// 	sam_post(philo->data->spoon[(philo->num - 1)]);
// }

// void take_spoon(t_philo *philo)
// {
// 	int spoon_l;
// 	int spoon_r;
// 	choose_spoon(philo, &spoon_l, &spoon_r);

// 	sem_wait(philo->data->spoon[spoon_l]);

// 	printf(CYAN "%04llums " RESET, time_elapsed());
// 	printf(MAGENTA "#%02d " RESET, philo->num);
// 	printf("%s[%d]\n", g_party[TAKE], spoon_l);

// 	// print_does(philo, TAKE);

// 	sem_wait(philo->data->spoon[spoon_r]);

// 	printf(CYAN "%04llums " RESET, time_elapsed());
// 	printf(MAGENTA "#%02d " RESET, philo->num);
// 	printf("%s[%d]\n", g_party[TAKE], spoon_l);

// 	// print_does(philo, TAKE);
// }

// void eating(t_philo *philo)
// {
// 	if (philo->eats < philo->data->num_meals)
// 	{
// 		philo->eats++;
// 		philo->last_meal = time_elapsed();
// 		my_sleep(philo->data->t_eat);
// 	}
// }

void *philosopher_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (!(philo->num % 2))
		my_sleep(philo->data->t_eat);
	// while (philo->eats < philo->data->num_meals)
	while (1)
	// while (philosopher->meals_eaten < MAX_MEALS)
	{

		printf("toma\n");
		// take_spoon(philo);
		// print_does(philo, EAT);
		// eating(philo);
		// drop_spoon(philo);

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
