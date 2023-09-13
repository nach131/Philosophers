/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:31:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/13 12:26:20 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

uint64_t	times_ms(void)
{
	static struct timeval	time;

	gettimeofday(&time, NULL);
	return ((uint64_t)(time.tv_sec) * 1000 + (uint64_t)(time.tv_usec) / 1000);
}

uint64_t	time_elapsed(void)
{
	// TODO cuidado que no se ponga start = 0 en otra linea
	// static uint64_t start = 0; // Inicializar start al inicio del programa
	static uint64_t start = 0; // Inicializar start al inicio del programa
	if (start == 0)
		start = times_ms();
	return (times_ms() - start);
}
