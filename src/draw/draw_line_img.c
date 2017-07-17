#include <math.h>
#include "draw.h"
#include "../color/color.h"


void	draw_line_img(t_root *r, int Xo, int Yo, int  Xn, int Yn, t_color color)
{
	int		steps;
	int		x;
	int		y;
	float	Xincrement;
	float	Yincrement;

	steps = abs(Yn - Yo);
	if (abs(Xn - Xo) > abs(Yn - Yo))	// Get the number of steps to run the loop
   		steps = abs(Xn - Xo);
	x = Xo;
	y = Yo;
	Xincrement = (Xn - Xo) / (float) steps; // X or Y increment by this ration
	Yincrement = (Yn - Yo) / (float) steps;

	for(int v=0; v < steps; v++)
	{
	   x += (int) round(Xincrement);
	   y += (int) round(Yincrement);
	 ((t_color *) r->img)[x + (y * r->img_x)] = color ;
	}
}
