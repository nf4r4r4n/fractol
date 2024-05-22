NAME	=	fractol
SRCS	=	src/main.c src/ft_errors.c src/ft_fractol.c \
			src/ft_hook.c src/ft_tools.c src/ft_render.c \
			src/set/mandelbrot.c src/set/julia.c src/ft_complex.c \
			src/ft_utils.c
OBJ		=	$(SRCS:.c=.o)
LIBFT	=	libft/libft.a
INCLUDE	=	-I includes

all:	$(NAME)

%.o: %.c
	@$(CC) -Wall -Wextra -Werror -g -I/usr/include $(INCLUDE) -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	@echo "\33[1;34mLIBFT-----------------------\33[0m"
	@make -C libft
	@echo "\33[1;34mMINILIB_X-------------------\33[0m"
	@make -C mlx_linux
	@echo "\33[1;34mFRACTOL---------------------\33[0m"
	@$(CC) $(OBJ) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	@echo "\33[1;34mLIBFT-----------------------\33[0m"
	@make -C libft clean
	@echo "\33[1;34mMINILIB_X-------------------\33[0m"
	@make -C mlx_linux clean
	@echo "\33[1;34mFRACTOL---------------------\33[0m"
	@rm -f $(OBJ)

fclean:	clean
	@echo "\33[1;34mLIBFT-----------------------\33[0m"
	@make -C libft fclean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
