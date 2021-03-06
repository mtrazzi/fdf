NAME = fdf
MAIN = main.c
LIB = lib

LIBFT = libft
LIBFT_A = libft/libft.a

MLX_LINUX = minilibx_linux
MLX_LINUX_A = minilibx_linux/libmlx.a
MLX_LINUX_FLAG = -lXext -lX11

MLX_MAC = minilibx_mac
MLX_MAC_A = minilibx_mac/libmlx.a
MLX_MAC_FLAG = -lmlx -framework OpenGL -framework AppKit

SUPPORT = src
SRC  = src/ft_line.c src/ft_change_point.c src/ft_pixel.c src/ft_image.c src/ft_parse.c src/ft_iso.c \
	   src/ft_free.c src/ft_bonus.c
SRC_DIR = src

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)

$(NAME): libft
ifeq ($(shell uname -s),Linux)
	@make linux --no-print-directory
else ifeq ($(shell uname -s),Darwin)
	@make mac --no-print-directory
endif

all: $(NAME)

linux:
	@gcc $(MAIN) $(MLX_LINUX_FLAG) $(SRC) \
	-I $(LIB)/$(MLX_LINUX) $(LIB)/$(MLX_LINUX_A) \
	-I $(LIB)/$(LIBFT) $(LIB)/$(LIBFT_A) \
	-lm  -g -o $(NAME)
	@echo "Done: $(NAME)"

mac:
	@gcc $(MAIN) $(MLX_MAC_FLAG) $(SRC) \
	-I $(LIB)/$(MLX_MAC) $(LIB)/$(MLX_MAC_A) \
	-I $(LIB)/$(LIBFT) $(LIB)/$(LIBFT_A) \
	-I $(SRC_DIR) \
	-lm -g -o $(NAME)
	@echo "Done: $(NAME)"


clean:
	@/bin/rm -f $(OBJ)
fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

src:
	@make -C src/ re --no-print-directory
	@make -C src/ clean --no-print-directory

libft:
	@(test -f $(LIB)/$(LIBFT_A)) || make -C $(LIB)/$(LIBFT) --no-print-directory

libclean:
	make -C $(LIB)/$(LIBFT) clean

libfclean:
	make -C $(LIB)/$(LIBFT) fclean

fullclean: clean libclean

fullfclean: fclean libfclean
