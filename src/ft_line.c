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
	int sum = 0;

	t = ft_line_init(abs(p1.x - p2.x), abs(p1.y - p2.y), \
abs(p1.x - p2.x) > abs(p1.y - p2.y) ? abs(p1.x - p2.x) : -abs(p1.y - p2.y));
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		e->d = ft_change_pix(*e, e->pix, p1.x, p1.y);
		e2 = t.err;
		if (e2 > -t.dx)
		{
			t.err -= t.dy;
			p1.x += (p1.x < p2.x ? 1 : -1);
		}
		if (p1.x == p2.x && p1.y == p2.y)
			break;
		if (e2 < t.dy)
		{
			t.err += t.dx;
			p1.y += (p1.y < p2.y ? 1 : -1);
		}
		sum++;
	}	
}

void	ft_process_pt(int x, int y, t_env *e)
{
	t_point	**coord;

	coord = e->coord;
	//printf("coord[%d][%d] : (%d, %d)\n", x, y, (coord[x][y]).x, (coord[x][y]).y);
	ft_put_line(coord[x][y], coord[x - 1][y], e);
	ft_put_line(coord[x][y], coord[x + 1][y], e);
	ft_put_line(coord[x][y], coord[x][y - 1], e);
	ft_put_line(coord[x][y], coord[x][y + 1], e);
}
