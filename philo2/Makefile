CC = gcc

NAME = philo

SRC = philo.c input_check.c cycle.c printer.c watcher.c

UTILS = ./utils/get_time.c ./utils/basic_utils.c

ATOIS = ./atois/atoi.c ./atois/ft_ll_atoi.c start_philo.c

ALLSRC = $(SRC) $(ATOIS) $(UTILS)

FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): *.c
	$(CC) $(FLAGS) $(ALLSRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
