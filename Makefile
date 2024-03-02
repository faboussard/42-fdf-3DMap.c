#*******************************  VARIABLES  **********************************#

NAME			=	fdf

# --------------- FILES --------------- #

LIST_SRCS		=	main.c \
					events.c\
					parsing.c\
					init.c\
					error_management.c\
					draw.c\
					isometric_projection.c\

# ------------ DIRECTORIES ------------ #

DIR_BUILD		=	.build/
DIR_SRCS 		= 	srcs/
DIR_HEADERS		=	includes/
DIR_LIBFT		=	libft/

# ------------- SHORTCUTS ------------- #

OBJS			=	$(patsubst %.c, $(DIR_BUILD)%.o, $(LIST_SRCS))
DEPS			=	$(patsubst %.c, $(DIR_BUILD)%.d, $(LIST_SRCS))
#SRCS			=	$(addprefix $(DIR_SRCS),$(LIST_SRCS))

# ------------ COMPILATION ------------ #

CFLAGS			=	-Wall -Wextra -Werror -g3
DEPS_FLAGS		=	-MMD -MP

# -------------  COMMANDS ------------- #

RM				=	rm -rf
MKDIR			=	mkdir -p

# -------------  MLX ------------- #

OS				= $(shell uname -s)

DIR_MLX		=	mlx_linux/
MLX_FLAGS	=	-lXext -lX11 -lm

#-------------  VPATH  ---------------#

VPATH			=	$(DIR_SRCS):$(DIR_LIBFT):$(DIR_HEADERS)

#***********************************  RULES  **********************************#

.PHONY: all
all:			$(NAME)

# ---------- VARIABLES RULES ---------- #

$(NAME):		mlx libft  $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -I $(DIR_LIBFT) -L $(DIR_LIBFT) -lft -I $(DIR_MLX) -L $(DIR_MLX) -lmlx $(MLX_FLAGS)

# ---------- COMPILED RULES ----------- #

-include $(DEPS)

$(DIR_BUILD)%.o: %.c
				mkdir -p $(shell dirname $@)
				$(CC) $(CFLAGS) $(DEPS_FLAGS) -I $(DIR_MLX) -I $(DIR_HEADERS) -c $< -o $@

.PHONY: mlx
mlx:
	            		$(MAKE) -C $(DIR_MLX)

.PHONY: libft
libft:
	            		$(MAKE) -C $(DIR_LIBFT)

.PHONY: debug
debug:
				$(MAKE) -g3

.PHONY: clean
clean:
				$(MAKE) -C $(DIR_LIBFT) clean
				$(MAKE) -C $(DIR_MLX) clean
				$(RM) $(DIR_BUILD)

.PHONY: fclean
fclean: clean
				$(MAKE) -C $(DIR_LIBFT) fclean
				$(RM) $(NAME)

.PHONY: re
re:				fclean
				$(MAKE) -C ./
