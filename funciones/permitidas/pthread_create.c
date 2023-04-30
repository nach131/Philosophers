/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 19:33:53 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/04/29 19:48:56 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

// La función pthread_create se utiliza para crear un nuevo hilo en un programa
// multihilo. La función toma como argumentos un puntero a una variable de
// tipo pthread_t,
// que se utilizará para almacenar el identificador del nuevo hilo,
// un puntero a una estructura pthread_attr_t,
// que contiene los atributos del hilo,
// un puntero a una función que será la rutina del hilo y
// un puntero a un argumento que se pasará a la rutina del hilo.

// int pthread_create(pthread_t* thread, const pthread_attr_t* attr,
// void* (*start_routine)(void*), void* arg);

// thread: un puntero a una variable de tipo pthread_t que se utilizará para
// almacenar el identificador del nuevo hilo creado por la función.

// attr: un puntero a una estructura de tipo pthread_attr_t que especifica
// los atributos del nuevo hilo. En la mayoría de los casos,
// se puede utilizar NULL para utilizar los valores por defecto.

// start_routine: un puntero a la función que será la rutina del hilo.
//  Esta función debe ser de tipo void* y aceptar un argumento de tipo void*.
//   La función devolverá un puntero void* cuando finalice.

// arg : un puntero a un argumento que se pasará a la función start_routine
// como su único argumento.La función devuelve 0 si el hilo se crea correctamente,
// o un valor de error en caso contrario.

#include <pthread.h>
#include <stdio.h>

void	*funcion_hilo(void *arg)
{
	printf("\tHola desde el hilo\n");
	pthread_exit(NULL);
}

int	main(void)
{
	pthread_t	id_hilo;

	pthread_create(&id_hilo, NULL, funcion_hilo, NULL);
	printf("Hola desde el hilo principal\n");
	pthread_exit(NULL);
}
