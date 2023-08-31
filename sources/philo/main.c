/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 22:38:49 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/31 11:46:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "colors.h"
#include "error.h"
#include "philosophers.h"
#include <stdio.h>
#include <stdlib.h>
#include "mylibft.h"

void	err_argc(void)
{
	ft_message(DANGER, "Missing arguments:");
	printf("\x1B[41m\x1B[1m\x1B%s\x1B[0m \x1B[41m\x1B[1m\x1B%s\x1B[0m "
		   "\x1B[41m\x1B[1m\x1B%s\x1B[0m \x1B[41m\x1B[1m\x1B%s\x1B[0m "
		   "\x1B[41m\x1B[1m\x1B%s\x1B[0m\n",
		   g_mss[0], g_mss[1], g_mss[2], g_mss[3], g_mss[4]);
	ft_message(INFO, (char *)g_args[0]);
	ft_message(INFO, (char *)g_args[1]);
	ft_message(INFO, (char *)g_args[2]);
	ft_message(INFO, (char *)g_args[3]);
	ft_message(INFO, (char *)g_args[4]);
	printf(ICYAN "\t    *(minimum two Philosophers).\n" RESET);
	printf(ICYAN "\t   **(Time in milliseconds).\n" RESET);
}

int	main(int argc, char *argv[])
{
	if (argc < 5 || argc > 6)
	{
		err_argc();
		return (EXIT_FAILURE);
	}
	if (init_data(argc, argv))
	{
		ft_message(DANGER, "All arguments have to be positive.");
		return (EXIT_FAILURE);
	}

	// utils();
	return (0);
}
