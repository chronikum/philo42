/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:48:24 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/18 12:31:29 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

static long long	ft_skip_plus_minus(const char *str,
	long long p, long long *m)
{
	int	a;

	a = 0;
	if (str[p] == '-' && ft_isdigit((int) str[p + 1]))
	{
		*m = -1;
		a++;
	}
	if (str[p] == '+' && ft_isdigit((int) str[p + 1]))
	{
		*m = 1;
		a++;
	}
	if (ft_isdigit((int) str[p]))
		*m = 1;
	return (p + a);
}

long long	ft_ll_atoi(const char *str)
{
	long long		i;
	long long		r;
	long long		m;

	i = 0;
	r = 0;
	m = 0;
	while (whitespace(str[i]))
		i++;
	i = ft_skip_plus_minus(str, i, &m);
	if (m == 0)
		return (0);
	if (str[i] == '0')
		i++;
	while (ft_isdigit((int) str[i]) && (str[i] != '\0'))
	{
		r = ((10 * r) + (str[i] - 48));
		i++;
	}
	return (r * m);
}
