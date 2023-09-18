/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:31:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/18 17:43:38 by nmota-bu         ###   ########.fr       */
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
	static uint64_t	start = 0;

	if (start == 0)
		start = times_ms();
	return (times_ms() - start);
}

void	my_sleep(uint64_t wait)
{
	wait += time_elapsed();
	while (wait >= time_elapsed())
		usleep(100);
}
