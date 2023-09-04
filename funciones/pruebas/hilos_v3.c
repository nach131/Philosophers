/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hilos_v3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:34:36 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/04 13:15:17 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// IMPRIMER 4 HILOS, CADA UNO CON UN COLOR DIFERENTE

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
} t_data;

void *funcion_hilo(void *arg)
{
	int i;
	t_data *data = (t_data *)arg;

	i = 0;
	// while (i++ < 10)
	while (42)
	{
		i++;
		sleep(2);
		pthread_mutex_lock(&data->m);
		printf("%s\thilo #%d, Tu turno %d%s\n", data->color, data->hilo, i, RESET);
		pthread_mutex_unlock(&data->m);
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
		pthread_mutex_init(&data[i].m, NULL);
		pthread_create(&data[i].id_hilo, NULL, funcion_hilo, &data[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		pthread_join(data[i].id_hilo, NULL);
		pthread_mutex_destroy(&data[i].m);
	}

	return 0;
}
