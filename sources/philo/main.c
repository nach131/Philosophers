/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:38:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/26 10:18:24 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                      https://github.com/nach131                        ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "colors.h"
#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_does(t_philo *philo, int type)
{
	char	*mss;

	if (philo->data->is_dead)
		return ;
	mss = (char *)g_party[type];
	pthread_mutex_lock(&philo->data->m_print);
	printf(CYAN "%04llums " RESET, time_elapsed());
	printf(MAGENTA "#%02d " RESET, philo->num);
	printf("%s\n", mss);
	pthread_mutex_unlock(&philo->data->m_print);
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
		err_argc(argc);
		return (EXIT_FAILURE);
	}
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (EXIT_FAILURE);
	if (init_data(argc, argv, data))
	{
		free(data);
		return (EXIT_FAILURE);
	}
	if (waiting(data))
	{
		destroy(data);
		free_data(data);
		free(data);
		return (0);
	}
}
