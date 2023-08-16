/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:38:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/16 20:19:58 by nmota-bu         ###   ########.fr       */
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
	ft_message(DANGER, "[number_philosophers] [time_to_die] [time_to_eat] "
						"[time_to_sleep] [number_of_times_each_philosopher_must_eat]");
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
