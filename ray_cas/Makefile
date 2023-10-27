CC = cc
CFLAGS =  #-fsanitize=address  -g3 #-Wall -Werror -Wextra -fsanitize=address -g3
RM = rm -f
PATH = /Users/oelboukh/Desktop/parsing/cub3d_pars
FILES = lunchmap.c cub3d.c $(PATH)/parsing.c $(PATH)/texters.c $(PATH)/more_files.c $(PATH)/libft/ft_bzero.c \
        $(PATH)/libft/ft_strjoin.c $(PATH)/libft/ft_atoi.c $(PATH)/libft/ft_strlen.c $(PATH)/libft/ft_calloc.c \
        $(PATH)/libft/ft_split.c $(PATH)/libft/ft_strdup.c   $(PATH)/libft/ft_strnstr.c $(PATH)/libft/ft_strchr.c \
         $(PATH)/file.c $(PATH)/get_line/get_next_line.c
OBJ = $(FILES:.c=.o)
NAME = cub3d

all: $(NAME)

UNAME = $(shell uname)
ifeq ($(UNAME),Linux)
    MLX_FLAGS = -lmlx -lXext -lX11 -lm
endif
ifeq ($(UNAME),Darwin)
    MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif


$(NAME): $(FILES)
	$(CC) $(CFLAGS) $(FILES) $(MLX_FLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
