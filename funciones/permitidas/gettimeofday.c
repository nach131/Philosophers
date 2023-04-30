/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:20:02 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 19:33:08 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

//  se utiliza para obtener el tiempo actual del sistema con una resolución de microsegundos

//  int gettimeofday(struct timeval *tv, struct timezone *tz);

// tv : Es un puntero a una estructura timeval que se llenará con el tiempo actual.
// tz : Es un puntero a una estructura timezone.Este parámetro es obsoleto y
//  no se utiliza en la mayoría de las implementaciones de gettimeofday.
// Por lo tanto,
// 	se puede pasar NULL en este parámetro en la mayoría de los casos.

// struct	timeval
// {
// 	time_t tv_sec;       /* segundos */
// 	suseconds_t tv_usec; /* microsegundos */
// };

// La función gettimeofday es comúnmente utilizada para medir el tiempo transcurrido
// entre dos eventos en un programa,
// ya que tiene una resolución de microsegundos.
//  A continuación, se muestra un ejemplo de uso de gettimeofday
//  para medir el tiempo que tarda un programa en ejecutarse:

#include <stdio.h>
#include <sys/time.h>

int	main(void)
{
	long	tiempo_transcurrido;
	int		i;

	struct timeval inicio, fin;
	gettimeofday(&inicio, NULL); // Tiempo de inicio
	// Código que se desea medir
	i = 0;
	while (i++ < 100000)
	{
		;
	}
	gettimeofday(&fin, NULL); // Tiempo de fin
	tiempo_transcurrido = (fin.tv_sec - inicio.tv_sec) * 1000000L + (fin.tv_usec
			- inicio.tv_usec);
	printf("Tiempo transcurrido: %ld microsegundos.\n", tiempo_transcurrido);
	printf("Tiempo transcurrido: %ld segundos.\n", tiempo_transcurrido
			/ 1000000);
	return (0);
}
