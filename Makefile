NAME		=	so_long

NAME_B		=	so_long_bonus

SRCS		=	so_long.c sl_key_hook.c \
				sl_read_map.c sl_parser_map.c \
				sl_open_source.c sl_draw_map.c \
				sl_error_game.c \

SRCS_BONUS	=	so_long_bonus.c sl_key_hook_bonus.c \
				sl_read_map_bonus.c sl_parser_map_bonus.c \
				sl_open_source_bonus.c sl_draw_map_bonus.c \
				sl_animation_bonus.c sl_animation_snow_bonus.c \
				sl_animation_enemy_bonus.c \
				sl_error_game_bonus.c \

OBJS		=	${addprefix sources/, ${SRCS:.c=.o}} 

OBJS_BONUS	=	${addprefix bonus/, ${SRCS_BONUS:.c=.o}} 

LIBDIR		=	libft

LIBFT_LIB	=	$(LIBDIR)/libft.a

LIB			=	-L$(LIBDIR) -lft

FLAGSMLX	=	-lmlx -framework OpenGL -framework AppKit


CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra -I

RM			=	rm -f

%.o: %.c	Makefile includes/so_long.h includes/so_long_bonus.h
			$(CC) $(CFLAGS)$(LIBDIR) -Iincludes -c $< -o $@

$(NAME):	$(LIBFT_LIB) $(OBJS)
			@ $(CC) $(CFLAGS)$(LIBDIR) $(OBJS) $(FLAGSMLX) -o $(NAME) $(LIB)

all:		$(NAME)

bonus:		$(LIBFT_LIB) $(OBJS_BONUS) 
			@ $(CC) $(CFLAGS)$(LIBDIR) $(OBJS_BONUS) $(FLAGSMLX) -o $(NAME_B) $(LIB)

$(LIBFT_LIB):	tools ;

tools:
			make -C $(LIBDIR)

clean:		
			make clean -C $(LIBDIR)
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean 
			make fclean -C $(LIBDIR)
			$(RM) $(NAME) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re tools bonus
