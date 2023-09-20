/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:58:27 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/20 22:19:16 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"
#include "error.h"
#include "philosophers.h"
#include <stdio.h>

void	argc_none(int argc)
{
	if (argc > 1)
		printf("\x1B[42m\x1B[1;30m\x1B%s\x1B[0m ", g_mss[0]);
	else
		printf("\x1B[41m\x1B[1m\x1B%s\x1B[0m ", g_mss[0]);
	if (argc > 2)
		printf("\x1B[42m\x1B[1;30m\x1B%s\x1B[0m ", g_mss[1]);
	else
		printf("\x1B[41m\x1B[1m\x1B%s\x1B[0m ", g_mss[1]);
	if (argc > 3)
		printf("\x1B[42m\x1B[1;30m\x1B%s\x1B[0m ", g_mss[2]);
	else
		printf("\x1B[41m\x1B[1m\x1B%s\x1B[0m ", g_mss[2]);
	printf("\x1B[41m\x1B[1m\x1B%s\x1B[0m ", g_mss[3]);
	printf("\x1B[43m\x1B[31m\x1B%s\x1B[0m \n", g_mss[4]);
}

void	err_argc(int argc)
{
	ft_message(DANGER, "Missing arguments:");
	argc_none(argc);
	ft_message(INFO, (char *)g_args[0]);
	ft_message(INFO, (char *)g_args[1]);
	ft_message(INFO, (char *)g_args[2]);
	ft_message(INFO, (char *)g_args[3]);
	ft_message(INFO, (char *)g_args[4]);
	printf(ICYAN "\t    *(Minimum two philosophers).\n" RESET);
	printf(ICYAN "\t   **(Time in milliseconds).\n" RESET);
}
