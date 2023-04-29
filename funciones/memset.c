/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:07:19 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 19:12:53 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// void *memset(void *ptr, int value, size_t num);

// ptr: Es un puntero al bloque de memoria que se desea inicializar.
// value: Es el valor que se desea establecer en cada byte del bloque de memoria.
// num: Es el número de bytes que se deben inicializar.

// La función memset es comúnmente utilizada para inicializar matrices y
// otros tipos de bloques de memoria.
//  Por ejemplo,el siguiente código utiliza memset
//  para inicializar una matriz de enteros con el valor 0:

#include <stdio.h>
#include <string.h>

int	main(void)
{
	int	myArray[10];
	int	i;

	memset(myArray, 0, sizeof(myArray));
	i = -1;
	while (++i < 10)
		printf("%d: %d\n", i, myArray[i]);
	return (0);
}

// 0: 0
// 1: 0
// 2: 0
// 3: 0
// 4: 0
// 5: 0
// 6: 0
// 7: 0
// 8: 0
// 9: 0
