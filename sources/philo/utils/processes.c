/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/07 13:22:14 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "philosophers.h"
#include <stdbool.h>
#include <stdio.h>

// void	print_ptr(t_philo *ph)
// {
// 	(void)ph;
// 	// printf("loop\n");
// 	printf(MAGENTA "Philos: %d\n", ph->num);
// 	printf(MAGENTA "%d:Philo die\n" RESET, ph->data->t_die);
// 	printf("Mutex: %p\n", (void *)&ph->data->mutex[ph->num - 1]);
// }

void	choose_spoon(int *right, int *left, t_philo *philo)
{
	if (philo->num % 2)
	{
		*left = philo->num;
		if (philo->num == 1)
			*right = philo->data->num_philos;
		else
			*right = (philo->num - 1);
	}
	else
	{
		*left = philo->num;
		*right = (philo->num - 1);
	}
}

void	print_does(t_philo *philo, int type)
{
	char	*mss;

	mss = (char *)g_party[type];
	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%llums " RESET, (unsigned long long)time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s", mss);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	take_spoon(t_philo *philo)
{
	int	s_right;
	int	s_left;

	choose_spoon(&s_right, &s_left, philo);
	pthread_mutex_lock(&philo->data->mutex[philo->num]);
	print_does(philo, TAKE);
	pthread_mutex_unlock(&philo->data->mutex[philo->num]);
}

void	eating(t_philo *philo)
{
	philo->eats++;
	philo->last_meal = time_elapsed();
	usleep(philo->data->t_sleep);
}

void	*processes(void *arg)
{
	t_philo	*philo;

	// uint64_t	start;
	philo = (t_philo *)arg;
	// start = times_ms();
	while (42)
	{
		// printf("%4llums,\n", time_elapsed(start));
		take_spoon(philo);
		print_does(philo, EAT);
		// pthread_mutex_unlock(&philo->data->m_print);
		// printf(CYAN "%04llums #%02d " RESET, time_elapsed(start),
		// philo->num);
		// printf(ORANGE "\xF0\x9F\x8D\x95 Is eating\n" RESET);
		pthread_mutex_unlock(&philo->data->m_print);
		eating(philo);
	}
	return (NULL);
}
