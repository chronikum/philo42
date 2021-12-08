CC = gcc

NAME = philo

SRC = philo.c input_check.c

ATOIS = ./atois/atoi.c ./atois/ft_ll_atoi.c

ALLSRC = $(SRC) $(ATOIS)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): *.c
	$(CC) $(FLAGS) $(ALLSRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
