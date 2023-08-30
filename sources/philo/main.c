/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:38:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/30 13:45:04 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "error.h"
#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>

void	err_argc(void)
{
	ft_message(WARNING, "Missing arguments:");
	ft_message(DANGER,
				"./philo [number_philosophers] [time_to_die] [time_to_eat] "
				"[time_to_sleep] [number_of_times_each_philosopher_must_eat]");
	printf("\n");
	ft_message(INFO,
				"number_of_philosophers: The number of philosophers and also the number of forks\n"
				" time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the sim- ulation,
					they die");
}

int	main(int argc, char *argv[])
{
	(void)argv;
	if (argc < 5 || argc > 6)
	{
		err_argc();
		return (EXIT_FAILURE);
	}
	utils();
	return (0);
}
