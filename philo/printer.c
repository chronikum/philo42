/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:46:42 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/11 16:02:41 by jfritz           ###   ########.fr       */
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
	
	time = get_current_time() - philo->params->start_time;
	if (activity == EATING)
		printf("%lu Phile %d is eating\n", time, philo->identifier);
	if (activity == SLEEPING)
		printf("%lu Phile %d is sleeping\n", time, philo->identifier);
	if (activity == THINKING)
		printf("%lu Phile %d is thinking\n", time, philo->identifier);
}