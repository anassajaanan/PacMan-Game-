NAME =	so_long

SRCS =	so_long.c player.c images.c mouvements.c  \
		line_queue.c map_validator.c map_validator_helpers.c map.c depth_first_search.c \
		depth_first_search_utils.c parsing.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Imlx

all : $(NAME)

${NAME} : ${OBJS}
		@make -C ./libft
		@make -C ./ft_printf
		@make -C ./mlx
		${CC} ${CFLAGS} ${OBJS} -L./libft -lft -L./mlx -lmlx -L./ft_printf -lftprintf -framework OpenGL -framework AppKit -o ${NAME}

clean :
		@make clean -C ./libft
		@make clean -C ./ft_printf
		@make clean -C ./mlx
		${RM} ${OBJS}

fclean : clean
		@make fclean -C ./libft
		@make fclean -C ./ft_printf
		${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re