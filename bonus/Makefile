NAME =	so_long

SRCS =	so_long_bonus.c game_utils_bonus.c player_bonus.c ghosts_bonus.c fruits_bonus.c images_bonus.c \
		mouvements_bonus.c ghost_movement_bonus.c ghost_movement_utils_bonus.c \
		line_queue_bonus.c map_validator_bonus.c map_validator_helpers_bonus.c map_bonus.c depth_first_search_bonus.c \
		depth_first_search_utils_bonus.c parsing_bonus.c \
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

bonus : ${NAME}

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