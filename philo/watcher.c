/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:30:04 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/18 12:33:54 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

void	kill_philo(t_philosph *philos, int *i)
{
	(*i) = 400;
	philos->params->alive = 0;
}

/*
	Looks if philosophers are not eating for a certain time
	If yes, declare them as dead.
*/
void	watcher(t_philosph *philos)
{
	int	i;
	int	all_done;

	i = 0;
	all_done = 0;
	while (philos->params->alive)
	{
		i = 0;
		all_done = 0;
		while (i < philos->params->number_philo)
		{
			pthread_mutex_lock(&philos->params->reading_alive);
			if (get_current_time() >= philos[i].next_death)
			{
				printer(&philos[i], DEAD);
				kill_philo(philos, &i);
			}
			else if (philos[i].times_eaten >= philos->params->number_must_eat)
				all_done++;
			i++;
			pthread_mutex_unlock(&philos->params->reading_alive);
		}
		if (all_done == philos->params->number_philo)
			kill_philo(philos, &i);
	}
}

void	ft_unlock_all(t_philosph *phs)
{
	int	i;

	i = 0;
	while (i < phs->params->number_philo)
	{
		pthread_mutex_unlock((&phs[i])->left_fork);
		pthread_mutex_unlock((&phs[i])->right_fork);
		i++;
	}
	pthread_mutex_unlock(&phs->params->wait_printing);
	print_how_many_eaten(phs);
}

void	print_how_many_eaten(t_philosph *phs)
{
	int	i;

	i = 0;
	while (i < phs[0].params->number_philo)
	{
		printf("eaten %d, philo %d\n", phs[i].times_eaten, phs[i].identifier);
		i++;
	}
}
