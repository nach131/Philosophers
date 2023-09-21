/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/21 19:06:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"
#include "mylibft_bonus.h"
#include "philo_bonus.h"
// #include <semaphore.h>
#include <limits.h>
#include <stdlib.h>

int static init_fork_mutex(t_data *data)
{
	int i;
	int id_fork;
	t_philo *philo;

	i = -1;
	philo = ft_calloc(sizeof(sem_t), data->num_philos);
	if (!philo)
		return (1);
	while (++i < data->num_philos)
	{
		id_fork = fork();
		if (id_fork == 0)
		{
			philo[i].num = i + 1;
			philo[i].data = data;
			philosopher_life(&philo[i]);
			exit(0);
		}
		usleep(100);
	}
	i = -1;
	while (++i < data->num_philos)
		waitpid(id_fork, NULL, 0);
	free(philo);

	return (0);
}

int init_sem(t_data *data)
{
	char *fork_name;
	int i;
	i = -1;
	while (++i < data->num_philos)
	{
		fork_name = ft_strjoin("fork_", ft_itoa(i));
		data->spoon[i] = sem_open(fork_name, O_CREAT, 0644, 1);
		if (data->spoon[i] == SEM_FAILED)
			perror("Error al crear el semáforo");
		free(fork_name);
	}
	return (0);
}

int init_data(int argc, char *argv[], t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->spoon = malloc(sizeof(sem_t) * data->num_philos);
	if (!data->spoon)
		return (1);
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = INT_MAX;
	if (data->num_philos < 0 || data->t_die < 0 || data->t_eat < 0 || data->t_sleep < 0 || data->num_meals < 0)
	{
		ft_message(DANGER, "All arguments have to be positive.");
		return (1);
	}
	if (init_sem(data) || init_fork_mutex(data))
		return (1);
	return (0);
}
