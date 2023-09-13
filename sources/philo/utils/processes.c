/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/13 15:43:59 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "error.h"
#include "philosophers.h"
#include <stdbool.h>
#include <stdio.h>

void print_does(t_philo *philo, int type, int spoon)
{
	char	*mss;

	if (philo->data->is_dead)
		return ;
	mss = (char *)g_party[type];
	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	if (spoon)
		printf("%s[%d]\n", mss, spoon);
	else
		printf("%s\n", mss);
	pthread_mutex_unlock(&philo->data->m_print);
}

static void take_spoon(t_philo *philo)
{
	if (philo->num % 2)
	{

		pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);

		// print_does(philo, TAKE, (philo->num - 1));

		pthread_mutex_lock(&philo->data->m_print);
		printf(CYAN "%04llums " RESET, time_elapsed());
		printf(MAGENTA "#%02d " RESET, philo->num);
		printf("%s[%d]\n", g_party[TAKE], philo->num - 1);
		pthread_mutex_unlock(&philo->data->m_print);

		if (philo->num == 1)
		{
			pthread_mutex_lock(&philo->data->mutex[philo->data->num_philos - 1]);

			// print_does(philo, TAKE, (philo->data->num_philos - 1));

			pthread_mutex_lock(&philo->data->m_print);
			printf(CYAN "%04llums " RESET, time_elapsed());
			printf(MAGENTA "#%02d " RESET, philo->num);
			printf("%s[%d]\n", g_party[TAKE], philo->data->num_philos - 1);
			pthread_mutex_unlock(&philo->data->m_print);
		}
		else
		{
			pthread_mutex_lock(&philo->data->mutex[philo->num - 2]);

			// print_does(philo, TAKE, (philo->num - 2));

			pthread_mutex_lock(&philo->data->m_print);
			printf(CYAN "%04llums " RESET, time_elapsed());
			printf(MAGENTA "#%02d " RESET, philo->num);
			printf("%s[%d]\n", g_party[TAKE], philo->num - 2);
			pthread_mutex_unlock(&philo->data->m_print);
		}
	}
	else
	{

		pthread_mutex_lock(&philo->data->mutex[philo->num - 2]);

		// print_does(philo, TAKE, (philo->num - 2));

		pthread_mutex_lock(&philo->data->m_print);
		printf(CYAN "%04llums " RESET, time_elapsed());
		printf(MAGENTA "#%02d " RESET, philo->num);
		printf("%s[%d]\n", g_party[TAKE], philo->num - 2);
		pthread_mutex_unlock(&philo->data->m_print);

		pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);

		// print_does(philo, TAKE, (philo->num - 1));

		pthread_mutex_lock(&philo->data->m_print);
		printf(CYAN "%04llums " RESET, time_elapsed());
		printf(MAGENTA "#%02d " RESET, philo->num);
		printf("%s[%d]\n", g_party[TAKE], philo->num - 1);
		pthread_mutex_unlock(&philo->data->m_print);
	}
	//
	//=========================================================================
	// if (philo->num == 1)
	// {
	// 	pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);
	// 	pthread_mutex_lock(&philo->data->mutex[philo->data->num_philos - 1]);
	// }
	// else
	// {
	// 	pthread_mutex_lock(&philo->data->mutex[philo->num - 1]);
	// 	pthread_mutex_lock(&philo->data->mutex[philo->num - 2]);
	// }
	//
	//=========================================================================
	// printf("Num: %d\n", philo->num);
	//=========================================================================
	// pthread_mutex_lock(&philo->data->m_print);
	// printf(CYAN "%04llums " RESET, time_elapsed());
	// printf(MAGENTA "#%02d " RESET, philo->num);
	// printf("%s[%d]\n", g_party[TAKE], philo->num);
	// pthread_mutex_unlock(&philo->data->m_print);
	//=========================================================================
	// pthread_mutex_lock(philo->data->mutex + spoon_l);
	//=========================================================================
	// pthread_mutex_lock(&philo->data->m_print);
	// printf(CYAN "%04llums " RESET, time_elapsed());
	// printf(MAGENTA "#%02d " RESET, philo->num);
	// if (philo->num == 1)
	// 	printf("%s[%d]\n", g_party[TAKE], philo->data->num_philos);
	// else
	// 	printf("%s[%d]\n", g_party[TAKE], philo->num - 1);
	// pthread_mutex_unlock(&philo->data->m_print);
}

static void	drop_spoon(t_philo *philo)
{
	// if (philo->num == 1)
	// {
	// 	pthread_mutex_unlock(&philo->data->mutex[philo->data->num_philos - 1]);
	// 	pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
	// }
	// else
	// {
	// 	pthread_mutex_unlock(&philo->data->mutex[philo->num - 2]);
	// 	pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
	// }
	if (philo->num % 2)
	{
		pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
		if (philo->num == 1)
			pthread_mutex_unlock(&philo->data->mutex[philo->data->num_philos - 1]);
		else
			pthread_mutex_unlock(&philo->data->mutex[philo->num - 2]);
	}
	else
	{
		pthread_mutex_unlock(&philo->data->mutex[philo->num - 1]);
		pthread_mutex_unlock(&philo->data->mutex[philo->num - 2]);
	}
}

static void	eating(t_philo *philo)
{
	usleep(philo->data->t_eat * 1000);
	philo->eats++;
	philo->last_meal = time_elapsed();
	// printf("Eating: %d\t%d\t%llu\n", philo->num, philo->eats,
	// philo->last_meal);
}

void	*processes(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	// printf("Before: %d\n", philo->num);
	pthread_mutex_lock(&philo->data->m_print);
	pthread_mutex_unlock(&philo->data->m_print);
	// printf("After: %d\n", philo->num);
	while (1)
	{
		if (is_die(philo->data))
			break ;
		// printf("Philo num: %d\n", philo->num);
		take_spoon(philo);
		// print_does(philo, TAKE);
		print_does(philo, EAT, 0);
		eating(philo);
		drop_spoon(philo);
		print_does(philo, SLEEP, 0);
		usleep(philo->data->t_sleep * 1000);
		print_does(philo, THINK, 0);
	}
	return (NULL);
}
