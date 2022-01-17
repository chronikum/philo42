/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:46:42 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/17 12:27:26 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

void	put_number(unsigned int n, char *seq, unsigned int base)
{
	if (n < base)
		write(1, &seq[n], 1);
	else
	{
		put_number(n / base, seq, base);
		write(1, &(seq[n % base]), 1);
	}
}

void	printer(t_philosph *philo, int activity)
{
	long time;
	
	pthread_mutex_lock(&philo->params->wait_printing);
	if (philo->params->alive)
	{
		time = get_current_time() - philo->params->start_time;
		if (activity == EATING && philo->params->alive)
			printf("%lu | Philo %d is eating\n", time, philo->identifier);
		if (activity == SLEEPING && philo->params->alive)
			printf("%lu | Philo %d is sleeping\n", time, philo->identifier);
		if (activity == THINKING && philo->params->alive)
			printf("%lu | Philo %d is thinking\n", time, philo->identifier);
		if (activity == FORK && philo->params->alive)
			printf("%lu | Philo %d takes a fork\n", time, philo->identifier);
		if (activity == DEAD)
			printf("%lu | Philo %d died\n", time, philo->identifier);	
	}
	pthread_mutex_unlock(&philo->params->wait_printing);
}