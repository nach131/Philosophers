/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmota-bu <nmota-bu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:01:35 by nmota-bu          #+#    #+#             */
/*   Updated: 2023/09/12 10:33:46 by nmota-bu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	ft_message(int err, char *msg);

typedef enum e_error
{
	DANGER,
	WARNING,
	INFO,
	SUCCESS,
}		t_error;

typedef enum e_bool
{
	FALSE,
	TRUE,
}		t_bool;

typedef enum e_power
{
	OFF,
	ON,
}		t_power;

#endif

// # define MSG_DAN_0 "Danger message 0"
// # define MSG_WAR_0 "Warning message 0"
// # define MSG_INF_0 "Info message 0"
// # define MSG_SUC_0 "Success message 0"
