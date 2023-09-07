/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiempo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:52:35 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/07 18:01:12 by nmota-bu         ###   ########.fr       */
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
	// return ((time.tv_sec * (uint64_t)1000) + (time.tv_usec / 1000));
	return ((uint64_t)(time.tv_sec) * 1000 + (uint64_t)(time.tv_usec) / 1000);
}

uint64_t	time_elapsed(void)
{
	static uint64_t start = 0; // Inicializar start al inicio del programa
	if (start == 0)
		start = times_ms();
	return (times_ms() - start);
}

int	main(void)
{
	while (42)
	{
		printf("%04llu\n", time_elapsed());
		usleep(100000);
	}
}
