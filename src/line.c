#include "fdf.h"

t_line	ft_put_line_init(int dx, int dy, int err)
{
	t_line	t;

	t.dx = dx;
	t.dy = dy;
	t.err = err;
	return (t);
}

void	ft_put_line(t_point p1, t_point p2)
{
}
