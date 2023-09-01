/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:00:11 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/01 18:11:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include "philosophers.h"
#include <colors.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

// 4,294,967,295 milisegundos / 60,000 = 71,582.78825 minutos

uint32_t	gettimeofday_ms(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (uint32_t)1000) + (time.tv_usec / 1000));
}

uint32_t	timestamp_in_ms(void)
{
	static uint32_t	start;

	start = 0;
	if (start == 0)
		start = gettimeofday_ms();
	return (gettimeofday_ms() - start);
}

void	utils(void)
{
	int	sit;

	sit = 2;
	// printf("%04lld %02d\e[1;31m has taken fork\e[0m\n",
	// 		timestamp_in_ms(),	sit);
	printf(CYAN "%04ums %02d " RESET, timestamp_in_ms(), sit);
	// printf(GREEN "\xF0\x9F\x8D\xBD  Has taken fork\n" RESET);
	printf(GREEN "\xF0\x9F\xA5\x84 Has taken spoon\n" RESET);
	printf(CYAN "%04ums %02d " RESET, timestamp_in_ms(), sit);
	printf(RED "\xE2\x98\xA0\xEF\xB8\x8F  Is died\n" RESET);
	printf(CYAN "%04ums %02d " RESET, timestamp_in_ms(), sit);
	printf(YELLOW "\xF0\x9F\x92\xA1 Is Thinking\n" RESET);
	printf(CYAN "%04ums %02d " RESET, timestamp_in_ms(), sit);
	printf(ORANGE "\xF0\x9F\x8D\x95 Is eating\n" RESET);
}
