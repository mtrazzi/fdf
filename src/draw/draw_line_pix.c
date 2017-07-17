#include <math.h>
#include "draw.h"

void	draw_line_pix(t_root *root, int Xo, int Yo, int  Xn, int Yn, int color)
{
	int		steps;
	float	x = Xo;
	float	y = Yo;
	float	Xincrement;
	float	Yincrement;


	steps = abs(Yn - Yo);
	if (abs(Xn - Xo) > abs(Yn - Yo)) // Get the number of steps to run the loop
   		steps = abs(Xn - Xo);

	Xincrement = (Xn - Xo) / (float) steps;
	Yincrement = (Yn - Yo) / (float) steps;


	for(int v=0; v < steps; v++)
	{
	   x = x + Xincrement;
	   y = y + Yincrement;
	   mlx_pixel_put(root->mlx, root->win , round(x), round(y), color);
	}
}
