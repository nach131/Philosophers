/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:07:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/31 18:02:05 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "mylibft.h"
#include "philosophers.h"
#include <stdio.h>

int	init_data(int argc, char *argv[], t_data *data)
{
	data->num_philo = ft_atoi(argv[1]);
	data->philo = ft_calloc(data->num_philo, sizeof(t_philo));
	data->t_die = ft_atoi(argv[2]) * 1000;
	data->t_eat = ft_atoi(argv[3]) * 1000;
	data->t_sleep = ft_atoi(argv[4]) * 1000;
	if (argc == 6)
		data->num_meals = ft_atoi(argv[5]);
	if (data->num_philo < 0 || data->t_die < 0 || data->t_eat < 0
		|| data->t_sleep < 0 || data->num_meals < 0)
		return (1);
	return (0);
}
