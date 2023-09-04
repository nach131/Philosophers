/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilos_v5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 13:38:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/04 13:38:59 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// EJECUTA 4 HILOS CON COLORES DIFERENTES Y EN DIFERENTES TURNOS

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define ORANGE "\033[1;31m"
#define RESET "\033[0m"

typedef struct s_data
{
	pthread_t id_hilo;
	pthread_mutex_t m;
	int hilo;
	char *color;
	int turno; // Nuevo campo para controlar el turno
} t_data;

pthread_mutex_t turno_mutex; // Mutex para controlar el turno
int turno_actual = 0;		 // Variable global para el turno actual

void *funcion_hilo(void *arg)
{
	int i;
	t_data *data = (t_data *)arg;

	i = 0;
	while (42)
	{
		i++;
		sleep(2);

		pthread_mutex_lock(&turno_mutex);
		if (data->turno == turno_actual)
		{
			pthread_mutex_lock(&data->m);
			printf("%s\thilo #%d, Tu turno %d%s\n", data->color, data->hilo, i, RESET);
			pthread_mutex_unlock(&data->m);

			turno_actual = (turno_actual + 1) % 4; // Avanza al siguiente turno
		}
		pthread_mutex_unlock(&turno_mutex);
	}
	pthread_exit(NULL);
}

int main(void)
{
	t_data data[4];
	char *colores[] = {RED, GREEN, YELLOW, ORANGE};

	pthread_mutex_init(&turno_mutex, NULL); // Inicializar el mutex del turno

	for (int i = 0; i < 4; i++)
	{
		data[i].hilo = i;
		data[i].color = colores[i];
		data[i].turno = i; // Asignar un turno a cada hilo
		pthread_mutex_init(&data[i].m, NULL);
		pthread_create(&data[i].id_hilo, NULL, funcion_hilo, &data[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		pthread_join(data[i].id_hilo, NULL);
		pthread_mutex_destroy(&data[i].m);
	}

	pthread_mutex_destroy(&turno_mutex); // Destruir el mutex del turno

	return 0;
}
