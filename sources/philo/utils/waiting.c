/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:22:51 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/14 13:39:51 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "philosophers.h"
#include <stdio.h>

int	is_die(t_data *data)
{
	uint64_t	limit;
	uint64_t	timestamp;
	int			i;

	i = 0;
	while (i < data->num_philos)
	{
		limit = data->philo[i].last_meal + data->t_die;
		timestamp = time_elapsed();
		if (limit < timestamp)
		{
			print_does(&data->philo[i], DIE);
			data->is_dead = 1;
			return (1);
		}
		i++;
	}
	return (0);
}

int	all_eating(t_data *data)
{
	int	i;
	int	flag;

	flag = 0;
	i = -1;
	while (++i < data->num_philos)
	{
		if (data->philo[i].eats < data->num_meals)
			flag = 0;
		else
			flag = 1;
		if (!flag)
			return (0);
	}
	return (1);
}

void	waiting(t_data *data)
{
	while (42)
	{
		if (is_die(data) || all_eating(data))
			return ;
	}
}
