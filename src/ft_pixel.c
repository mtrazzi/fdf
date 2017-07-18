#include "fdf.h"

void	ft_put_pixel(t_point *s, int color)
{
	mlx_pixel_put(s->mlx, s->win, s->x, s->y, color);
}

t_pix	ft_pixel_init(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
	t_pix	p;

	p.a = a;
	p.r = r;
	p.g = g;
	p.b = b;
	return (p);
}
