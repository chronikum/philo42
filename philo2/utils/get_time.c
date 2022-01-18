/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 17:46:06 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/18 12:34:11 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

long	get_current_time(void)
{
	struct timeval	timeval;
	long			ms;

	gettimeofday(&timeval, NULL);
	ms = timeval.tv_sec * 1000;
	ms += timeval.tv_usec / 1000;
	return (ms);
}
