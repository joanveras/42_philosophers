### Variables

NAME = philosophers.a

SRCS = $(wildcard sources/*.c) \
       $(wildcard sources/libft/*.c) \
       $(wildcard sources/utils/*.c)

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

# ANSI escape codes for colors and effects
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m
BLINK = \033[5m
RESET = \033[0m

### Rules

$(NAME): $(OBJS) main.o
	@echo "$(BLUE)Creating static library...$(NC)"
	@ar rc $(NAME) $(OBJS)
	@echo "$(GREEN)Linking executable...$(NC)"
	@$(CC) $(CFLAGS) main.o $(NAME) -o philosophers
	@echo "$(GREEN)$(BLINK)Build successful!$(RESET)$(NC)"

main.o: main.c
	@echo "$(YELLOW)Compiling main.c...$(NC)"
	@$(CC) $(CFLAGS) -c main.c -o main.o > /dev/null 2>&1

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null 2>&1

all: $(NAME)

clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@$(RM) $(OBJS) main.o

fclean: clean
	@echo "$(RED)Cleaning all files...$(NC)"
	@$(RM) $(NAME)
	@$(RM) philosophers

re: fclean all

.PHONY: all clean fclean re