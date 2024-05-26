NAME = philo
SRCDIR = srcs srcs/philosophers srcs/utils srcs/time_gremreaper
SRCS   = $(foreach SRCDIR,$(SRCDIR),$(wildcard $(SRCDIR)/*.c))
OBJ = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

.o:.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

all: $(NAME)

clean:
	$(RM) $(OBJ)
	@$(RM) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

sanitize: $(OBJ)
	$(CC) -g -fsanitize=address $(OBJ) -o $(NAME)

echo:
	@echo $(OBJ)

1:
	time ./philo 1 800 200 200

2:
	time ./philo 5 800 200 200

3:
	time ./philo 5 800 200 200 5

4:
	time ./philo 4 410 200 200

5:
	time ./philo 4 310 200 100