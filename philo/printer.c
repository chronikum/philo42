/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:46:42 by jfritz            #+#    #+#             */
/*   Updated: 2022/02/02 21:01:08 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

void	print_action(int phil_id, int activity, t_philosph *philo)
{
	long		time;
	static int	is_dead = 0;

	time = get_current_time() - philo->params->start_time;
	if (is_dead != 1)
	{
		if (activity == DEAD)
		{
			is_dead = 1;
			kill_philo(philo, NULL, phil_id);
		}
		else if (activity == EATING)
			printf("%ld %d is eating\n", time, phil_id);
		else if (activity == FORK)
			printf("%ld %d has taken a fork\n", time, phil_id);
		else if (activity == SLEEPING)
			printf("%ld %d is sleeping\n", time, phil_id);
		else if (activity == THINKING)
			printf("%ld %d is thinking\n", time, phil_id);
	}
}

void	printer(t_philosph *philo, int activity)
{
	if (philo->params->alive)
	{
		pthread_mutex_lock(&philo->params->wait_printing);
		print_action(philo->identifier, activity, philo);
		pthread_mutex_unlock(&philo->params->wait_printing);
	}
}
