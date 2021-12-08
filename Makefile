CC = gcc

NAME = philo

SRC = philo.c

ALLSRC = $(SRC)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): *.c
	$(CC) $(FLAGS) $(ALLSRC) -o $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
