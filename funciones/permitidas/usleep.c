/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:15:20 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 19:19:24 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// int usleep(useconds_t usec);

// usec: Es el número de microsegundos durante los cuales el programa debe detenerse.
// La función usleep es útil en situaciones en las que es necesario pausar
// el programa por un corto período de tiempo.Por ejemplo,
// se puede usar para controlar la velocidad a la que se envían datos a
// través de una conexión de red o para limitar la velocidad
//  de procesamiento de una aplicación.

#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	i;

	printf("Inicio del programa.\n");
	i = 0;
	while (i++ < 100000)
	{
		if (i == 5000)
		{
			printf("\tSE DETIENE\n");
			usleep(1000000); // Espera 1 segundo (1,000,000 microsegundos)}
		}
		printf("%d\n", i);
	}
	printf("Fin del programa.\n");
	return (0);
}
