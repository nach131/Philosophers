/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ma.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:48:25 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/21 10:52:32 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*toma;

	toma = malloc(sizeof(char) * 6);
	toma[0] = 'c';
	toma[1] = 'a';
	toma[2] = 's';
	toma[3] = 'a';
	toma[4] = '\0';
	printf("%s\n", toma);
	free(toma);
}
