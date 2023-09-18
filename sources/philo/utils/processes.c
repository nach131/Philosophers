/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/18 10:25:48 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "error.h"
#include "philosophers.h"
#include <stdbool.h>
#include <stdio.h>

void print_does(t_philo *philo, int type)
{
	char *mss;

	if (philo->data->is_dead)
		return;
	mss = (char *)g_party[type];
	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s\n", mss);
	pthread_mutex_unlock(&philo->data->m_print);
}

static void choose_spoon(t_philo *philo, int *spoon_l, int *spoon_r)
{
	int flag;

	if (philo->num % 2)
	{
		if (philo->data->num_philos % 2)
			flag = 0;
		else
			flag = 1;
	}
	else
	{
		if (philo->data->num_philos % 2)
			flag = 1;
		else
			flag = 0;
	}
	if (flag)
	{
		*spoon_l = philo->num % philo->data->num_philos;
		*spoon_r = philo->num - 1;
		return;
	}
	*spoon_l = philo->num - 1;
	*spoon_r = philo->num % philo->data->num_philos;
}

static void drop_spoon(t_philo *philo)
{
	pthread_mutex_unlock(philo->data->mutex + (philo->num % philo->data->num_philos));
	pthread_mutex_unlock(philo->data->mutex + (philo->num - 1));
}

// static void choose_spoon(t_philo *philo, int *spoon_l, int *spoon_r)
// {
// 	*spoon_l = philo->num % philo->data->num_philos;
// 	*spoon_r = (philo->num + 1) % philo->data->num_philos;

// 	// Intercambia los tenedores si el número de filósofos es par
// 	if (philo->data->num_philos % 2 == 0 && philo->num % 2 == 0)
// 	{
// 		int temp = *spoon_l;
// 		*spoon_l = *spoon_r;
// 		*spoon_r = temp;
// 	}
// }

// static void drop_spoon(t_philo *philo)
// {
// 	pthread_mutex_unlock(philo->data->mutex + (philo->num % philo->data->num_philos));
// 	pthread_mutex_unlock(philo->data->mutex + (philo->num + 1) % philo->data->num_philos);
// }

// static void take_spoon(t_philo *philo)
// {

// 	int spoon_l;
// 	int spoon_r;
// 	choose_spoon(philo, &spoon_l, &spoon_r);
// 	pthread_mutex_lock(philo->data->mutex + spoon_l);
// 	print_does(philo, TAKE);
// 	pthread_mutex_lock(philo->data->mutex + spoon_r);
// 	print_does(philo, TAKE);
// }

static void take_spoon(t_philo *philo)
{

	int spoon_l;
	int spoon_r;

	// if (philo->data->num_philos % 2)
	// {
	// 	printf(RED "impar\n" RESET);
	// 	choose_spoon_im(philo, &spoon_l, &spoon_r);
	// }
	// else
	choose_spoon(philo, &spoon_l, &spoon_r);

	pthread_mutex_lock(philo->data->mutex + spoon_l);
	// printf("\tl%d\n", spoon_l);
	// print_does(philo, TAKE);

	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s[%d]\n", g_party[TAKE], spoon_l);
	pthread_mutex_unlock(&philo->data->m_print);

	pthread_mutex_lock(philo->data->mutex + spoon_r);
	// printf("\tr%d\n", spoon_r);
	// print_does(philo, TAKE);
	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s[%d]\n", g_party[TAKE], spoon_r);
	pthread_mutex_unlock(&philo->data->m_print);
}

static void	eating(t_philo *philo)
{
	if (philo->eats < philo->data->num_meals)
	{
		philo->eats++;
		philo->last_meal = time_elapsed();
		usleep(philo->data->t_eat * 1000);
	}
}

void *processes(void *arg)
{
	t_philo *philo;

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
