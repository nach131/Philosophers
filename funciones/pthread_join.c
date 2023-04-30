/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 20:37:24 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 20:44:58 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// se utiliza para esperar a que un hilo específico termine su ejecución.
//  Cuando se llama a esta función, el hilo principal (o cualquier otro hilo
//  que llame a la función) se bloqueará hasta que el hilo
//  especificado haya terminado su ejecución.

// int pthread_join(pthread_t thread, void** retval);

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void	*rutina_hilo(void *arg)
{
	int	*resultado;

	printf("Hola desde el hilo\n");
	resultado = malloc(sizeof(int));
	*resultado = 42;
	pthread_exit(resultado);
}

int	main(void)
{
	pthread_t	hilo;
	int			resultado;
	int			*valor_hilo;

	resultado = pthread_create(&hilo, NULL, rutina_hilo, NULL);
	if (resultado != 0)
	{
		perror("Error al crear el hilo");
		exit(EXIT_FAILURE);
	}
	resultado = pthread_join(hilo, (void **)&valor_hilo);
	if (resultado != 0)
	{
		perror("Error al esperar al hilo");
		exit(EXIT_FAILURE);
	}
	printf("Hilo finalizado con resultado: %d\n", *valor_hilo);
	free(valor_hilo);
	pthread_exit(NULL);
}
