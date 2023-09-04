/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:39:35 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/04 12:13:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define ORANGE "\033[1;31m"

void put_color(int color)
{
	if (color == 0)
		printf(RED "");
	else if (color == 1)
		printf(GREEN "");
	else if (color == 2)
		printf(YELLOW "");
	else if (color == 3)
		printf(ORANGE "");
}

void *funcion_hilo(void *arg)
{
	int i;
	int hilo;

	i = 0;
	hilo = (int)(intptr_t)arg;
	while (i++ < 10)
	{
		// put_color(hilo);
		sleep(2);
		pthread_mutex_lock(&m);
		printf("\thilo #%d, Tu turno %d\n", hilo, i);
		pthread_mutex_unlock(&m);
	}
	pthread_exit(NULL);
}

int main(void)
{
	pthread_t id_hilo[4];
	pthread_mutex_t m[4];

	int hilo = -1;
	while (++hilo < 4)
		pthread_create(&id_hilo[hilo], NULL, funcion_hilo, (void *)(intptr_t)hilo);
	// pthread_exit(NULL);
	hilo = -1;
	// Espera a que los hilos terminen antes de salir del programa
	while (++hilo < 4)
		pthread_join(id_hilo[hilo], NULL);
}
