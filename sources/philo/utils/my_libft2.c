/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:44:17 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/14 17:40:11 by nmota-bu         ###   ########.fr       */
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
