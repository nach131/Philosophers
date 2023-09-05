/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:31:55 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/05 14:42:20 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "philosophers.h"
#include <stdio.h>

void	print_ptr(t_philo *ph)
{
	(void)ph;
	// printf("loop\n");
	printf(MAGENTA "Philos: %d\n", ph->num);
	printf(MAGENTA "%d:Philo die\n" RESET, ph->data->t_die);
	printf("Mutex: %p\n", (void *)&ph->data->mutex[ph->num - 1]);
}

void	*processes(void *arg)
{
	t_philo		*ph;
	uint64_t	start;

	ph = (t_philo *)arg;
	(void)ph;
	start = times_ms();
	while (42)
	{
		printf("%4llums,\n", time_elapsed(start));
		// print_ptr(ph);
	}
	return (NULL);
}
