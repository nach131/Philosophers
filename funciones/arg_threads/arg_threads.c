/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_threads.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:39:23 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/05/01 20:49:54 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ╔════════════════════════════════════════════════════════════════════════╗ */
/* ║                 https://github.com/nach131/42Barcelona                 ║ */
/* ╚════════════════════════════════════════════════════════════════════════╝ */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define CYAN "\033[0;36m"

void	*tuTurno(void)
{
	int	i;

	while (i++ < 10)
	{
		sleep(1);
		printf(RED "\t%d Tu turno\n", i);
	}
	pthread_exit(NULL);
}

void	*miTurno(void *arg)
{
	int	i;
	int	*iptr;

	iptr = (int *)malloc(sizeof(int));
	*iptr = 5;
	i = 0;
	while (i++ < 5)
	{
		sleep(1);
		printf(GREEN "%d %d Mi turno\n", i, *iptr);
		(*iptr)++;
	}
	return (iptr);
}

int	main(void)
{
	pthread_t	id_hilo;
	int			*res;

	pthread_create(&id_hilo, NULL, miTurno, NULL);
	tuTurno();
	pthread_join(id_hilo, (void *)&res);
	printf(CYAN "\t\tFIN %d\n", *res);
	pthread_exit(NULL);
}

// https://www.youtube.com/watch?v=It0OFCbbTJE&list=PL9IEJIKnBJjFZxuqyJ9JqVYmuFZHr7CFM
