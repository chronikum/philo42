/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:30:33 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/08 16:51:39 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

/*
	usage:
	number_of_philosophers time_to_die time_to_eat
	time_to_sleep [number_of_times_each_philosopher_must_eat]
*/
int	main(int argc, char **argv)
{
	if (argc < 4 && argv)
	{
		printf("Usage: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	if (!check_input(argv))
		return (1);
	printf("OK!");
	return (0);
}
