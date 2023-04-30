/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_mutex_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:48:46 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 20:52:17 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// se utiliza en C para inicializar un objeto mutex, que es un mecanismo de
// sincronización utilizado para evitar que varios hilos accedan simultáneamente
// a una sección crítica del código.

// int pthread_mutex_init(pthread_mutex_t *mutex,
// const pthread_mutexattr_t *attr);

// mutex es un puntero al objeto mutex que se desea inicializar.
// attr es un puntero a un objeto pthread_mutexattr_t

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*rutina_hilo(void *arg)
{
	pthread_mutex_t	*mutex;

	mutex = (pthread_mutex_t *)arg;
	printf("Hilo bloqueado\n");
	pthread_mutex_lock(mutex);
	printf("Hilo desbloqueado\n");
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t		hilo;
	pthread_mutex_t	mutex;
	int				resultado;

	resultado = pthread_mutex_init(&mutex, NULL);
	if (resultado != 0)
	{
		perror("Error al inicializar el mutex");
		exit(EXIT_FAILURE);
	}
	resultado = pthread_create(&hilo, NULL, rutina_hilo, &mutex);
	if (resultado != 0)
	{
		perror("Error al crear el hilo");
		exit(EXIT_FAILURE);
	}
	printf("Programa bloqueado\n");
	pthread_mutex_lock(&mutex);
	printf("Programa desbloqueado\n");
	resultado = pthread_join(hilo, NULL);
	if (resultado != 0)
	{
		perror("Error al esperar al hilo");
		exit(EXIT_FAILURE);
	}
	pthread_mutex_destroy(&mutex);
	pthread_exit(NULL);
}

// En este ejemplo, se inicializa un objeto mutex utilizando la
// función pthread_mutex_init.
// Luego, se crea un nuevo hilo utilizando la función pthread_create,
// y se le pasa el objeto mutex como argumento. En la rutina del hilo,
// se bloquea el mutex utilizando la función
//  pthread_mutex_lock,
// y luego se desbloquea cuando el programa principal lo desbloquea.

// Es importante destacar que si un objeto mutex no se inicializa utilizando
//  pthread_mutex_init, puede llevar a errores de ejecución en el programa.
