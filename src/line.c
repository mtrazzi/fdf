#include "fdf.h"

t_line	ft_line_init(int dx, int dy, int err)
{
	t_line	t;

	t.dx = dx;
	t.dy = dy;
	t.err = err;
	return (t);
}

void	ft_put_line(t_point p1, t_point p2, t_env *e)
{
	int		e2;
	t_line	t;
	int		x;
	int		y;

	t = ft_line_init(abs(p1.x - p2.x), abs(p1.y - p2.y), (t.dx > t.dy ? t.dx : -t.dy) / 2);
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		e->d = ft_change_pix(e->pix, p1.x, p1.y, e->d);
		e2 = t.err;
		if (e2 > -t.dx)
		{
			t.err -= t.dy;
			p1.x += (p1.x < p2.x ? 1 : -1);
		}
		if (e2 < t.dy)
		{
			t.err += t.dx;
			p1.y += (p1.y < p2.y ? 1 : -1);
		}
	}	
}
