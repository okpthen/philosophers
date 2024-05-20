NAME = philo
SRCDIR = srcs srcs/philosophers srcs/utils
SRCS   = $(foreach SRCDIR,$(SRCDIR),$(wildcard $(SRCDIR)/*.c))
OBJ = $(SRCS:.c=.o)
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

sanitize: $(OBJ)
	$(CC) -g -fsanitize=address $(OBJ) -o $(NAME)

echo:
	@echo $(OBJ)