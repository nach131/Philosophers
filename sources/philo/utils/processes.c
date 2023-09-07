/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/06 15:41:59 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "philosophers.h"
#include <stdbool.h>
#include <stdio.h>

void	print_ptr(t_philo *ph)
{
	(void)ph;
	// printf("loop\n");
	printf(MAGENTA "Philos: %d\n", ph->num);
	printf(MAGENTA "%d:Philo die\n" RESET, ph->data->t_die);
	printf("Mutex: %p\n", (void *)&ph->data->mutex[ph->num - 1]);
}

void	choose_spoon(int *right, int *left, t_philo *philo)
{
	if (philo->num % 2)
	{
		*left = philo->num;
		if (philo->num == 1)
			*right = philo->data->num_philos;
		else
			*right = (philo->num - 1);
		// printf(ORANGE "Philo #%d, r:%d, l:%d\n" RESET, philo->num, *right,
		// 		*left);
	}
	else
	{
		*left = philo->num;
		*right = (philo->num - 1);
		// printf(CYAN "Philo #%d, r:%d, l:%d\n" RESET, philo->num, *right,
		// *left);
	}
}

void	take_spoon(t_philo *philo, uint64_t start)
{
	int	s_right;
	int	s_left;

	choose_spoon(&s_right, &s_left, philo);
	pthread_mutex_lock(&philo->data->mutex[philo->num]);
	printf(CYAN "%04llums #%02d " RESET, time_elapsed(start), philo->num);
	printf(GREEN "\xF0\x9F\xA5\x84 Has taken spoon\n" RESET);
	pthread_mutex_unlock(&philo->data->mutex[philo->num]);
}

void	*processes(void *arg)
{
	t_philo		*philo;
	uint64_t	start;

	philo = (t_philo *)arg;
	start = times_ms();
	while (42)
	{
		// printf("%4llums,\n", time_elapsed(start));
		take_spoon(philo, start);
	}
	return (NULL);
}
