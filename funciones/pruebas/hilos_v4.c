/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilos_v4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:17:15 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/04 13:45:22 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EJECUTA 4 HILOS CON COLRES DIFERENTES PERO TODOS A LA VEZ

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h> // Agrega esta línea para gettimeofday

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define ORANGE "\033[1;31m"
#define RESET "\033[0m"

typedef struct s_data
{
	pthread_t id_hilo;
	pthread_mutex_t mutex;
	int hilo;
	char *color;
} t_data;

uint64_t time_ms(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return ((uint64_t)(time.tv_sec) * 1000 + (uint64_t)(time.tv_usec) / 1000);
}

void time_elapsed(uint64_t *inicio, uint64_t *transcurrido)
{
	uint64_t tiempoActual = time_ms();
	*transcurrido = tiempoActual - *inicio;
}

void *funcion_hilo(void *arg)
{
	int i;
	t_data *data = (t_data *)arg;
	uint64_t tiempoInicio, tiempoTranscurrido;

	i = 0;
	tiempoInicio = time_ms(); // Obtener el tiempo de inicio
	while (42)
	{
		i++;
		sleep(2);
		pthread_mutex_lock(&data->mutex);
		time_elapsed(&tiempoInicio, &tiempoTranscurrido); // Calcular tiempo transcurrido
		printf("%s\thilo #%d, Tu turno %d, Tiempo transcurrido: %llu ms%s\n", data->color, data->hilo, i, tiempoTranscurrido, RESET);
		pthread_mutex_unlock(&data->mutex);
	}
	pthread_exit(NULL);
}

int main(void)
{
	t_data data[4];
	char *colores[] = {RED, GREEN, YELLOW, ORANGE};

	for (int i = 0; i < 4; i++)
	{
		data[i].hilo = i;
		data[i].color = colores[i];
		pthread_mutex_init(&data[i].mutex, NULL);
		pthread_create(&data[i].id_hilo, NULL, funcion_hilo, &data[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		// Espera a que los hilos terminen antes de salir del programa
		pthread_join(data[i].id_hilo, NULL);
		// Destruye los mutexes
		pthread_mutex_destroy(&data[i].m);
	}

	return 0;
}

// hilo #2, Tu turno 1, Tiempo transcurrido: 2004 ms
// hilo #0, Tu turno 1, Tiempo transcurrido: 2004 ms
// hilo #1, Tu turno 1, Tiempo transcurrido: 2004 ms
// hilo #3, Tu turno 1, Tiempo transcurrido: 2004 ms
// hilo #2, Tu turno 2, Tiempo transcurrido: 4006 ms
// hilo #1, Tu turno 2, Tiempo transcurrido: 4006 ms
// hilo #0, Tu turno 2, Tiempo transcurrido: 4006 ms
