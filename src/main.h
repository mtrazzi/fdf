#ifndef MAIN_H
# define MAIN_H

# include <math.h>
# include "button_map.h"
# include "general.h"
# include "../lib/libft/libft.h"

typedef struct	s_root
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	char	*title;

	void	*imgpnt;
	char	*img;
	int 	img_x;
	int 	img_y;

	int 	pos;
}				t_root;


# include "./color/color.h"
# include "draw/draw.h"

#endif
