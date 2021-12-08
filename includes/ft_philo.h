#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdio.h>

int			check_input(char **argv);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			whitespace(char c);
long long	ft_ll_atoi(const char *str);

#endif