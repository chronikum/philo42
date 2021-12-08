/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:42:38 by jfritz            #+#    #+#             */
/*   Updated: 2021/12/08 13:21:57 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	whitespace(char c)
{
	return ((c == '\t') || (c == '\n')
		|| (c == '\v') || (c == '\f') || (c == '\r') || (c == ' '));
}

static int	ft_skip_plus_minus(const char *str, int p, int *m)
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

/*
	Ascii to integer
*/
int	ft_atoi(const char *str)
{
	int		i;
	int		r;
	int		m;

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

