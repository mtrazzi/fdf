#include "fdf.h"

t_pix	ft_pixel_init(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	t_pix	p;

	p.a = a;
	p.r = r;
	p.g = g;
	p.b = b;
	return (p);
}
