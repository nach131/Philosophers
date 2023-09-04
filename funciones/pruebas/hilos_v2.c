/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilos_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:39:35 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/04 12:32:09 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define ORANGE "\033[1;31m"

typedef struct s_data
{
	pthread_t id_hilo[4];
	pthread_mutex_t m[4];
	int hilo;

} t_data;

void *funcion_hilo(void *arg)
{
	int i;
	t_data *data; // Debes recibir un puntero a la estructura t_data

	data = (t_data *)arg;
	i = 0;
	while (i++ < 10)
	{
		sleep(2);
		pthread_mutex_lock(&data->m[data->hilo]); // Debes utilizar el mutex correspondiente
		printf("\thilo #%d, Tu turno %d\n", data->hilo, i);
		pthread_mutex_unlock(&data->m[data->hilo]);
	}
	pthread_exit(NULL);
}

int main(void)
{

	t_data data;

	data.hilo = -1;
	// Inicializa los mutexes
	for (int i = 0; i < 4; i++)
	{
		pthread_mutex_init(&data.m[i], NULL);
	}
	while (++data.hilo < 4)
		pthread_create(&data.id_hilo[data.hilo], NULL, funcion_hilo, (void *)&data); // Pasa un puntero a t_data
	data.hilo = -1;
	// Espera a que los hilos terminen antes de salir del programa
	while (++data.hilo < 4)
		pthread_join(data.id_hilo[data.hilo], NULL);
	// Destruye los mutexes
	for (int i = 0; i < 4; i++)
	{
		pthread_mutex_destroy(&data.m[i]);
	}
	return 0;
}
