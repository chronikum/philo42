#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_params {
	int	number_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_must_eat;
}	t_params;

int			check_input(char **argv);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			whitespace(char c);
long long	ft_ll_atoi(const char *str);

#endif