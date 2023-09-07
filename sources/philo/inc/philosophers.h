/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:22:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/07 13:03:13 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>

const static char	*g_args[] = {
	"\t1. Number* of philosophers.",
	"\t2. Time** for each philosohper to die without eating.",
	"\t3. Time** they have to eat.",
	"\t4. Time** they have to sleep.",
	"\t5. Number of meals have take every philo (optional)."};

const static char	*g_mss[] = {
	"/[number philosophers]",
	"/[time to die]",
	"/[time to eat]",
	"/[time to sleep]",
	"/[number of meals]"};

enum
{
	TAKE,
	EAT,
	THINK,
	DIE,
};

const static char	*g_party[] = {
	"\xF0\x9F\xA5\x84 \033[0;32mHas taken spoon\x1B[0m\n",
	"\xF0\x9F\x8D\x95 \033[1;31mIs eating\x1B[0m\n",
	"\xF0\x9F\x92\xA1 \033[0;33mIs Thinking\x1B[0m\n",
	"\xE2\x98\xA0\xEF\xB8\x8F  \033[0;31mIs died\x1B[0m\n"};

typedef struct s_philosopher
{
	struct s_data	*data;
	int num; //
	int				last_meal;
	int				eats;
}					t_philo;

typedef struct s_data
{
	pthread_t		*id;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	m_print;
	t_philo *philo; //
	int num_philos; //
	int num_meals;  //
	int t_die;      //
	int t_eat;      //
	int t_sleep;    //
}					t_data;

void				utils(void);

// ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ UTILS ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

int					init_data(int argc, char *argv[], t_data *data);
void				*processes(void *arg);
uint64_t			times_ms(void);
uint64_t			time_elapsed(uint64_t start);

#endif
