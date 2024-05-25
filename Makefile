NAME = philo
SRCDIR = srcs srcs/philosophers srcs/utils srcs/time_gremreaper
SRCS   = $(foreach SRCDIR,$(SRCDIR),$(wildcard $(SRCDIR)/*.c))
OBJ = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=thread
# CFLAGS += -g -fsanitize=address
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

sanitize: $(OBJ)
	$(CC) -g -fsanitize=address $(OBJ) -o $(NAME)

echo:
	@echo $(OBJ)

1:
	./philo 1 800 200 200

2:
	./philo 5 800 200 200

3:
	./philo 5 800 200 200 7

4:
	./philo 4 410 200 200

5:
	./philo 4 310 200 100