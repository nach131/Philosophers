/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 23:22:28 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/21 19:04:55 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <semaphore.h>
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
	SLEEP,
	THINK,
	DIE,
};

const static char	*g_party[] = {
	"\xF0\x9F\xA5\x84 \033[0;32mHas taken spoon\x1B[0m",
	"\xF0\x9F\x8D\x95 \033[1;31mIs eating\x1B[0m",
	"\xF0\x9F\x92\xa4 \x1B[38;2;47;82;191mIs sleeping\x1B[0m",
	"\xF0\x9F\x92\xA1 \033[0;33mIs thinking\x1B[0m",
	"\xE2\x98\xA0\xEF\xB8\x8F  \033[0;31mIs died\x1B[0m"};

typedef struct s_philosopher
{
	struct s_data	*data;
	int				num;
	uint64_t		last_meal;
	int				eats;
}					t_philo;

typedef struct s_data
{
	// pthread_t		*id;
	// pthread_mutex_t	*mutex;
	sem_t *spoon;
	// sem_t			*m_print;
	// t_philo			*philo;
	int				num_philos;
	int				num_meals;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				is_dead;
}					t_data;

// ▄▄▄▄▄▄▄▄▄▄▄▄▄▄ UTILS ▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄

int					init_data(int argc, char *argv[], t_data *data);
void err_argc(int argc);
void				*processes(void *arg);
uint64_t			times_ms(void);
uint64_t			time_elapsed(void);
// void				print_does(t_philo *philo, int type);
void				waiting(t_data *data);
int					is_die(t_data *data);
int					all_eating(t_data *data);
char				*ft_itoa(int n);
void my_sleep(uint64_t wait);

void				*philosopher_life(void *arg);
#endif
