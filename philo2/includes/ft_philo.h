#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// #define malloc(__size) NULL;

# define EATING 1
# define SLEEPING 2
# define THINKING 3
# define DEAD 4
# define FORK 5

typedef struct s_params {
	int				number_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_must_eat;
	pthread_mutex_t	*forks;
	int				alive;
	long			start_time;
	pthread_mutex_t	waiter;
	pthread_mutex_t	wait_printing;
	pthread_mutex_t	reading_alive;
	pthread_mutex_t	all_alive;
	void			*all_phs;
}	t_params;

typedef struct s_philosoph {
	int					identifier;
	char				*str_id;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			thread;
	int					is_dead;
	long				next_death;
	unsigned int		last_meal;
	int					times_eaten;
	t_params			*params;
}	t_philosph;

int			check_input(char **argv);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
int			whitespace(char c);
long long	ft_ll_atoi(const char *str);
void		start_philo(t_params *param, t_philosph	*phs);
long		get_current_time(void);

void		eating_philo(t_philosph *ph);
void		sleeping_philo(t_philosph *ph);

int			ft_strlen(char *c);
void		printer(t_philosph *philo, int activity);
void		*life_cycle(void *pointer);
void		watcher(t_philosph *philos);

void		ft_unlock_all(t_philosph *phs);
void		ft_buffnbr(int n, char *seq, int base, char **buff);
void		ft_putstr_fd(char *s, int fd);
void		putstr_buff(char *s, char **buff);
void		putnbr_buff(int n, char **buff);
void		put_nbr(int n);
void		watcher(t_philosph *philos);

void		print_how_many_eaten(t_philosph *phs);
void		lock_all(t_philosph *philo);
void		kill_philo(t_philosph *philos, int *i, int phil_id);
void		join_together(t_philosph *philosophs);

#endif