NAME = push_swap.a
NAME_EXEC = push_swap
FT_PRINTF = ft_printf
SOURCES = push_swap.c push_swap_rules.c push_swap_rules2.c push_swap_rules3.c sort_arg.c radix_sort.c helper_functions.c check_input.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I./ft_printf
AR = ar
RM = rm

all: $(NAME) $(NAME_EXEC)

$(NAME_EXEC):
	@$(CC) $(CFLAGS) -o $@ $(NAME)

$(NAME): $(OBJECTS)						
	@make -C $(FT_PRINTF)
	@cp ft_printf/libftprintf.a .
	@mv libftprintf.a $(NAME)				
	@$(AR) -rcs $(NAME) $(OBJECTS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(FT_PRINTF)

fclean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(FT_PRINTF)
	@$(RM) -rf $(NAME)
	@$(RM) -rf $(FT_PRINTF)/libftprintf.a
	@$(RM) -rf $(FT_PRINTF)/libft/libft.a
	@$(RM) -rf $(NAME_EXEC)

re: fclean all

.PHONY: all clean fclean re