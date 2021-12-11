#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

// #define malloc(__size) NULL;

typedef struct s_params {
	int	number_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_must_eat;
	pthread_mutex_t	*forks;
}	t_params;

typedef struct s_philosoph {
	int identifier;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			thread;
	int					is_dead;
	unsigned int		last_meal;
	t_params			*params;
}	t_philosph;

int			check_input(char **argv);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			whitespace(char c);
long long	ft_ll_atoi(const char *str);
void		start_philo(t_params *param, t_philosph	*phs);
long		get_current_time(void);

#endif