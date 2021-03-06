/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:30:33 by jfritz            #+#    #+#             */
/*   Updated: 2022/02/09 10:50:34 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

/*
	Join the thread back together
*/
void	join_together(t_philosph *philosophs)
{
	int			i;
	int			philo_number;
	t_params	*params;

	i = 0;
	params = philosophs->params;
	philo_number = philosophs->params->number_philo;
	ft_unlock_all(philosophs);
	while (i < philo_number)
	{
		pthread_join(philosophs[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < philo_number)
	{
		pthread_mutex_destroy(&params->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&params->wait_printing);
	pthread_mutex_destroy(&params->waiter);
	pthread_mutex_destroy(&params->reading_alive);
}

/*
	Fills the parameter in the allocated struct
*/
int	fill_params(char **argv, t_params *param)
{
	param->number_philo = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	param->forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!param->forks)
		return (0);
	if (argv[5])
		param->number_must_eat = ft_atoi(argv[5]);
	else
		param->number_must_eat = 2147483647;
	return (1);
}

/*
	Creates the parameter struct
*/
t_params	*create_params(char **argv)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
		return (NULL);
	if (fill_params(argv, params))
		return (params);
	return (NULL);
}

/*
	usage:
	number_of_philosophers time_to_die time_to_eat
	time_to_sleep [number_of_times_each_philosopher_must_eat]
*/
int	main(int argc, char **argv)
{
	t_params	*params;
	t_philosph	*phs;

	if (argc < 5 && argv)
	{
		printf("Usage: number time_die time_eat time_sleep [must_eat]");
		return (1);
	}
	if (!check_input(argv))
		return (1);
	params = create_params(argv);
	if (!params)
		return (1);
	phs = malloc(sizeof(t_philosph) * params->number_philo + 1);
	params->all_phs = phs;
	start_philo(params, phs);
	free(params->forks);
	free(params);
	free(phs);
	return (0);
}
