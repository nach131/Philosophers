/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:31:38 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/07 13:08:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

uint64_t	times_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((uint64_t)(time.tv_sec) * 1000 + (uint64_t)(time.tv_usec) / 1000);
}

uint64_t	time_elapsed(uint64_t start)
{
	uint64_t	time_now;

	time_now = times_ms();
	return (time_now - start);
}

// uint64_t	gettimeofday_ms(void)
// {
// 	static struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
// }

// uint64_t	times_ms(void)
// {
// 	static uint64_t	start;

// 	start = 0;
// 	if (start == 0)
// 		start = gettimeofday_ms();
// 	return (gettimeofday_ms() - start);
// }
