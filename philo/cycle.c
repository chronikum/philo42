/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:41:09 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/11 16:06:09 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

void	ft_wait(long time)
{
	long	starting_time;

	starting_time = get_current_time();
	while (starting_time + time > get_current_time())
		usleep(100);
	return ;
}

/*
	Eats if possible
*/
void	eating_philo(t_philosph *ph)
{
	pthread_mutex_lock(ph->left_fork);
	pthread_mutex_lock(ph->right_fork);
	printer(ph, EATING);
	ft_wait(ph->params->time_to_eat);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
	ph->last_meal = get_current_time();
}

/*
	Sleeping philosoph
*/
void	sleeping_philo(t_philosph *ph)
{
	ft_wait(ph->params->time_to_sleep);
	printer(ph, SLEEPING);
}