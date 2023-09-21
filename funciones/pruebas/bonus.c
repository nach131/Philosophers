/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 22:56:43 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/21 11:32:02 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h> // Necesario para sem_open en algunos sistemas
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5
#define MAX_MEALS 10

sem_t		*forks[NUM_PHILOSOPHERS];
sem_t		*print_mutex;

typedef struct
{
	int		id;
	int		meals_eaten;
}			PhilosopherData;

uint64_t	get_time_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((uint64_t)(time.tv_sec) * 1000 + (uint64_t)(time.tv_usec) / 1000);
}

void	eat(PhilosopherData *philosopher)
{
	printf("Philosopher %d is eating.\n", philosopher->id);
	usleep(200000); // Simulate eating time in microseconds
	philosopher->meals_eaten++;
}

void	think(PhilosopherData *philosopher)
{
	printf("Philosopher %d is thinking.\n", philosopher->id);
	usleep(200000); // Simulate thinking time in microseconds
}

void	*philosopher_life(void *arg)
{
	PhilosopherData	*philosopher;

	philosopher = (PhilosopherData *)arg;
	while (philosopher->meals_eaten < MAX_MEALS)
	{
		think(philosopher);
		sem_wait(forks[philosopher->id]);
		sem_wait(forks[(philosopher->id + 1) % NUM_PHILOSOPHERS]);
		eat(philosopher);
		sem_post(forks[philosopher->id]);
		sem_post(forks[(philosopher->id + 1) % NUM_PHILOSOPHERS]);
	}
	return (NULL);
}

int	main(void)
{
	char			fork_name[64];
	pid_t			pid;
	PhilosopherData	philosophers[NUM_PHILOSOPHERS];

	// Inicializar semáforos para los tenedores
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		snprintf(fork_name, sizeof(fork_name), "/fork%d", i);
		forks[i] = sem_open(fork_name, O_CREAT, 0644, 1);
	}
	// Inicializar semáforo para impresión
	print_mutex = sem_open("/print_mutex", O_CREAT, 0644, 1);
	// Crear filósofos como procesos independientes
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		pid = fork();
		if (pid == 0)
		{
			philosophers[i].id = i;
			philosophers[i].meals_eaten = 0;
			philosopher_life(&philosophers[i]);
			exit(0);
		}
	}
	// Esperar a que todos los filósofos terminen
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		waitpid(pid, NULL, 0);
	}
	// Cerrar y destruir semáforos
	for (int i = 0; i < NUM_PHILOSOPHERS; i++)
	{
		sem_close(forks[i]);
		sem_unlink(forks[i]);
	}
	sem_close(print_mutex);
	sem_unlink("/print_mutex");
	return (0);
}
