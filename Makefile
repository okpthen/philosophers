NAME = philo
SRC = src/main.c src/philosophers/init_philo.c src/utils/check_input.c src/utils/ft_atoi.c
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all


echo:
	@echo $(OBJ)