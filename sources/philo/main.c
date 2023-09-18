/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:38:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/18 10:25:38 by nmota-bu         ###   ########.fr       */
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

static void	err_argc(void)
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

static void	free_data(t_data *data)
{
	if (data->mutex)
		free(data->mutex);
	if (data->id)
		free(data->id);
	if (data->philo)
		free(data->philo);
}

static void	destroy(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
	{
		pthread_mutex_destroy(&data->mutex[i]);
		pthread_join(data->id[i], NULL);
	}
	pthread_mutex_destroy(&data->m_print);
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
	waiting(data);
	destroy(data);
	free_data(data);
	free(data);
	return (0);
}
