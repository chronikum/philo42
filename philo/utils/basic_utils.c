/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfritz <jfritz@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:49:16 by jfritz            #+#    #+#             */
/*   Updated: 2022/01/17 17:19:09 by jfritz           ###   ########.fr       */
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

void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	if (!s)
		return ;
	while (s[c])
	{
		write(fd, &s[c], 1);
		c++;
	}
}

void	putstr_buff(char *s, char **buff)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			*(*buff)++ = s[i];
			i++;
		}
		*(*buff) = '\0';
	}
}

void	putnbr_buff(int n, char **buff)
{
	int		base;
	char	*seq;
	
	seq = "0123456789";
	base = 10;
	if (n >= base)
		putnbr_buff(n / base, buff);
	*(*buff)++ = (seq[n % base]);
}