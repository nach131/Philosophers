/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_mutex_lock.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 21:26:39 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 21:28:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

//  utiliza para bloquear un objeto mutex. Si el mutex ya está bloqueado
//   por otro hilo, la función pthread_mutex_lock esperará hasta que el
//    mutex se desbloquee antes de continuar.

// int pthread_mutex_lock(pthread_mutex_t *mutex);

// mutex es un puntero al objeto mutex que se desea bloquear.

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


// En este ejemplo, se utiliza la función pthread_mutex_lock para bloquear el objeto mutex.
//  En el hilo, la función pthread_mutex_lock se utiliza para bloquear el mutex y esperar a 
//  que el programa principal lo desbloquee. En el programa principal, la función
//   pthread_mutex_lock se utiliza para bloquear el mutex y esperar a 
//   que el hilo lo desbloquee.