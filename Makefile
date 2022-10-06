CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SRC = so_long.c so_long_utils/check_members.c so_long_utils/ft_free.c so_long_utils/ft_itoa.c \
	so_long_utils/ft_strnstr.c so_long_utils/map_builder.c so_long_utils/map_checker.c \
	so_long_utils/moves.c so_long_utils/map_checker_utils/ft_split.c \
	so_long_utils/map_checker_utils/ft_strmchr.c so_long_utils/map_checker_utils/ft_strrchr.c \
	so_long_utils/map_checker_utils/ft_strtrim.c so_long_utils/map_checker_utils/get_line.c \
	so_long_utils/ft_strncmp.c Get_Next_Line/get_next_line_utils.c Get_Next_Line/get_next_line.c

LIBX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBX) -o $(NAME)
clean:

fclean:
	rm -f $(NAME)
re: fclean all