/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:38:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/05 12:51:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "colors.h"
#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	err_argc(void)
{
	ft_message(DANGER, "Missing arguments:");
	printf("\x1B[41m\x1B[1m\x1B%s\x1B[0m \x1B[41m\x1B[1m\x1B%s\x1B[0m "
			"\x1B[41m\x1B[1m\x1B%s\x1B[0m \x1B[41m\x1B[1m\x1B%s\x1B[0m "
			"\x1B[41m\x1B[1m\x1B%s\x1B[0m\n",
			g_mss[0],
			g_mss[1],
			g_mss[2],
			g_mss[3],
			g_mss[4]);
	ft_message(INFO, (char *)g_args[0]);
	ft_message(INFO, (char *)g_args[1]);
	ft_message(INFO, (char *)g_args[2]);
	ft_message(INFO, (char *)g_args[3]);
	ft_message(INFO, (char *)g_args[4]);
	printf(ICYAN "\t    *(Minimum two philosophers).\n" RESET);
	printf(ICYAN "\t   **(Time in milliseconds).\n" RESET);
}

void	free_data(t_data *data)
{
	if (data->mutex)
		free(data->mutex);
	if (data->id)
		free(data->id);
	if (data->philo)
		free(data->philo);
}

void	print_all(t_data *data)
{
	int	i;

	i = 0;
	printf("-----------\n");
	printf(RED "philos: %d\n", data->num_philos);
	printf("die: %d\n", data->t_die);
	printf("eat: %d\n", data->t_eat);
	printf("sleep: %d\n", data->t_sleep);
	if (data->num_meals)
		printf("meals: %d\n" RESET, data->num_meals);
	while (i < data->num_philos) // Cambiar data->philo[i] por data->num_philo
	{
		printf(RED "philo num: %d\n", data->philo[i].num);
		printf(ORANGE "\tlast_meal: %d, num eats: %d\n" RESET,
				data->philo->last_meal,
				data->philo->eats);
		// Acceder a num dentro de la estructura t_philo
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc < 5 || argc > 6)
	{
		err_argc();
		return (EXIT_FAILURE);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (init_data(argc, argv, data))
	{
		free_data(data);
		free(data);
		return (EXIT_FAILURE);
	}
	usleep(100000000);

	//=========================================================================
	// print_all(data);
	//=========================================================================
	// start_program(data);
	// utils();
	free_data(data);
	free(data);
	return (0);
}
