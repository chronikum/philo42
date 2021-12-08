/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:22:17 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/08 16:39:16 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

/*
**	Validates if number received is the actual value or not
**	This can happen if a number exceeds the maximal or minimal integer.
*/
static int	validate_number(char *n)
{
	long long	number_long;
	int			number_int;

	number_int = ft_atoi(n);
	number_long = ft_ll_atoi(n);
	if (number_int == number_long)
		return (1);
	return (0);
}

static int	ft_is_number(char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		while (c[i] == ' ' && c[i])
			i++;
		if ((c[i] == '-' || c[i] == '+') && c[i])
			i++;
		if (ft_isdigit(c[i]) && c[i])
			i++;
		else
			return (0);
	}
	return (1);
}

static int check_single_arg(char *arg)
{
	if (validate_number(arg) && ft_is_number(arg))
		return (1);
	return (0);
}

/*
	Validates the input
*/
int	check_input(char **argv)
{
	int	i;
	int valid;

	i = 1;
	valid = 1;
	while (argv[i])
	{
		if (!check_single_arg(argv[i]))
			valid = 0;
		i++;
	}

	return (valid);
}