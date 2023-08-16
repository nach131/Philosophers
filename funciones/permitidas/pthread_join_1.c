/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_join_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 17:37:51 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/01 17:50:33 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"

void	*funcion_hilo(void *arg)
{
	int	i;

	i = 0;
	while (i++ < 15)
	{
		sleep(1);
		printf(RED "\t%d Tu turno\n", i);
	}
	pthread_exit(NULL);
}

void	myTurno(void)
{
	int	i;

	i = 0;
	while (i++ < 10)
	{
		sleep(1);
		printf(GREEN "%d Mi turno\n", i);
	}
}

int	main(void)
{
	pthread_t	id_hilo;

	pthread_create(&id_hilo, NULL, funcion_hilo, NULL);
	myTurno();
	// pthread_join(id_hilo, (void **)&funcion_hilo);
	pthread_join(id_hilo, NULL);
	pthread_exit(NULL);
}
