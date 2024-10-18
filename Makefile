NAME = philo
HEADER = philo.h
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g
RM = rm -f

FILES = philo \
		monitoring \
		innit \
		parse \
		routine \
		threads \
		utils \
		utils1 \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addsuffix .o, $(FILES))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean