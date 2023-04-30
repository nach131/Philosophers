/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_detach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:07:22 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 20:09:39 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// indicar al sistema que el hilo especificado debe ejecutarse de
// forma independiente, sin necesidad de que el hilo principal lo espere
// para realizar la limpieza de los recursos que utiliza. En otras palabras,
//  con esta función se puede liberar la memoria y otros recursos asociados al
//   hilo de forma automática, sin necesidad de llamar a pthread_join.

// int pthread_detach(pthread_t thread);

// thread es el identificador del hilo que se desea desvincular.

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*rutina_hilo(void *arg)
{
	printf("Hola desde el hilo\n");
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	hilo;
	int			resultado;

	resultado = pthread_create(&hilo, NULL, rutina_hilo, NULL);
	if (resultado != 0)
	{
		perror("Error al crear el hilo");
		exit(EXIT_FAILURE);
	}
	resultado = pthread_detach(hilo);
	if (resultado != 0)
	{
		perror("Error al desvincular el hilo");
		exit(EXIT_FAILURE);
	}
	printf("Hilo creado y desvinculado\n");
	pthread_exit(NULL);
}
