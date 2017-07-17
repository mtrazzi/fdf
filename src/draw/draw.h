#ifndef FDF_DRAW_H
# define FDF_DRAW_H

# include "../color/color.h"
# include "../main.h"



void	draw_line_pix(t_root *root, int Xo, int Yo, int  Xn, int Yn, int color);
void	draw_line_img(t_root *r, int Xo, int Yo, int  Xn, int Yn, t_color color);

#endif
