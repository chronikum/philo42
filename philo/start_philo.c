/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:56:28 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/14 13:37:03 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

/*
	Inits the mutex and creates all the forks
	which are being used by the philosphers later on
	
*/
void	build_forks(t_params *param)
{
	int i;
	
	i = 0;
	while (i < param->number_philo)
	{
		pthread_mutex_init(&param->forks[i], NULL);
		i++;
	}
}

/*
	After all input has been validated, we finally
	start the philos
*/
void	start_philo(t_params *param, t_philosph	*phs)
{
	int i;
	
	i = 0;
	build_forks(param);
	param->start_time = get_current_time();
	param->alive = 1;
	while (i < param->number_philo)
	{
		(&phs[i])->params = param;
		(&phs[i])->identifier = (i + 1);
		(&phs[i])->left_fork = &param->forks[i];
		(&phs[i])->right_fork = &param->forks[(i + 1) % param->number_philo];
		(&phs[i])->next_death = get_current_time() + param->time_to_die;
		pthread_create(&phs[i].thread, NULL, &life_cycle, &phs[i]);
		usleep(100);
		i++;
	}
	watcher(phs);
}

// printf("Philo %d has left fork %d and right fork %d\n", i, i, ((i + 1) % param->number_philo));
// Philo 0 has left fork 0 and right fork 1
// Philo 1 has left fork 1 and right fork 2
// Philo 2 has left fork 2 and right fork 3
// Philo 3 has left fork 3 and right fork 4
// Philo 4 has left fork 4 and right fork 5
// Philo 5 has left fork 5 and right fork 0