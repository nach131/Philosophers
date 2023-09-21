/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:38:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/21 18:59:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "mylibft_bonus.h"
#include "philo_bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// static void	free_data(t_data *data)
// {
// 	if (data->mutex)
// 		free(data->mutex);
// 	if (data->id)
// 		free(data->id);
// 	if (data->philo)
// 		free(data->philo);
// }

// static void destroy(t_data *data)
// {
// 	int i;

// 	i = -1;
// 	while (++i < data->num_philos)
// 	{
// 		pthread_mutex_destroy(&data->mutex[i]);
// 		pthread_join(data->id[i], NULL);
// 	}
// }

int kkk(t_data *data)
{

	char *fork_name;
	int i;
	i = -1;
	while (++i < data->num_philos)
	{
		fork_name = ft_strjoin("fork_", ft_itoa(i));
	}

	data->spoon = sem_open("sem", O_CREAT | O_EXCL, 0644, data->num_philos);
	if (data->spoon == (sem_t *)-1)
	{
		printf("esto\n");
		return (1);
	}
	return (0);
}

int main(int argc, char *argv[])
{
	t_data *data;

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
		// free_data(data);
		free(data);
		return (EXIT_FAILURE);
	}
	// waiting(data);
	// pthread_mutex_destroy(&data->m_print);
	// destroy(data);
	// free_data(data);
	free(data);
	return (0);
}
