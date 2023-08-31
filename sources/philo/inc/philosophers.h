/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:22:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/08/31 18:22:15 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>

const static char	*g_args[] = {
	"\t1: Number* of philosophers.",
	"\t2: Time** for each philosohper to die without eating.",
	"\t3: Time** they have to eat.",
	"\t4: Time** they have to sleep.",
	"\t5: Number of meals have take every philo (optional).",
};

const static char	*g_mss[] = {
	"/[number philosophers]",
	"/[time to die]",
	"/[time to eat]",
	"/[time to sleep]",
	"/[number of meals]",
};

typedef struct s_philosopher
{
	size_t			last_meal;
	size_t			eats;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	t_philo			*philo;
	int				num_philo;
	int				num_meals;
	int				t_die;
	int				t_eat;
	int				t_sleep;
}					t_data;

void				utils(void);

// ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ UTILS ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

int					init_data(int argc, char *argv[], t_data *data);

#endif
