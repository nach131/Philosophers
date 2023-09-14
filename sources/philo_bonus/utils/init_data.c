/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/14 23:23:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mylibft.h"
#include "philo_bonus.h"
#include <limits.h>
#include <stdlib.h>

void create_fork(t_data *dt)
{
	pid_t pid;
	int i;

	i = -1;
	while (++i < dt->num_philos)
	{
		pid = fork();
		if (pid == 0)
		{
			dt->philo[i].num = i;
			dt->philo[i].data = dt;
			philosopher_life(&dt->philo[i]);
			exit(0);
		}
	}

	i = -1;
	//==========para esperar a que se cumplan todos los forks===========================================================
	// while (++i < dt->num_philos)
	// 	waitpid(pid, NULL, 0);
}

void static init_fork_mutex(t_data *dt)
{
	int i;
	char *fork_name;

	i = -1;
	dt->forks = malloc(sizeof(sem_t) * dt->num_philos);
	dt->m_print = malloc(sizeof(sem_t) * 1);
	while (++i < dt->num_philos)
	{
		fork_name = ft_strjoin("fork_", ft_itoa(i));
		dt->forks[i] = sem_open(fork_name, O_CREAT, 0644, 1);
		free(fork_name);
	}
	dt->m_print = sem_open("/print_mutex", O_CREAT, 0644, 1);
	create_fork(dt);
}

int init_data(int argc, char *argv[], t_data *data)
{
	data->num_philos = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->philo = ft_calloc(data->num_philos, sizeof(t_philo));
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	else
		data->num_meals = INT_MAX;
	if (data->num_philos < 0 || data->t_die < 0 || data->t_eat < 0 || data->t_sleep < 0 || data->num_meals < 0)
	{
		ft_message(DANGER, "All arguments have to be positive.");
		return (1);
	}
	else if (data->num_philos <= 1)
	{
		ft_message(DANGER, "Minimum two philosophers.");
		return (1);
	}
	init_fork_mutex(data);
	return (0);
}
