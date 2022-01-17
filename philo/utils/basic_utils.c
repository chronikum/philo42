/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:49:16 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/17 12:30:22 by jfritz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_philo.h"

int	ft_strlen(char *c)
{
	int	i;
	
	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	ft_unlock_all(t_philosph *phs)
{
	int i;
	
	i = 0;
	while (i < phs->params->number_philo)
	{
		pthread_mutex_unlock((&phs[i])->left_fork);
		pthread_mutex_unlock((&phs[i])->right_fork);
		i++;
	}
	pthread_mutex_unlock(&phs->params->wait_printing);
}