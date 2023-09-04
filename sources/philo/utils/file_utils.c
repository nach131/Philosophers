/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:00:11 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/04 11:29:03 by nmota-bu         ###   ########.fr       */
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

uint64_t time_ms(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((uint64_t)(time.tv_sec) * 1000 + (uint64_t)(time.tv_usec) / 1000);
}

// void ft_clock(void)
// {
// 	uint64_t tiempoInicio;
// 	uint64_t tiempoActual;
// 	uint64_t tiempoTranscurrido;

// 	tiempoInicio = time_ms();
// 	while (1)
// 	{
// 		tiempoActual = time_ms();
// 		tiempoTranscurrido = tiempoActual - tiempoInicio;
// 		printf("Milisegundos transcurridos: %llu\n", tiempoTranscurrido);
// 	}
// }

void	utils(void)
{
	int sit;
	uint64_t t_start;
	uint64_t time_now;
	uint64_t time_elapsed;

	t_start = time_ms();
	sit = 2;

	// while (1)
	// {
	time_now = time_ms();
	time_elapsed = time_now - t_start;
	printf(CYAN "%04llums #%02d " RESET, time_elapsed, sit);
	printf(GREEN "\xF0\x9F\xA5\x84 Has taken spoon\n" RESET);
	printf(CYAN "%04llums #%02d " RESET, time_elapsed, sit);
	printf(RED "\xE2\x98\xA0\xEF\xB8\x8F  Is died\n" RESET);
	printf(CYAN "%04llums #%02d " RESET, time_elapsed, sit);
	printf(YELLOW "\xF0\x9F\x92\xA1 Is Thinking\n" RESET);
	printf(CYAN "%04llums #%02d " RESET, time_elapsed, sit);
	printf(ORANGE "\xF0\x9F\x8D\x95 Is eating\n" RESET);
	// }
}

// printf(GREEN "\xF0\x9F\xA5\x84 Has taken spoon\n" RESET);
// 	printf(CYAN "%04llums #%02d " RESET, time_elapsed, sit);
// 	printf(RED "\xE2\x98\xA0\xEF\xB8\x8F  Is died\n" RESET);
// 	// printf(RED "\xF0\x9F\x92\x80  Is died\n" RESET);
// 	printf(CYAN "%04llums #%02d " RESET, time_elapsed, sit);
// 	printf(YELLOW "\xF0\x9F\x92\xA1 Is Thinking\n" RESET);
// 	printf(CYAN "%04llums \xF0\x9F\xA4\xA1%02d " RESET, time_elapsed,
// 		   sit);
// 	printf(ORANGE "\xF0\x9F\x8D\x95 Is eating\n" RESET);

// // printf(GREEN "\xF0\x9F\x8D\xBD  Has taken fork\n" RESET);
// // printf(RED "\xF0\x9F\x92\x80  Is died\n" RESET);
