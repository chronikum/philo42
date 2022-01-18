/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:56:28 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/18 12:30:09 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

/*
	Inits the mutex and creates all the forks
	which are being used by the philosphers later on
	
*/
void	build_forks(t_params *param)
{
	int	i;

	i = 0;
	pthread_mutex_init(&param->wait_printing, NULL);
	pthread_mutex_init(&param->waiter, NULL);
	pthread_mutex_init(&param->reading_alive, NULL);
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
	int	i;

	i = 0;
	build_forks(param);
	param->start_time = get_current_time();
	while (i < param->number_philo)
	{
		(&phs[i])->params = param;
		(&phs[i])->identifier = (i + 1);
		(&phs[i])->left_fork = &param->forks[i];
		(&phs[i])->right_fork = &param->forks[(i + 1) % param->number_philo];
		(&phs[i])->times_eaten = 0;
		i++;
	}
	i = 0;
	param->alive = 1;
	while (i < param->number_philo)
	{
		(&phs[i])->next_death = param->start_time + param->time_to_die;
		pthread_create(&phs[i].thread, NULL, &life_cycle, &phs[i]);
		usleep(20);
		i++;
	}
	watcher(phs);
}
