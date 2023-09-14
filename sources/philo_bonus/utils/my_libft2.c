/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:44:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/14 20:40:45 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_num_digitos(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	numeros(char *s, int nd, long n)
{
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
	}
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		s[--nd] = n % 10 + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		n_digitos;

	n_digitos = ft_num_digitos(n);
	res = (char *)ft_calloc(n_digitos + 1, sizeof(char));
	if (!res)
		return (NULL);
	numeros(res, n_digitos, n);
	return (res);
}
