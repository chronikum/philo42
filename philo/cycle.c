/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:41:09 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/17 12:53:59 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

/*
	Looks if philosophers are not eating for a certain time
	If yes, declare them as dead.
*/
void	watcher(t_philosph *philos)
{
	int i;
	
	i = 0;
	while (philos->params->alive)
	{
		i = 0;
		while (i < philos->params->number_philo)
		{
			if (get_current_time() >= philos[i].next_death)
			{
				printer(&philos[i], DEAD);
				philos->params->alive = 0;
				i = 400;
			}
		}
	}
}

void	ft_wait(long time)
{
	long	starting_time;

	starting_time = get_current_time();
	while (starting_time + time > get_current_time())
		usleep(3);
	return ;
}

/*
	Eats if possible
*/
void	eating_philo(t_philosph *ph)
{
	pthread_mutex_lock(ph->left_fork);
	printer(ph, FORK);
	pthread_mutex_lock(ph->right_fork);
	printer(ph, FORK);
	ph->next_death = get_current_time() + get_current_time();
	printer(ph, EATING);
	ph->next_death = get_current_time() + (ph->params->time_to_die);
	ft_wait(ph->params->time_to_eat);
	pthread_mutex_unlock(ph->left_fork);
	pthread_mutex_unlock(ph->right_fork);
}

/*
	Sleeping philosoph
*/
void	sleeping_philo(t_philosph *ph)
{
	printer(ph, SLEEPING);
	ft_wait(ph->params->time_to_sleep);
}

/*
	The life cycle of a philosoph
*/
void	*life_cycle(void *pointer)
{
	t_philosph 	*philo;
	
	philo = (t_philosph *) pointer;
	while (philo->params->alive)
	{
		eating_philo(philo);
		sleeping_philo(philo);
		printer(philo, THINKING);
	}
	return (NULL);
}