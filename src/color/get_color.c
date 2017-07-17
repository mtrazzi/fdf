#include "color.h"

t_color		get_color(int r, int g, int b, int a)
{
	t_color		col;

	col.b = b;
	col.g = g;
	col.r = r;
	col.a = a;
	return (col);
}
