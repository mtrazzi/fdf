NAME = src.a

COLOR = color
DRAW  = draw

SRC  = 	get_color.c \
		draw_line_pix.c \
		draw_line_img.c


TOO := $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Werror -Wextra -Wall \
	$(COLOR)/get_color.c \
	$(DRAW)/draw_line_pix.c \
	$(DRAW)/draw_line_img.c
	@ar rc $(NAME) $(TOO)
	@ranlib $(NAME)

clean:
	@rm -f $(TOO)

fclean: clean
	@rm -f $(NAME)

re: fclean all
