NAME = libftprintf.a
LIBFT = libft
SOURCES = ft_printf.c ft_printf_format.c 
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -I./libft
AR = ar
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)						
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)				
	@$(AR) -rcs $(NAME) $(OBJECTS)

%.o:%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(LIBFT)

fclean:
	@$(RM) -rf $(OBJECTS)
	@make clean --no-print-directory -C $(LIBFT)
	@$(RM) -rf $(NAME)
	@$(RM) -rf $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re                   