/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:30:33 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/08 17:08:20 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

/*
	Fills the parameter in the allocated struct
*/
void	fill_params(char **argv, t_params *param)
{
	param->number_philo = ft_atoi(argv[1]);
	param->time_to_die = ft_atoi(argv[2]);
	param->time_to_eat = ft_atoi(argv[3]);
	param->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		param->number_must_eat = ft_atoi(argv[5]);
	else
		param->number_must_eat = 1;
}

/*
	Creates the parameter struct
*/
t_params	*create_params(char **argv)
{
	t_params	*params;

	if (!check_input(argv))
		return (NULL);
	params = malloc(sizeof(t_params));
	if (params)
		return (NULL);
	fill_params(argv, params);

	return (params);
}
/*
	usage:
	number_of_philosophers time_to_die time_to_eat
	time_to_sleep [number_of_times_each_philosopher_must_eat]
*/
int	main(int argc, char **argv)
{
	t_params *params;

	if (argc < 4 && argv)
	{
		printf("Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	params = create_params(argv);
	if (!params)
		return (1);
	printf("OK!");
	free(params);
	return (0);
}
