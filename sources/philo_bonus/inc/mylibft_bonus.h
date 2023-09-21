/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylibft_bonus_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 11:05:16 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/21 17:02:21 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIBFT_BONUS_H
# define MYLIBFT_BONUS_H

# include <stdio.h>

void	ft_message(int err, char *msg);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif
