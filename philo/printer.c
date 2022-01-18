/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:46:42 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/18 11:42:54 by jfritz           ###   ########.fr       */
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

void	print_action(int phil_id, int activity, t_philosph *philo)
{
	char buff[128];
	char *ptr;
	int i;
	long time;
	
	i = 0;
	ptr = buff;
	pthread_mutex_lock(&philo->params->wait_printing);
	while (i < 128)
	{
		buff[i] = '\0';
		i++;
	}
	// putnbr_buff(time, &ptr);
	putstr_buff(" ", &ptr);
	putnbr_buff(phil_id, &ptr);
	if (activity == EATING)
		putstr_buff(" is eating\n", &ptr);
	if (activity == FORK)
		putstr_buff(" is taking a fork\n", &ptr);
	else if (activity == SLEEPING)
		putstr_buff(" is sleeping\n", &ptr);
	else if (activity == THINKING)
		putstr_buff(" is thinking\n", &ptr);
	else if (activity == DEAD)
		putstr_buff(" died\n", &ptr);
	if (philo->params->alive)
	{
		time = get_current_time() - philo->params->start_time;
		put_nbr(time);
		write(1, buff, ft_strlen(buff));
	}
	pthread_mutex_unlock(&philo->params->wait_printing);
}

void	printer(t_philosph *philo, int activity)
{
	if (philo->params->alive)
	{
		print_action(philo->identifier, activity, philo);
	}
}