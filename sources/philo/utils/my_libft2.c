/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:44:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/26 10:13:44 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "philosophers.h"
#include <stdlib.h>

void static	ft_bzero(void *s, size_t n)
{
	char	*ch;
	size_t	i;

	ch = s;
	i = 0;
	while (i < n)
	{
		ch[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*puntero;

	puntero = malloc(count * size);
	if (!puntero)
		return (NULL);
	ft_bzero(puntero, count * size);
	return (puntero);
}

int	is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if ((str[i] >= '!' && str[i] <= '/') || (str[i] >= ':'
				&& str[i] <= '~'))
		{
			if (str[i] == '-' && i == 0)
				continue ;
			ft_message(DANGER, "Only number in the arguments");
			return (1);
		}
	}
	return (0);
}

int	if_neg(t_data *data)
{
	if (data->num_philos < 0 || data->t_die < 0 || data->t_eat < 0
		|| data->t_sleep < 0 || data->num_meals < 0)
	{
		ft_message(DANGER, "All arguments have to be positive.");
		return (1);
	}
	return (0);
}
