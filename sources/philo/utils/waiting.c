/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:51 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/12 16:10:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "philosophers.h"
#include <stdio.h>

static int	is_die(t_data *data)
{
	uint64_t	limit;
	uint64_t	timestamp;
	int			i;

	i = 0;
	while (i < data->num_philos)
	{
		limit = data->philo[i].last_meal + data->t_die / 1000;
		timestamp = time_elapsed();
		if (limit < timestamp)
		{
			printf(CYAN "%04llums " RESET, timestamp);
			printf(MAGENTA "#%02d " RESET, data->philo[i].num);
			printf("%s", g_party[DIE]);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	all_eating(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		// printf(UORANGE "\tcomidas: %d\n" RESET, data->philo[i].eats);
		// printf("philo: %d ", data->philo[i].num);
		// printf(UORANGE "comidas: %d\n" RESET, data->philo[i].eats);
		if (data->philo[i].eats < data->num_meals)
			return (0);
		i++;
	}
	return (1);
}

void	waiting(t_data *data)
{
	while (42)
	{
		if (is_die(data))
			return ;
		if (all_eating(data))
			return ;
	}
}
